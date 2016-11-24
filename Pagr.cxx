#include "Pagr.h"

Pagr::Pagr(){

}
Pagr::~Pagr(){

}
std::vector<Student>  Pagr::getEstTot(){
  return this-> estudiantes;
}
std::map<int, Subject>  Pagr::getMateriasTot(){
  return this-> materias;
}
void Pagr::setEstudiantes(std::vector<Student> es){
   this-> estudiantes = es;
}
void Pagr::setMaterias(std::map<int, Subject> mat){
  this-> materias = mat;
}
void Pagr::addEstPr(Student estudiante){
  std::cout << "Entre a agregar estudiante" << '\n';
  this-> estudiantes.push_back(estudiante);
}
void Pagr::addMat(Subject materia){

  this->materias.insert(std::pair<int,Subject>(materia.get_id_subject(),materia));
}
