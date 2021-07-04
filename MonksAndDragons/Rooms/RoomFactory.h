//
// Created by games on 7/4/2021.
//

#ifndef MONKSANDDRAGONS_ROOMFACTORY_H
#define MONKSANDDRAGONS_ROOMFACTORY_H
#include "Room.h"
#include "EmptyRoom.h"
#include "TreasureRoom.h"
#include "MonsterRoom.h"

class RoomFactory {
public:
    static Room *getRoom(RoomType room, Room *next, Room *previous) {
        switch (room) {
            case EMPTY: {
                auto *emp = new EmptyRoom();
                emp->next = next;
                emp->previous = previous;
                return emp;
            }
            case MONSTER: {
                auto *emp = new MonsterRoom();
                emp->next = next;
                emp->previous = previous;
                return emp;
            }
            case TREASURE: {
                auto *emp = new TreasureRoom();
                emp->next = next;
                emp->previous = previous;
                return emp;
            }
        }
        return nullptr;
    }

};
#endif //MONKSANDDRAGONS_ROOMFACTORY_H
