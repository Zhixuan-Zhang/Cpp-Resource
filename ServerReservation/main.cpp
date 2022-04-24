//
// Created by zhixuan on 4/19/22.
//


#include <iostream>

#include "Inc/BackupFunc.h"
int main(int argc, char *argv[]){

    int choice;
    while (1){
        BackupFunc::menu();
        std::cin>>choice;
        switch(choice){
            case 1:
                BackupFunc::Login("student.txt", 1);
                break;
            case 2:
                BackupFunc::Login("teacher.txt", 2);
                break;
            case 3:
                BackupFunc::Login("admin.txt", 3);
                break;
            case 0:
                goto end;
            default:
                BackupFunc::menu();
                std::cout<<"Error input"<<std::endl;
                break;
        }
    }
    end:
    std::cout<<"Exit system"<<std::endl;
    return EXIT_SUCCESS;
}