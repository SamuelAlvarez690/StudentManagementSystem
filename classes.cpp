#import "classes.h"

// creates the student list
classes::classes() {
  studentList = new student[10];
  classSize = 0;
}

// sets the class name
void classes::setClass(string name) { 
  className = name; 
}

//returns the class name
string classes::getClass() {
  return className; 
}

// sets the teacher
void classes::setTeacher(teacher &t) { 
  teach = t; 
}

//adds a student to the student list
void classes::updateStudentList(student &student) {
  studentList[classSize] = student;
  classSize ++;
}

// frees the memory
classes::~classes(){
  delete [] studentList;
}