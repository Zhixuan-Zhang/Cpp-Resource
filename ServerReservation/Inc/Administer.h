//
// Created by zhixuan on 4/19/22.
//

#ifndef SERVER_RESERVATION_ADMINISTER_H
#define SERVER_RESERVATION_ADMINISTER_H

#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "globalFile.h"
#include "computerRoom.h"

class Administer:public Identity {
private:
    std::vector<Student> vStu;
    std::vector<Teacher> vTea;
public:
    Administer();
    Administer(std::string name,std::string pwd);
    void openMenu();
    void addPerson();
    void showPerson();
    void showComputer();
    void cleanFile();
    void initVector();
    void initRoom();
    void managerMenu();
    bool chechRepeat(int id, int type);
    void showSelf();
};


#endif //SERVER_RESERVATION_ADMINISTER_H
