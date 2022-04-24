//
// Created by zhixuan on 4/19/22.
//

#ifndef SERVER_RESERVATION_IDENTITY_H
#define SERVER_RESERVATION_IDENTITY_H

#include <string>
#include <utility>
#include <iostream>
#include <vector>

class Identity {
protected:
    std::string m_Name;
    std::string m_Pwd;
public:
    virtual void openMenu()=0;
    virtual void showSelf()=0;
    friend class Administer;
};


#endif //SERVER_RESERVATION_IDENTITY_H
