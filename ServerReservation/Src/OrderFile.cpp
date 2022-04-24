//
// Created by zhixuan on 4/22/22.
//


#include "../Inc/OrderFile.h"
#include "globalFile.h"

OrderFile::OrderFile(){
    std::ifstream ifs;
    ifs.open(ORDER_FILE, std::ios::in);
    if(!ifs.is_open()){
        std::cout<<"read file failed"<<std::endl;
        return ;
    }
    std::string date;
    std::string interval;
    std::string stuId;
    std::string stuName;
    std::string roomId;
    std::string status;
    this->m_size=0;
    while(ifs>>date && ifs>>interval && ifs>>stuId && ifs>>stuName
            && ifs>>roomId && ifs>>status){
        std::string key;
        std::string value;
        std::map<std::string,std::string> m ;
        m.insert(decodeOrder(date));
        m.insert(decodeOrder(interval));
        m.insert(decodeOrder(stuId));
        m.insert(decodeOrder(stuName));
        m.insert(decodeOrder(roomId));
        m.insert(decodeOrder(status));
        m_orderData.insert(make_pair(this->m_size,m));
        m_size++;
    }
    ifs.close();
}

std::pair<std::string,std::string> OrderFile::decodeOrder(std::string OriginString){
    std::string key;
    std::string value;
    int pos = OriginString.find(':');
    if(pos!=-1){
        key = OriginString.substr(0,pos);
        std::cout<<key<<std::endl;
        value = OriginString.substr(pos+1, OriginString.size()-pos-1);
        return make_pair(key,value);
    }
}
void OrderFile::updateOrder(){
    if(this->m_size==0){
        return;
    }
    std::ofstream ofs(ORDER_FILE,std::ios::out|std::ios::trunc);
    for (int i=0;i<m_size;i++){
        showoneOrder(ofs, m_orderData[i] );
    }
    ofs.close();
}

void OrderFile::showoneOrder(std::ostream& out,std::map<std::string,std::string> m){
    out<<"date: "<<m["date"]<<" ";
    out<<"interval: "<<m["interval"]<<" ";
    out<<"stuId: "<<m["stuId"]<<" ";
    out<<"stuName: "<<m["stuName"]<<" ";
    out<<"roomId: "<<m["roomId"]<<" ";
    out<<"status: "<<m["status"]<<std::endl;
}