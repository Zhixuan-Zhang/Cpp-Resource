//
// Created by zhixuan on 4/19/22.
//

#include <fstream>
#include "../Inc/BackupFunc.h"


void BackupFunc::menu(){
    std::cout<<"1. Student"<<std::endl;
    std::cout<<"2. Teacher"<<std::endl;
    std::cout<<"3. Administer"<<std::endl;
    std::cout<<"0. Quit"<<std::endl;
}

void BackupFunc::Login(std::string fileName, int type) {
    std::ifstream ifs;
    ifs.open(fileName,std::ios::in);
    if (!ifs.is_open()){
        std::cout<<"File not found: "<<std::endl;
        ifs.close();
        return ;
    }

    int id = 0;
    std::string name;
    std::string pwd;
    if (type==1){
        std::cout<<"input your id"<<std::endl;
        std::cin>>id;
    }
    else if (type==2){
        std::cout<<"input your id"<<std::endl;
        std::cin>>id;
    }
    std::cout<<"UserName?"<<std::endl;
    std::cin>>name;
    std::cout<<"Password?"<<std::endl;
    std::cin>>pwd;

    if (type==1){
        int fId;
        std::string fName;
        std::string fPwd;
        while(ifs>>fId && ifs>>fName && ifs>>fPwd){
            if(id==fId && fName==name && fPwd==pwd){
                std::cout<<"Login successful"<<std::endl;
                auto person = new Student(id,name,pwd);
                person->studentMenu();
                return ;
            }
        }
    }
    else if (type==2){
        int fId;
        std::string fName;
        std::string fPwd;
        while(ifs>>fId && ifs>>fName && ifs>>fPwd){
            if(id==fId && fName==name && fPwd==pwd){
                std::cout<<"Login successful"<<std::endl;
                auto person = new Teacher(id,name,pwd);
                person->TeacherMenu();
                delete person;
                return ;
            }
        }
    }
    else if(type ==3){
        std::string fName;
        std::string fPwd;
        while(ifs>>fName && ifs>>fPwd){
            if(fName==name && fPwd==pwd){
                std::cout<<"Login successful"<<std::endl;
                auto person = new Administer(name,pwd);
                person->managerMenu();
                return ;
            }
        }
    }
    std::cout<<"Login Failed"<<std::endl;
}
