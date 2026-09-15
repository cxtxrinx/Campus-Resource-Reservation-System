#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include <queue>
#include <string>

using namespace std;

// Manages studnets waiting for campus resources

class WaitingList {
private:
    queue<string> students;

public:
    void addStudent(string studentID);
    void removeStudent();
    void displayWaitingList() const;
};

#endif // WAITING_LIST_H  

