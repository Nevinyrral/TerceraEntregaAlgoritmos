#include "subject.h"

// Constructor
Subject :: Subject (int id_subject, int credits) {
    set_id_subject (id_subject); 
    set_credits (credits);
}

// Setters
void Subject :: set_id_subject (int id_subject) {
    this -> id_subject = id_subject;     
}

void Subject :: set_credits (int credits) {
    this -> credits = credits;
}

void Subject :: set_classes (std :: map<int, Class> classes) {
    this -> classes = classes;
}

void Subject :: add_class (Class klass) {
    this -> classes.insert (std::pair<int, Class>(klass.get_id_class(), klass));
}

// Getters
int Subject :: get_id_subject () {
    return this -> id_subject;
}

int Subject :: get_credits () {
    return this -> credits; 
}

std :: map<int, Class> Subject :: get_classes () {
    return this -> classes; 
}


