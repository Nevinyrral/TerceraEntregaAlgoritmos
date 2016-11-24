#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include "subject.h"

class Student {
    private:
        // Instance variables
        int id_student;
        int approved_credits;
        int available_credits;
        std :: vector<int> subjects;
        std::vector<int> codClasesIns;

    public:
        // Constructor
        Student (int id_student, int approved_credits, int available_credits);

        // Getters
        int get_id_student ();
        int get_approved_credits ();
        int get_available_credits ();
        std :: vector<int> get_subjects ();
        std::vector<int> getClasesIns();

        // Setters
        void set_id_student (int id_student);
        void set_approved_credits (int approved_credits);
        void set_available_credits (int available_credits);
        void set_subjects (std :: vector<int> subjects);
	    void add_subject (int subject_id);
      void setClasesIns(std::vector<int> v);
};

#endif
