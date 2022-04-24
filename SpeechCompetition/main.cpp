

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Inc/speechManager.h"
// we assume all arguments are integers and we sum them up
// for simplicity we do not verify the type of arguments

int main(int argc, char *argv[]){
    srand((unsigned int)time(nullptr));
    speechManager sm;
    speechManager::showMenu();
    int choice = 0;
    while (true){
        std::cout << "Input your choice:" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                //sm.showInfo();
                sm.initSpeech();
                sm.createSpeaker();
                sm.startSpeech();
                sm.startSpeech();
                sm.saveRecord();
                break;
            case 2:
                sm.loadRecord();
                break;
            case 3:
                sm.clearRecord();
                break;
            case 0:
                speechManager::exitSystem();
                break;
            default:
                printf("\033[H\033[J");
                break;
        }

    }
    return 0;
}