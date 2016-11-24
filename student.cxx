#include "student.h"

Student::Student(int id_student, int approved_credits, int available_credits) {
	this-> id_student = id_student;
 	this-> approved_credits = approved_credits;
 	this-> available_credits = available_credits;
}

// Getters
int Student::get_id_student (){
	return this -> id_student;
}
int Student::get_approved_credits (){
	return this -> approved_credits;
}
int Student::get_available_credits (){
	return this -> available_credits;
}
std::vector<int> Student::get_subjects (){
	return this -> subjects;
}
std::vector<int> Student::getClasesIns(){
	return this-> codClasesIns;
}

// Setters
void Student::set_id_student (int id_student){
	this -> id_student = id_student;
}
void Student::set_approved_credits (int approved_credits){
	this -> approved_credits = approved_credits;
}
void Student::set_available_credits (int available_credits){
	this -> available_credits = available_credits;
}
void Student::set_subjects(std::vector<int> subjects){
	this -> subjects = subjects;
}
void Student::add_subject(int sub){
	this -> subjects.push_back(sub);
}
void Student::setClasesIns(std::vector<int> v){
	 this-> codClasesIns = v;
}
