#pragma once
#import <iostream>
#import <string>

#import "student.h"
#import "teacher.h"

using namespace std;

class classes {
public:
  classes();
  void setClass(string name);
  string getClass();
  void setTeacher(teacher &teacher);
  void updateStudentList(student &student);
  ~classes();
  student *studentList;
  int classSize;
private:
  string className;
  teacher teach;
  
  int classID;
};