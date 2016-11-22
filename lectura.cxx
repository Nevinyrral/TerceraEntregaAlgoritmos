#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "class.h"
#include "subject.h"
#include "student.h"

using namespace std;

int main (int argc, char** argv) {
if (argc < 1) {
		std::cout << "File reader usage: reader input_file_name" << std::endl;
		return EXIT_FAILURE;	
	} else {
		std::fstream file_reader;
		std::vector<Subject> subjects;
    std::vector<Student> students;
		file_reader.open (argv[1], std::ios::in);
		if (!file_reader.is_open()) {
			std::cout << "The requested file doesn't exist!" << std::endl;		
			return EXIT_FAILURE;
		} else {
			int student_size, student_id, approved_credits, available_credits;
			file_reader >> student_size;
			std::string buffer;
			for (int i = 0; i < student_size + 1; i++) {
				std::vector<std::string> student_data;
				std::getline (file_reader, buffer);
				std::size_t previous = 0, position;
				std::string sub_buffer;
				while ((position = buffer.find_first_of (" ,", previous)) != std::string::npos) {
					if (position > previous) {
						sub_buffer = buffer.substr(previous, position - previous);
						student_data.push_back (sub_buffer);
					}
					previous = position + 1;
				}
				if (previous < buffer.length()) {		
					sub_buffer = buffer.substr(previous, std::string::npos);
					student_data.push_back (sub_buffer);
					student_id = std::atoi (student_data[0].c_str());
					approved_credits = std::atoi (student_data[1].c_str());
					available_credits = std::atoi (student_data[2].c_str());
					Student student = Student (student_id, approved_credits, available_credits); 
					for (int j = 4; j < student_data.size() - 1; ++j) {
						student.add_subject(student_data[j]);
					}
					students.push_back (student);
				}
			}
			std :: string idMat;
			int credMat, clasTot, matTot;
			file_reader >> matTot; 
			std::cout << matTot << std::endl;
      for (int i = 0; i < matTot; i++) {
          std::cout << "Entre a crear materias" << std::endl;
          file_reader >> idMat;
          file_reader >> credMat;
          Subject sb = Subject(idMat, credMat);
          file_reader >> clasTot;
          int idClass, ini, ends, dia, nCupos;
          std::string prof;
          std::cout << "clasTot" << clasTot << std::endl;
          for(int j = 0; j < clasTot; j++){
              std::cout << "Entre a crear clases" << '\n';
              file_reader >> idClass;
              file_reader >> ini;
              file_reader >> ends;
              file_reader >> dia;
              file_reader >> nCupos;
              file_reader >> prof;
              Class klass = Class (idClass, ini, ends, nCupos, prof);
              klass.add_day (dia);
              sb.add_class (klass);
          }
      }
			std::cout << "STOP!" << std::endl;		
		}		
		file_reader.close();
	}	 
}	
