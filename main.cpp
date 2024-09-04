#include <iostream>
#include <string>
#include "person.h"
#include "student.h"
#include "classes.h"

using namespace std;

int main(){
    
  string strInput;
  string strInput2;
  int intInput;
  int intInput2;
  int intInput3;
  
  classes classes[7];
  int totalClasses = 0;

  student students[30];
  int totalStudents = 0;
  
  teacher Teacher;
    
  cout << "Hello teacher, this is the Student Management System." << endl << endl;
  cout << "Please enter your name, email, and ID:" << endl;
  
  cin >> strInput;
  Teacher.setName(strInput);

  cin >> strInput;
  Teacher.setEmail(strInput);

  cin >> intInput;
  Teacher.setID(intInput);

  do{
  cout << endl << "what would you like to do?" << endl << "1 - Create a class" << endl << "2 - Create a student" << endl << "3 - Add a student to a class" << endl << "4 - Add an assignment/exam grade to a student" << endl << "5 - Calculate the grade average for a student" << endl << "6 - Set the attendance status for a student" << endl << "7 - Output the attendance report for a class" << endl << "8 - End program" << endl;
    cin >> intInput;
    
    // Creates classes
    if(intInput == 1){
      cout << "What do you want to call the class?" << endl;
      cin >> strInput;
      classes[totalClasses].setClass(strInput);
      classes[totalClasses].setTeacher(Teacher);
      totalClasses++;
      if (totalClasses < 2){
        cout << "You have created " << totalClasses << " class" << endl;
      }
      else{
        cout << "You have created " << totalClasses << " classes" << endl;
      }
    }
      
    // Creates students
    else if(intInput == 2){
      cout << "What is the name and ID of the student you want to create?" << endl;
      cin >> strInput;
      students[totalStudents].setName(strInput);
      cin >> intInput;
      students[totalStudents].setID(intInput);
      totalStudents++;
    }
      
    // Adds students to classes
    else if(intInput == 3){
      cout << "Which class are you adding a student to (0 is the first class you created and 6 is the last)?" << endl;
      cin >> intInput; // class
      cout << "Which student are you adding (0 is the first student you created, and 6 is the las)?" << endl;
      cin >> intInput2; // student 
      classes[intInput].updateStudentList(students[intInput2]);
      students[intInput2].updateSchedule(classes[intInput].getClass());
    }

    // Adds grades to students
    else if(intInput == 4){
      cout << "Which class are you adding a grade to (0 is the first class you created and 6 is the last)?" << endl;
      cin >> intInput; // class
      cout << "Which student are you adding an assignment/exam to? (0 is the first student and 6 is the last)" << endl;
      cin >> intInput2; // student
      cout << "What is the grade for this assignment?" << endl;
      cin >> intInput3; // grade
      strInput = classes[intInput].getClass(); // class name
      classes[intInput].studentList[intInput2].submitAssignment(intInput3,  strInput);  
      }

    // Computes averages
    else if(intInput == 5){
      cout << "Which class are you dealing with(0 is the first class you created and 6 is the last)?" << endl;
      cin >> intInput; // class
      cout << "Which student are you finding the average for? (0 is the first student and 6 is the last)" << endl;
      cin >> intInput2; // student
      strInput = classes[intInput].getClass(); // class name
      cout << classes[intInput].studentList[intInput2].getName() << "'s Average: " << classes[intInput].studentList[intInput2].calculateClassGrade(strInput);
    }

    // Sets attendance for students
    else if(intInput == 6){
      cout << "Which class are you setting attendance for (0 is the first class you created and 6 is the last)" << endl;
      cin >> intInput; // class
      cout << "Which student are you adding an attendance status to? (0 is the first student and 6 is the last)" << endl;
      cin >> intInput2; // student
      cout << "What is the status for this date (0 = present, 1 = absent, 2 = tardy)?" << endl;
      cin >> intInput3; // attend status
      strInput = classes[intInput].getClass(); // class name
      classes[intInput].studentList[intInput2].markAttendance(intInput3, strInput);
    }

    // Generates an attendance report for a class
    else if(intInput == 7){
      cout << "Which class attendance report do you want (0 is the first class you created and 6 is the last)" << endl;
      cin >> intInput; // class
    cout << "What is the range you want the report for (0 is the first day of class and 6 is the first day)" << endl;
      cin >> intInput2; // start date
      cin >> intInput3; // end date
      strInput = classes[intInput].getClass(); // class name
      for(int i = 0; i < classes[intInput].classSize; i++){
        cout << endl << classes[intInput].studentList[i].getName() << endl;
        classes[intInput].studentList[i].generateAttendanceReport(intInput2, intInput3, strInput);
      }
    }

  //ends program
  }while(intInput != 8);
  cout << "Exiting system";
  return 0; 
}
