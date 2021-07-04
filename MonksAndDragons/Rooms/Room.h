#pragma once

#ifndef MONKSANDDRAGONS_ROOM_H
#define MONKSANDDRAGONS_ROOM_H
# define MAX_ITEMS 10
#include "MovingEntity.h"
#include "Logger.h"
#include <iostream>

enum RoomType{
    EMPTY,
    TREASURE,
    MONSTER,
    NULLROOM
};

struct Room{
public:
    Room *getPrevious() const {
        return previous;
    }

    void setPrevious(Room *previous) {
        Room::previous = previous;
    }

    Room *getNext() const {
        return next;
    }

    void setNext(Room *next) {
        Room::next = next;
    }

    Room * previous{};
    Room * next{};
    RoomType roomType = NULLROOM;

    virtual void log(Subject& subject) = 0;
    // for monster room we want to spawn goblin, empty room : heal
    virtual void roomSpeciality(MovingEntity& player) = 0;
};


#endif //MONKSANDDRAGONS_ROOM_H
