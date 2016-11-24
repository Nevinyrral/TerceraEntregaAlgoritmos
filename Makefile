all: lectura.cxx class.cxx Pagr.cxx subject.cxx student.cxx
	g++ lectura.cxx class.cxx Pagr.cxx subject.cxx student.cxx -pedantic -std=c++11 -g -o scheduler