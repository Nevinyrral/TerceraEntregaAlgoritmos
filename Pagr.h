#ifndef PRINCIPAL__H__
#define PRINCIPAL__H__

#include<iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include "student.h"
#include "subject.h"
#include <vector>

class Pagr{

 private:
    std::vector<Student> estudiantes;
	  std::map<int, Subject> materias;

 public:
	  Pagr();
		virtual ~Pagr();
		void setEstudiantes(std::vector<Student> es);
		void setMaterias(std::map<int, Subject>);
		std::vector<Student> getEstTot();
		std::map<int, Subject> getMateriasTot();
    void addEstPr(Student estudiante);
    void addMat(Subject materia);

};//fin de clase

#endif
