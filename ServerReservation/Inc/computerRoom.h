//
// Created by zhixuan on 4/22/22.
//

#ifndef SERVERRESERVATION_COMPUTERROOM_H
#define SERVERRESERVATION_COMPUTERROOM_H


class computerRoom {
protected:
    int m_Id;
    int m_Capacity;
public:
    computerRoom(int id,int capacity);
    int getCapacity();
};


#endif //SERVERRESERVATION_COMPUTERROOM_H
