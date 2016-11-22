#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <map>
#include "class.h"

class Subject {
    private:
        // Instance variables
        std :: string id_subject;
        int credits; 
        std :: map<int, Class> classes;
        
    public:
        // Constructor
        Subject (std :: string id_subject, int credits);
    
        // Getters
        std :: string get_id_subject ();
        int get_credits ();
        std :: map<int, Class> get_classes ();
        
        // Setters
        void set_id_subject (std :: string id);
        void set_credits (int credits);
        void set_classes (std :: map<int, Class> classes);
	void add_class (Class klass);
};

#endif
