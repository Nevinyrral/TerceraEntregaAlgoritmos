#include "class.h"

// Constructor
Class :: Class (int id_class, int start_time, int capacity, std :: string teacher) {
    set_id_class (id_class);
    set_start_time (start_time);
    set_end_time (end_time);
    set_capacity (capacity);
    set_days(std :: set<int> days);
    set_teacher(teacher);
}

// Setters
void set_id_class (int id_class) {
    this -> id_class = id;
}

void set_start_time (int start_time) {
    this -> start_time = start_time;
}

void set_end_time (int end_time) {
    this -> end_time = end_time;
}

void set_days (std :: set<int> days) {
    this -> days = days;
}

void set_teacher (std :: string teacher) {
    this -> teacher = teacher;
}

// Getters
int get_id_class () {
    return this -> id_class;
}

int get_start_time () {
    return this -> start_time;
}

int get_end_time () {
    return this -> end_time;
}

int get_capacity () {
    return this -> capacity;
}

std :: set<int> get_days () {
    return this -> days;
}

std :: string get_teacher () {
    return this -> teacher;
}