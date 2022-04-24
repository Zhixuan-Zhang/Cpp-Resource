//
// Created by zhixuan on 4/19/22.
//

#include "../Inc/Student.h"
#include "globalFile.h"

#include <utility>
#include <fstream>

Student::Student(){

}
Student::Student(int id,std::string name,std::string pwd){
    this->m_Id=id;
    this->m_Name=std::move(name);
    this->m_Pwd=std::move(pwd);
    std::ifstream ifs;
    ifs.open(COMPUTER_FILE,std::ios::in);
    int roomId;
    int roomCapacity;
    while(ifs>>roomId&& ifs>>roomCapacity){
        computerRoom C(roomId,roomCapacity);
        vCom.push_back(C);
    }
    ifs.close();
}


void Student::openMenu(){
    std::cout<<"Welcome"<<std::endl;
    std::cout<<"1. Apply reservation"<<std::endl;
    std::cout<<"2. Check my reservation"<<std::endl;
    std::cout<<"3. Check all reservation"<<std::endl;
    std::cout<<"4. cancel reservation"<<std::endl;
    std::cout<<"0. Logout"<<std::endl;
    std::cout<<"Choose your option"<<std::endl;
}

void Student::studentMenu(){
    openMenu();
    while(true){
        int select;
        std::cin>>select;
        if (select==1){
            applyOrder();
        }
        else if(select==2){
            showMyOrder();
        }
        else if(select==3){
            showAllOrder();
        }
        else if (select==4){
            cancelOrder();
        }
        else{
            return ;
        }
    }
}
void Student::applyOrder(){
    std::cout<<"1. Monday"<<std::endl;
    std::cout<<"2. Tuesday"<<std::endl;
    std::cout<<"3. Wednesday"<<std::endl;
    std::cout<<"4. Thursday"<<std::endl;
    std::cout<<"5. Friday"<<std::endl;
    int date;
    int interval;
    int room;
    while (true){
        std::cin>>date;
        if (date>=1 && date<=5) {
            break;
        }
        std::cout<<"Input Error"<<std::endl;
    }
    std::cout<<"1.Morning"<<std::endl;
    std::cout<<"2.Afternoon"<<std::endl;
    while (true){
        std::cin>>interval;
        if (interval==1 || interval==2) {
            break;
        }
        std::cout<<"Input Error"<<std::endl;
    }
    std::cout<<"Choose room"<<std::endl;
    std::cout<<"Room number one capacity: "<<vCom[0].getCapacity()<<std::endl;
    std::cout<<"Room number two capacity: "<<vCom[1].getCapacity()<<std::endl;
    std::cout<<"Room number three capacity: "<<vCom[2].getCapacity()<<std::endl;
    while (true){
        std::cin>>room;
        if (room>=1 && room<=3) {
            break;
        }
        std::cout<<"Input Error"<<std::endl;
    }
    std::cout<<"reserve success"<<std::endl;
    std::ofstream ofs(ORDER_FILE,std::ios::app);
    ofs<<"date:"<<date<<" ";
    ofs<<"interval:"<<interval<<" ";
    ofs<<"stuId:"<<this->m_Id<<" ";
    ofs<<"stuName:"<<this->m_Name<<" ";
    ofs<<"roomId:"<<room<<" ";
    ofs<<"status:"<<1<<" "<<std::endl;
    ofs.close();

}
void Student::showMyOrder(){
    OrderFile of;
    if(of.m_size==0){
        std::cout<<"No records found"<<std::endl;
        return;
    }
    std::ostream out(std::cout.rdbuf());
    for (int i=0;i<of.m_size;i++){
        if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())){
            of.showoneOrder(out,of.m_orderData[i]);
        }

    }
}
void Student::showAllOrder(){
    OrderFile F;
}
void Student::cancelOrder(){
    OrderFile of;
    if(of.m_size==0){
        std::cout<<"No records found"<<std::endl;
        return ;
    }
    std::vector<int> v;
    int index = 1;
    for (int i=0;i<of.m_size;i++){
        if(this->m_Id== atoi(of.m_orderData[i]["stuId"].c_str())){
            if (of.m_orderData[i]["status"]=="1"||of.m_orderData[i]["status"]=="2"){
                v.push_back(i);
            }
        }
    }
}

void Student::showSelf() {
    std::cout<<"ID: "<<this->m_Id<<" Name: "<<this->m_Name<<"Password: "<<this->m_Pwd<<std::endl;
}
