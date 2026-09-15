#include "../include/WaitingList.h"
#include <iostream>

using namespace std;

void WaitingList::addStudent(string studentID){
    students.push(studentID); 
}

void WaitingList::removeStudent(){
    if (students.empty()) {
        cout << "Waiting list is empty." <<endl;
        return;
    }

    cout << "Removing Student: " << students.front() <<endl;
    students.pop();
}
void WaitingList::displayWaitingList() const {
    if (students.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    cout << "--- Waiting List ---" << endl;

    queue<string> temp = students;

    while (!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }
}