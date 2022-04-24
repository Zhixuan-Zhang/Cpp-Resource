//
// Created by zhixuan on 4/16/22.
//
#include "../Inc/Speaker.h"
#include <vector>

std::string Speaker::getName() const{
    return Name;
}
void Speaker::setName(std::string name){
    this->Name = name;
}
void Speaker::setScore(float S,int times){
    (this->score)[times] = S;
}
double Speaker::getScore(int times) const{
    return (this->score)[times];
}
void Speaker::ShowInfo() const{
    std::cout << Name << score[0] <<std::endl;
}
