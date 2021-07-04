//
// Created by games on 7/4/2021.
//

#include "Logger.h"
#include <iostream>
#include <fstream>
Observer::~Observer() {

}

void TraverseLogger::onNotify(std::string detail, Events e) {
    if(e == Events::TRAVERSE){
        detail = "traversal: "+ detail;
        std::cout << detail << std::endl;
        traverseLog.push_back(detail);
    }
}

void TraverseLogger::writeToFile() {
    std::ofstream traverseLoger;
    traverseLoger.open("traverse.txt");
    for(const std::string& d:traverseLog){
        traverseLoger << d << std::endl;
    }
    traverseLoger.close();
}


void FightLogger::onNotify(std::string detail, Events e) {
    if(e == Events::FIGHT){
        detail = "fight: "+ detail;
        std::cout << detail << std::endl;
        fightlog.push_back(detail);
    }
}


void FightLogger::writeToFile() {

    std::ofstream fightlogger;
    fightlogger.open("fight.txt");
    for(const std::string& d:fightlog){
        fightlogger << d << std::endl;
    }
    fightlogger.close();
}
