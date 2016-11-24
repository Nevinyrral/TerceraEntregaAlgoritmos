#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include "class.h"
#include "Pagr.h"

using namespace std;

typedef std :: vector< std::set<int> > Schedule;

bool student_comparator (Student student_a, Student student_b);
void scheduler (Pagr *pr);
int archivoEntrada(int argc, Pagr *pr,char** argv);
void archivoSalida(Pagr *pr);
void imprimir(Pagr *pr);

// Try to find better solutions using multiple iterations
const int PASSES = 1;

int main (int argc, char** argv) {
	Pagr *pr = new Pagr();
	int a;
	a = archivoEntrada(argc,pr,argv);
	if (a == 0) {
		scheduler(pr);
		imprimir(pr);
		archivoSalida(pr);
	} else {
		return a;
	}
}//FIN MAIN

void scheduler (Pagr *pr) {
	std::vector<Student> aux = pr->getEstTot();
	std::map<int,Subject> auxSub = pr -> getMateriasTot();
	for(int k =0; k<aux.size();k++){
		std :: set<int> day;
		Schedule schedule (7, day);
		std :: vector<int> student_subjects = aux[k].get_subjects();
		int class_counter = 0;
		int current_credits = aux[k].get_available_credits();
		std :: vector<int> results;
		for (int i = 0; i < PASSES; i++) {
			while (student_subjects.size() > 0) {
				// Choose random subject
				int rm = student_subjects.size();
				int random_subject = rand() % rm + 0;
				int subject_id = student_subjects[random_subject];
				Subject sub = auxSub.find(subject_id) -> second;
				if (current_credits - sub.get_credits() >= 0) {
					std::map<int,Class> auxClas = sub.get_classes();
					std::map<int,Class>::iterator itC = auxClas.begin();
					bool class_added = false;
					while (itC != auxClas.end() && !class_added){
						bool valid_class = true;
						std::set<int> hours = schedule[itC -> second.get_day()];
						std::set<int> new_schedule_for_day = schedule[itC -> second.get_day()];
						int start_aux_time = itC -> second.get_start_time();
						int end_aux_time = itC -> second.get_end_time();
						if (valid_class && hours.find(start_aux_time) == hours.end() && hours.find(end_aux_time) == hours.end() && itC -> second.get_capacity() > 0) {
							new_schedule_for_day.insert(start_aux_time);
							new_schedule_for_day.insert(end_aux_time);
							for (int j = start_aux_time + 1; j < end_aux_time; j++) {
								if (hours.find(j) != hours.end()) {
									valid_class = false;
									class_added = true;
								} else {
									new_schedule_for_day.insert(j);
								}
							}
							if(valid_class) {
								results.push_back (itC -> second.get_id_class());
								schedule[itC -> second.get_day()] = new_schedule_for_day;
								auxSub.find(subject_id) -> second.get_classes().find(itC -> second.get_id_class()) -> second.set_capacity(itC -> second.get_capacity() - 1);
								current_credits -= sub.get_credits();
								class_added = true;
							}
						}
						itC++;
					}
				} 
				std::vector<int> aux_subjects;
				for(int w = 0; w < student_subjects.size(); w++){
					if(w != random_subject){
						aux_subjects.push_back(student_subjects[w]);
					}
				}
				student_subjects = aux_subjects;
			}
		}
		aux[k].setClasesIns(results);
	}
	pr->setEstudiantes(aux);
}

