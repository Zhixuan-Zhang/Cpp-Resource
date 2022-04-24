//
// Created by zhixuan on 4/19/22.
//

#ifndef SERVER_RESERVATION_STUDENT_H
#define SERVER_RESERVATION_STUDENT_H
#include "Identity.h"
#include "computerRoom.h"
#include "OrderFile.h"
class Student:public Identity{
protected:
    int m_Id;
    std::vector<computerRoom> vCom;
public:
    Student();
    Student(int id,std::string name,std::string pwd);
    void openMenu();
    void showSelf();
    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();
    friend class Administer;

    void studentMenu();
};


#endif //SERVER_RESERVATION_STUDENT_H
