//
// Created by zhixuan on 4/22/22.
//

#include "../Inc/computerRoom.h"

computerRoom::computerRoom(int id, int capacity) {
    this->m_Id = id;
    this->m_Capacity = capacity;
}

int computerRoom::getCapacity() {
    return m_Capacity;
}
