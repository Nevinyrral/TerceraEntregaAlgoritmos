#include "subject.h"

// Constructor
Subject :: Subject (int id_subject, int credits) {
    set_id_subject (id_subject); 
    set_credits (credits);
    set_classes (std :: set<int> classes);
}

// Setters
void Subject :: set_id_subject (int id_subject) {
    this -> id_subject = id_subject;     
}

void Subject :: set_credits (int credits) {
    this -> credits = credits;
}

void Subject :: set_classes (std :: set<int> classes) {
    this -> classes = classes;
}

// Getters
int Subject :: get_id_subject () {
    return this -> id_subject;
}

int Subject :: get_credits () {
    return this -> credits; 
}

std :: vector<Class> Subject :: get_classes () {
    return this -> classes; 
}