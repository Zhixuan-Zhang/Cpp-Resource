//
// Created by zhixuan on 4/17/22.
//

#ifndef SPEECHCOMPITATION_SPEECHMANAGER_H
#define SPEECHCOMPITATION_SPEECHMANAGER_H
#include <iostream>
#include <vector>
#include <map>
#include "Speaker.h"
#include <algorithm>
#include <random>
#include <deque>
#include <fstream>
class speechManager {
private:
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> vVictory;
    std::map<int, Speaker> m_Speaker;
    int m_Index;
    bool fileIsEmpty;
public:
    speechManager();
    ~speechManager();
    void initSpeech();
    static void showMenu() ;
    static void exitSystem();
    void createSpeaker();
    void showInfo();
    void startSpeech();

    void speechDraw();

    void speechContest();

    void saveRecord();

    void loadRecord();


    std::map<int,std::vector<std::string>> m_Record;

    void showRecord();

    void clearRecord();
};


#endif //SPEECHCOMPITATION_SPEECHMANAGER_H
