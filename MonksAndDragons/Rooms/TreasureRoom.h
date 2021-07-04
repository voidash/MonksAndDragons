//
// Created by games on 7/3/2021.
//
#pragma once
#ifndef MONKSANDDRAGONS_TREASUREROOM_H
#define MONKSANDDRAGONS_TREASUREROOM_H
#include "Room.h"

class TreasureRoom: public Room {
public:
    TreasureRoom();

    void log(Subject &subject) override;

    void roomSpeciality(MovingEntity &player) override;

    void finishGame(MovingEntity &player);
};


#endif //MONKSANDDRAGONS_TREASUREROOM_H
