//
// Created by games on 7/4/2021.
//

#ifndef MONKSANDDRAGONS_LEVEL2_H
#define MONKSANDDRAGONS_LEVEL2_H
#include "Level.h"
class Level2: public Level{
public:
 Level2() : Level() {
     name = "Level 2";
     Room * goblinRoom =  RoomFactory::getRoom(RoomType::MONSTER, nullptr, nullptr);
     Room * goblinRoom2 =  RoomFactory::getRoom(RoomType::MONSTER, nullptr, nullptr);
     Room * treasureRoom =  RoomFactory::getRoom(RoomType::TREASURE, nullptr, nullptr);
     start = RoomFactory::getRoom(RoomType::EMPTY, nullptr, nullptr);
     start->next = goblinRoom;
     goblinRoom->next = goblinRoom2;
     goblinRoom->previous = start;
     goblinRoom2->next = treasureRoom;
     treasureRoom->previous = goblinRoom2;
 }
};
#endif //MONKSANDDRAGONS_LEVEL2_H
