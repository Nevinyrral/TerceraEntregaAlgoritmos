#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>
#include "class.h"

class Subject {
    private:
        // Instance variables
        int id_subject;
        int credits; 
        std :: vector<Class> classes;
        
    public:
        // Constructor
        Subject (int id_subject, int credits);
    
        // Getters
        int get_id_subject ();
        int get_credits ();
        std :: vector<Class> get_classes ();
        
        // Setters
        void set_id_subject (int id);
        void set_credits (int credits);
        void set_classes (std :: vector<Class> classes);
}