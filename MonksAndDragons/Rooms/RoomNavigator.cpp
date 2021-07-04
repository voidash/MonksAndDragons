//
// Created by games on 7/4/2021.
//

#include <SettingsSingleton.h>
#include <TUI/MiscComponents.h>
#include "RoomNavigator.h"
#include "SubjectInstance.h"

#include <iostream>
using namespace std;

RoomNavigator::RoomNavigator(MovingEntity *entity, Level *l,bool testing) : e(entity), l(l), testing(testing) {

    printAsciiRooms();
    l->start->log(SubjectInstance::subject);
    if(!testing)
        l->start->roomSpeciality(*e);

}

void RoomNavigator::printAsciiRooms(){
    RoomType ros =  l->start->roomType;
    if(SettingsSingleton::getInstance().settings.title == Title::ASCII){
        switch(ros){
            case EMPTY:
            {
                cout << TUIComponent::EmptyRoom << endl;
                break;
            }
            case TREASURE:
            {
                cout << TUIComponent::TreasureRoom << endl;
                break;
            }
            case MONSTER: {
                cout << TUIComponent::MonsterRoom << endl;
                break;
            }
            case NULLROOM:
                break;
        }
    }
}

bool RoomNavigator::getNextRoom() {
    if(l->start->next != nullptr) {
       l->start = l->start->next;

       l->start->log(SubjectInstance::subject);
       printAsciiRooms();
       if(!testing)
           l->start->roomSpeciality(*e);


       return true;
   }
   return false;
}

bool RoomNavigator::getPreviousRoom() {
    if(l->start->previous != nullptr) {
        l->start = l->start->previous;
        l->start->log(SubjectInstance::subject);
        printAsciiRooms();
        if(!testing)
            l->start->roomSpeciality(*e);
        return true;
    }
    return false;
}

std::array<RoomType, 2> RoomNavigator::getPreviousAndNextRooms() {
    std::array<RoomType,2> tpl{RoomType::NULLROOM};
    if(l->start->previous != nullptr) tpl[0] = l->start->previous->roomType;
    if(l->start->next != nullptr) tpl[1] = l->start->next->roomType;

    return tpl;
}

RoomType RoomNavigator::getCurrentRoom(){
    return l->start->roomType;
}

Level *RoomNavigator::getLevel() {
    return l;
}
