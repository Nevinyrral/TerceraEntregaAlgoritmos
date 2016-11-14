#ifndef STUDENT_H
#define STUDENT_H

#include <vector>

class Student {
    private:
        // Instance variables
        int id_student;
        int approved_credits;
        int available_credits;
        std :: vector<Subject> subjects;
    
    public:
        // Constructor
        Student (int id_student, int approved_credits, int available_credits);
        
        // Getters 
        int get_id_student ();
        int get_approved_credits ();
        int get_available_credits ();
        std :: vector<Subject> get_subjects ();
        
        // Setters
        void set_id_student (int id_student);
        void set_approved_credits (int approved_credits);
        void set_available_credits (int available_credits);
        void set_set_subjects (std :: vector<Subject> subjects);
}

#endif