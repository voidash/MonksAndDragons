//
// Created by games on 7/4/2021.
//

#ifndef MONKSANDDRAGONS_RANDOMLEVELGENERATOR_H
#define MONKSANDDRAGONS_RANDOMLEVELGENERATOR_H

#include "Level.h"
#include "RoomFactory.h"
#include <cstdlib>
#include <ctime>

#define MAXIMUM_ROOMS 10
#define MINIMUM_ROOMS 3
#include <array>

class RandomLevel : public Level{
public:
    RandomLevel() : Level(){
        std::srand(std::time(0));

        int maximum_rooms = std::rand() % 10 + 1;
        if(maximum_rooms < 3) maximum_rooms = 3;
        name = "RandomLevel";
//        //end room is always treasure room
//        Room *treasureRoom = RoomFactory::getRoom(RoomType::TREASURE, nullptr, nullptr);
//        //start Room is always Empty Room
//        start =  RoomFactory::getRoom(RoomType::EMPTY, nullptr,nullptr);
//        start->next = goblinRoom;
//        goblinRoom->next = treasureRoom;
//        goblinRoom->previous = start;
//        treasureRoom->previous = goblinRoom;

        //first generate A array with random RoomType
       // [empty,monster,empty,monster,monster...]
       RoomType rooms[maximum_rooms];
//       RoomType[maximum_rooms] rooms{RoomType::NULLROOM};
        rooms[0] = RoomType::EMPTY;
        for (int i = 1; i < maximum_rooms-1; ++i) {
            if(std::rand() % 2 == 1) {
                rooms[i] = RoomType::EMPTY;
            }else {
                rooms[i] = RoomType::MONSTER;
            }
        }
        rooms[maximum_rooms-1] = RoomType::TREASURE;

        // now with rooms associated with types and not actual rooms, lets create rooms
//        std::array<Room *,maximum_rooms> roomPointer{};
        Room * roomPointer[maximum_rooms];
        for(int i=0;i<maximum_rooms;i++) {
            roomPointer[i] = RoomFactory::getRoom(rooms[i],nullptr, nullptr);
        }

        roomPointer[0]->next = roomPointer[1];
        roomPointer[maximum_rooms-1]->previous = roomPointer[8];
        for (int i = 1; i < maximum_rooms-1; ++i) {
           roomPointer[i]->next = roomPointer[i+1];
           roomPointer[i]->previous = roomPointer[i-1];
        }
        start = roomPointer[0];
    }
};

#endif //MONKSANDDRAGONS_RANDOMLEVELGENERATOR_H
