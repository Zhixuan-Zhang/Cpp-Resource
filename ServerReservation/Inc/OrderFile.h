//
// Created by zhixuan on 4/22/22.
//

#ifndef SERVERRESERVATION_ORDERFILE_H
#define SERVERRESERVATION_ORDERFILE_H


#include <fstream>
#include <iostream>
#include <string>
#include <map>
class OrderFile {
public:
    OrderFile();
    void updateOrder();
    std::map<int,std::map<std::string,std::string>> m_orderData;
    int m_size;

    std::pair<std::string, std::string> decodeOrder(std::string);
    void showoneOrder(std::ostream& out,std::map<std::string, std::string> m);
};


#endif //SERVERRESERVATION_ORDERFILE_H