int archivoEntrada(int argc , Pagr *pr,char** argv){

	if (argc < 1) {
		std :: cout << "File reader usage: scheduler input_file_name" << std :: endl;
		return EXIT_FAILURE;
	} else {
		std :: fstream file_reader;
		std :: map<int,Subject> subjects;
		std :: vector<Student> students;
		file_reader.open (argv[1], std::ios::in);
		if (!file_reader.is_open()) {
			std :: cout << "The requested file doesn't exist!" << std :: endl;
			return EXIT_FAILURE;
		} else {
			int student_size, student_id, approved_credits, available_credits;
			file_reader >> student_size;
			std::string buffer;
			for (int i = 0; i < student_size + 1; i++) {
				std::vector<std :: string> student_data;
				std::getline (file_reader, buffer);
				std::size_t previous = 0, position;
				std::string sub_buffer;
				while ((position = buffer.find_first_of (" ,", previous)) != std :: string :: npos) {
					if (position > previous) {
						sub_buffer = buffer.substr(previous, position - previous);
						student_data.push_back (sub_buffer);
					}
					previous = position + 1;
				}
				if (previous < buffer.length()) {
					sub_buffer = buffer.substr(previous, std :: string :: npos);
					student_data.push_back (sub_buffer);
					student_id = std :: atoi (student_data[0].c_str());
					approved_credits = std :: atoi (student_data[1].c_str());
					available_credits = std :: atoi (student_data[2].c_str());
					Student student = Student (student_id, approved_credits, available_credits);
					for (int j = 4; j < student_data.size() - 1; ++j) {
						student.add_subject(std::atoi(student_data[j].c_str()));
					}
					students.push_back (student);
				}
			}
			int subject_size;
			file_reader >> subject_size;
			for (int i = 0; i < subject_size; i++) {
				int subject_credits, classes_by_subject, subject_id;
				vector<std :: string> subject_data;
				file_reader >> buffer;
				std :: size_t previous = 0, position;
				std :: string sub_buffer;
				while ((position = buffer.find_first_of (",", previous)) != std :: string :: npos) {
					if (position > previous) {
						sub_buffer = buffer.substr(previous, position - previous);
						subject_data.push_back (sub_buffer);
					}
					previous = position + 1;
				}
				if (previous < buffer.length()) {
					sub_buffer = buffer.substr(previous, std :: string :: npos);
					subject_data.push_back (sub_buffer);
					subject_id = std :: atoi (subject_data[0].c_str());
					subject_credits = std :: atoi (subject_data[1].c_str());
				}
				Subject subject = Subject(subject_id, subject_credits);

				file_reader >> classes_by_subject;
				int class_id, start_time, end_time, day, seats;
				std::string teacher;
				for(int j = 0; j < classes_by_subject; j++){
					file_reader >> buffer;
					std::vector<string> class_data;
					previous = 0;
					while ((position = buffer.find_first_of (",", previous)) != std :: string :: npos) {
						if (position > previous) {
							sub_buffer = buffer.substr(previous, position - previous);
							class_data.push_back (sub_buffer);
						}
						previous = position + 1;
					}
					if (previous < buffer.length()) {
						sub_buffer = buffer.substr(previous, std :: string :: npos);
						class_data.push_back (sub_buffer);
						class_id = std :: atoi (class_data[0].c_str());
						start_time = std :: atoi (class_data[1].c_str())/100;
						end_time = std :: atoi (class_data[2].c_str())/100;
						day = std :: atoi (class_data[3].c_str());
						seats = std :: atoi (class_data[4].c_str());
						teacher = class_data[5];
						Class klass = Class (class_id, start_time, end_time, seats, teacher);
						klass.set_day (day);
						subject.add_class (klass);
					}
				}
				subjects.insert (std :: pair<int, Subject> (subject_id, subject));
			}
		}
		file_reader.close();
		sort(students.begin(), students.end(), student_comparator);
		pr-> setEstudiantes(students);
		pr-> setMaterias(subjects);
	}
	return EXIT_SUCCESS;
}
bool student_comparator (Student student_a, Student student_b) {
	return  (student_a.get_approved_credits() > student_b.get_approved_credits());
}

void archivoSalida(Pagr *pr){
	std::fstream guardarArch;
	guardarArch.open("archivoSalida.txt",std::ios::out);
	if(!guardarArch.is_open()){

	}else{
     std::vector<Student> v = pr->getEstTot();
		 for(int i =0;i<v.size();i++){
			guardarArch << v[i].get_id_student();
			std::vector<int> clases = v[i].getClasesIns();
			guardarArch <<"," << clases.size()<<",";
			for(int j=0;j<clases.size();j++){
				guardarArch << clases[j]<< " ";
			}
			guardarArch << std::endl;
		 }
		guardarArch.close();
	}
}
void imprimir(Pagr *pr){
	std::cout << pr->getEstTot().size()<< '\n';
	std::vector<Student> v = pr->getEstTot();
	for(int i =0; i<v.size();i++ ){
		std::vector<Subject> x;
		std::cout << "Id estdiante: " << v[i].get_id_student()<<'\n';
		for(int j=0; j<x.size();j++){
			std::cout << "id materia: " << x[j].get_id_subject() <<'\n';
		}
		std::vector<int> z = v[i].getClasesIns();
		for(int k=0; k<z.size();k++){
				std::cout << "codigo de clases: " << z[k]<<'\n';
		}
	}
}
