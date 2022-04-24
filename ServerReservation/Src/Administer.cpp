//
// Created by zhixuan on 4/19/22.
//

#include <fstream>
#include "../Inc/Administer.h"



Administer::Administer(){

}
Administer::Administer(std::string name,std::string pwd){
    this->m_Name = std::move(name);
    this->m_Pwd = std::move(pwd);
    this->initVector();


}
void Administer::openMenu(){
    std::cout<<"Welcome"<<std::endl;
    std::cout<<"1. Add user"<<std::endl;
    std::cout<<"2. Check user"<<std::endl;
    std::cout<<"3. Check rooms"<<std::endl;
    std::cout<<"4. Clean reservation"<<std::endl;
    std::cout<<"0. Logout"<<std::endl;
    std::cout<<"Choose your option"<<std::endl;
}
void Administer::addPerson(){
    std::cout<<"1. Add student"<<std::endl;
    std::cout<<"2. Add teacher"<<std::endl;
    std::string fileName;
    std::string tip;
    std::string Errortip;
    std::ofstream ofs;
    int select;
    std::cin>>select;
    fileName = select==1?STUDENT_FILE:TEACHER_FILE;
    tip = select==1?"Input the student ID":"Input the teacher ID";
    Errortip = select==1?"Student Id repeat":"Teacher Id repeat";
    ofs.open(fileName,std::ios::out | std::ios::app);
    int id;
    std::string name;
    std::string pwd;
    std::cout<<tip<<std::endl;

    while (true){
        std::cin>>id;
        bool ret = this->chechRepeat(id,select);
        if (ret){
            std::cout<<Errortip<<std::endl;
        }
        else{
            break;
        }
    }
    std::cout<<"Name"<<std::endl;
    std::cin>>name;
    std::cout<<"Password"<<std::endl;
    std::cin>>pwd;
    ofs<<id<<" "<<name<<" "<<pwd<<" "<<std::endl;
    ofs.close();
    std::cout<<"Add successful"<<std::endl;
    this->initVector();
}
void Administer::showPerson(){
    std::cout<<"1. Show all student"<<std::endl;
    std::cout<<"2. Show all Teacher"<<std::endl;
    int select=0;
    std::cin>>select;
    if (select==1){
        std::cout<<"Student info"<<std::endl;
        for(auto it:vStu){
            it.showSelf();
        }
    }
    else{
        std::cout<<"Teacher info"<<std::endl;
        for(auto it:vTea){
            it.showSelf();
        }
    }
}
void Administer::showComputer(){
    initRoom();
}
void Administer::cleanFile(){
    std::ofstream ofs(ORDER_FILE,std::ios::trunc);
    ofs.close();
    std::cout<<"Cleaned"<<std::endl;

}
void Administer::managerMenu(){
    openMenu();
    int select;
    while(true){
        std::cin>>select;
        if (select==1){
            std::cout<<"Add person"<<std::endl;
            addPerson();
        }
        else if (select ==2){
            std::cout<<"Check account"<<std::endl;
            showPerson();
        }
        else if (select==3){
            std::cout<<"Check rooms"<<std::endl;
            showComputer();
        }
        else if (select==4){
            std::cout<<"clear reservation"<<std::endl;
            cleanFile();
        }
        else if (select==0){
            std::cout<<"Logout successful"<<std::endl;
            return ;
        }
        else{
            std::cout<<"Input error"<<std::endl;
        }
    }
}



void Administer::initVector() {
    std::ifstream ifs;
    ifs.open(STUDENT_FILE,std::ios::in);
    if (!ifs.is_open()) {
        std::cout<<"Error opening file"<<std::endl;
        return ;
    }
    vStu.clear();
    vTea.clear();

    int id;
    std::string name;
    std::string pwd;
    while(ifs>>id && ifs>>name && ifs>>pwd){
        Student s(id,name,pwd);
        vStu.push_back(s);
    }
    std::cout<<"Number of student"<<vStu.size()<<std::endl;
    ifs.close();

    ifs.open(TEACHER_FILE,std::ios::in);
    if (!ifs.is_open()) {
        std::cout<<"Error opening file"<<std::endl;
        return ;
    }
    while(ifs>>id && ifs>>name && ifs>>pwd){
        Teacher t(id,name,pwd);
        vTea.push_back(t);
    }
    std::cout<<"Number of teacher"<<vTea.size()<<std::endl;
    ifs.close();

}

bool Administer::chechRepeat(int id, int type) {
    if (type==1){
        for (const auto& it:vStu){
            if (id==it.m_Id){
                return true;
            }
        }
    }
    else{
        for (const auto& it:vTea){
            if (id==it.m_Id){
                return true;
            }
        }
    }
    return false;
}

void Administer::showSelf() {

}

void Administer::initRoom() {
    std::ifstream ifs;
    std::vector<computerRoom> vCom;
    int id;
    int capacity;
    ifs.open(COMPUTER_FILE);
    if (!ifs.is_open()) {
        std::cout<<"Open file failed."<<std::endl;
        return ;
    }
    while(ifs>>id && ifs>>capacity){
        computerRoom C(id,capacity);
        vCom.push_back(C);
    }
    std::cout<<"Number of computer room is "<<vCom.size()<<std::endl;
    ifs.close();

}
