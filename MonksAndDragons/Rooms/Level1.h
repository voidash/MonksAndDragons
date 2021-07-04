//
// Created by games on 7/4/2021.
//

#ifndef MONKSANDDRAGONS_LEVEL1_H
#define MONKSANDDRAGONS_LEVEL1_H


#include "Level.h"
#include "RoomFactory.h"


class Level1 : public Level{
public:
    Level1() : Level(){
        name = "Level 1";
        Room *goblinRoom = RoomFactory::getRoom(RoomType::MONSTER, nullptr, nullptr);
        Room *treasureRoom = RoomFactory::getRoom(RoomType::TREASURE, nullptr, nullptr);
        start =  RoomFactory::getRoom(RoomType::EMPTY, nullptr,nullptr);
        start->next = goblinRoom;
        goblinRoom->next = treasureRoom;
        goblinRoom->previous = start;
        treasureRoom->previous = goblinRoom;
    }
};

#endif //MONKSANDDRAGONS_LEVEL1_H
