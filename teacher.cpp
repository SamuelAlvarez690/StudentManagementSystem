#import "teacher.h"

// sets the variables to 0
teacher::teacher(){
    teacherID = 0;
    numSubjects = 0;
    
}

// sets the teacher ID
void teacher::setID(int ID){
    teacherID = ID;
    
}

//returns the teacher ID
int teacher::getID(){
    return teacherID;
    
}

// updates the subjects in the subjectsTaught
void teacher::updateSubjects(string newSub){
    subjectsTaught[numSubjects];
    numSubjects++;
}