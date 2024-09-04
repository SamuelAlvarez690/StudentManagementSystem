#include "student.h"

// creates the 2d pointer arrays and sets the classAttendance 
//and classAssignments to 0
student::student(){
    int studentID = 0;
    
    attendStatus = new int*[7];
        for (int i=0;i<7;i++){
            attendStatus[i] = new int[7];
        }  
  
    assignments = new int*[7];
        for (int i=0;i<7;i++){
            assignments[i] = new int[7];
        }

    for(int i = 0; i < 7; i++){
      classAttendance[i] = 0;
      classAssignments[i] = 0;
    }
  
    int subjects = 0;
}

//
void student::setID(int ID){
    studentID = ID;
    
}

// returns the student ID
int student::getID(){
    return studentID;
}

// updates the students schedule
void student::updateSchedule(string newSub){
    subjectsTaken[subjects] = newSub;
    subjects++;
}

// adds an attendance status to the student's attendStatus 2D array
void student::markAttendance(int status, string className){
  int studentClass = 0;
  for(int i = 0; i < subjects; i++){
    if(subjectsTaken[i] == className)
      studentClass = i;
  }
  cout << studentClass;
  attendStatus[studentClass][classAttendance[studentClass]] = status;
  classAttendance[studentClass]++;
}

// adds an assigment grade to the student's assignments 2D array
void student::submitAssignment(int grade, string className){
  int studentClass = 0;
  for(int i = 0; i < subjects; i++){
    if(subjectsTaken[i] == className)
      studentClass = i; 
  }
  assignments[studentClass][classAssignments[studentClass]] = grade;
  classAssignments[studentClass]++;

}

// computes an average for a student
float student::calculateClassGrade(string className){
  int average = 0;

  int studentClass = 0;
  for(int i = 0; i < subjects; i++){
    if(subjectsTaken[i] == className)
      studentClass = i;
  }
  for(int i = 0; i < 7; i++){
    average += assignments[studentClass][i];
  }
  return average/classAssignments[studentClass];
}

//generates the attendance report for a student
void student::generateAttendanceReport(int startDate, int endDate, string Class){
  int present = 0;
  int absent = 0;
  int tardy = 0;

  int studentClass = 0;
  for(int i = 0; i < subjects; i++){
    if(subjectsTaken[i] == Class)
      studentClass = i;
  }

  for(int i = startDate; i <= endDate; i++){
    if(attendStatus[studentClass][i] == 0){
      present++;
    }
    else if(attendStatus[studentClass][i] == 1){
      absent++;
    }
    if(attendStatus[studentClass][i] == 2){
      tardy++;
    }
  }
  cout << endl << "present: " << present << endl;
  cout << "absent: " << absent << endl;
  cout << "tardy: " << tardy << endl; 
}

// frees the memory
student::~student(){
delete [] attendStatus;
delete [] assignments;
}