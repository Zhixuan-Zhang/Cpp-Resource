//
// Created by zhixuan on 4/16/22.
//

#include <vector>
#include <iostream>

class Speaker{
private:
    std::string Name;
    double score[2];
public:
    std::string getName() const;
    void setName(std::string name);
    void setScore(float S, int times);

    void ShowInfo() const;

    double getScore(int times) const;
};