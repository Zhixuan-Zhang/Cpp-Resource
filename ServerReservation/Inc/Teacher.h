//
// Created by zhixuan on 4/19/22.
//

#ifndef SERVER_RESERVATION_TEACHER_H
#define SERVER_RESERVATION_TEACHER_H
#include "Identity.h"

class Teacher:public  Identity{
protected:
    int m_Id;
public:
    Teacher();
    Teacher(int empId,std::string name,std::string pwd);
    void openMenu();
    void showSelf();
    void showAllOrder();
    void validOrder();
    friend class Administer;

    void TeacherMenu();
};


#endif //SERVER_RESERVATION_TEACHER_H
