#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <set>

class Class {
    private:
        // Instance variables
        int id_class;
        int start_time;
        int end_time;
        int capacity;
        std :: string teacher;
        int day;

    public:
        // Constructor
        Class (int id_class, int start_time, int end_time, int capacity, std :: string teacher);

        // Getters
        int get_id_class ();
        int get_start_time ();
        int get_end_time ();
        int get_capacity ();
        int get_day ();
        std :: string get_teacher ();

        // Setters
        void set_id_class (int id_class);
        void set_start_time (int start_time);
        void set_end_time (int end_time);
        void set_day (int day);
        void set_teacher (std :: string teacher);
    	  void set_capacity (int capacity);
};

#endif
