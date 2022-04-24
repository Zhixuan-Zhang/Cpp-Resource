//
// Created by zhixuan on 4/19/22.
//

#include "../Inc/Teacher.h"

#include <utility>
Teacher::Teacher(){

}
Teacher::Teacher(int empId,std::string name,std::string pwd){
    this->m_Id=empId;
    this->m_Name=std::move(name);
    this->m_Pwd=std::move(pwd);
}
void Teacher::openMenu(){
    std::cout<<"Welcome"<<std::endl;
    std::cout<<"1. Check all reservation"<<std::endl;
    std::cout<<"2. Audit reservation"<<std::endl;
    std::cout<<"0. Logout"<<std::endl;
    std::cout<<"Choose your option"<<std::endl;
}
void Teacher::TeacherMenu(){
    openMenu();
    int select;
    while(1){
        std::cin>>select;
        if (select == 1){
            showAllOrder();
        }
        else if (select == 2){
            validOrder();
        }
        else{
            return ;
        }
    }
}
void Teacher::showAllOrder(){

}
void Teacher::validOrder(){

}

void Teacher::showSelf(){
    std::cout<<"ID: "<<this->m_Id<<" Name: "<<this->m_Name<<"Password: "<<this->m_Pwd<<std::endl;
}
