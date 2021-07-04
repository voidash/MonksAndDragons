//
// Created by games on 7/3/2021.
//

#pragma once
#ifndef MONKSANDDRAGONS_EMPTYROOM_H
#define MONKSANDDRAGONS_EMPTYROOM_H

#include "room.h"
//   /' .-'oO`'-.,\                                              /,.-'`Oo'-. '\
//   |~/!!O#Oo    `                                              `    oO#O!!\~|
//|/|!!)##               Empty Room                             ##(!!|\|
#include <iostream>
#include "MovingEntity.h"

struct EmptyRoom: public Room {
    EmptyRoom();

    void log(Subject &subject) override;


    void roomSpeciality(MovingEntity& player) override;

    //Speciality of healing. maybe in future goblin might also heal
    void healMana(MovingEntity& player);



};


#endif //MONKSANDDRAGONS_EMPTYROOM_H
