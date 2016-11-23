#include <string>
#include "class.h"


// Constructor
Class :: Class (int id_class, int start_time, int end_time, int capacity, std :: string teacher) {
    set_id_class (id_class);
    set_start_time (start_time);
    set_end_time (end_time);
    set_capacity (capacity);
    set_teacher (teacher);
}

// Setters
void Class :: set_id_class (int id_class) {
  this -> id_class = id_class;
}

void Class :: set_start_time (int start_time) {
  this -> start_time = start_time;
}

void Class :: set_end_time (int end_time) {
  this -> end_time = end_time;
}

void Class :: set_days (std :: set<int> days) {
  this -> days = days;
}

void Class :: set_teacher (std :: string teacher) {
  this -> teacher = teacher;
}

void Class :: set_capacity (int capacity) {
  this -> capacity = capacity;
}

void Class :: add_day (int day) {
	this -> days.insert(day);
}

// Getters
int Class :: get_id_class () {
  return this -> id_class;
}

int Class :: get_start_time () {
  return this -> start_time;
}

int Class :: get_end_time () {
  return this -> end_time;
}

int Class :: get_capacity () {
  return this -> capacity;
}

std :: set<int> Class :: get_days () {
  return this -> days;
}

std :: string Class :: get_teacher () {
  return this -> teacher;
}
