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
						student.add_subject(std::atoi(student_data[j].c_str()));
					}
					students.push_back (student);
				}
			}
			int subject_size;
			file_reader >> subject_size; 
		    for (int i = 0; i < subject_size; i++) {
		    	int subject_credits, classes_by_subject, subject_id;
		    	vector<std::string> subject_data;
		    	file_reader >> buffer;
		    	std::size_t previous = 0, position;
		    	std::string sub_buffer;
		    	while ((position = buffer.find_first_of (",", previous)) != std::string::npos) {
					if (position > previous) {
						sub_buffer = buffer.substr(previous, position - previous);
						subject_data.push_back (sub_buffer);
					}
					previous = position + 1;
				}
				if (previous < buffer.length()) {
					sub_buffer = buffer.substr(previous, std::string::npos);
					subject_data.push_back (sub_buffer);
		    		subject_id = std::atoi (subject_data[0].c_str());
		    		subject_credits = std::atoi (subject_data[1].c_str());
				}
	    		Subject subject = Subject(subject_id, subject_credits);
	    		
				file_reader >> classes_by_subject;
		    	int class_id, start_time, end_time, day, seats;
		    	std::string teacher;
		    	for(int j = 0; j < classes_by_subject; j++){
		    		file_reader >> buffer;
		    		std::vector<string> class_data;
		    		previous = 0;
		    		while ((position = buffer.find_first_of (",", previous)) != std::string::npos) {
						if (position > previous) {
							sub_buffer = buffer.substr(previous, position - previous);
							class_data.push_back (sub_buffer);
						}
						previous = position + 1;
					}
					if (previous < buffer.length()) {
						sub_buffer = buffer.substr(previous, std::string::npos);
						class_data.push_back (sub_buffer);
		    			class_id = std::atoi (class_data[0].c_str());
		    			start_time = std::atoi (class_data[1].c_str());
		    			end_time = std::atoi (class_data[2].c_str());
		    			day = std::atoi (class_data[3].c_str());
		    			seats = std::atoi (class_data[4].c_str());
		    			teacher = class_data[5];
		    			Class klass = Class (class_id, start_time, end_time, seats, teacher);
		    			klass.add_day(day);
		    			subject.add_class (klass);
					}
		    	}
		    	subjects.push_back (subject);
		    }
		}		
		file_reader.close();
	}	 
}	
