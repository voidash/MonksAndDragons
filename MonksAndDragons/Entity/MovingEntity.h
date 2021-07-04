//
// Created by games on 7/3/2021.
//

#pragma once
#ifndef MONKSANDDRAGONS_MOVINGENTITY_H
#define MONKSANDDRAGONS_MOVINGENTITY_H
#include "Logger.h"

class MovingEntity{
public:
    virtual void attack(MovingEntity& another, Subject& c) = 0;
    int getAttackPoints() const {
        return attackPoints;
    }

    void setAttackPoints(int ap) {
        MovingEntity::attackPoints = ap;
    }

    int getHealthPoints() const {
        return healthPoints;
    }

    void setHealthPoints(int hp) {
        MovingEntity::healthPoints = hp;
    }

    bool checkDead(){
        if(healthPoints <= 0)
            return true;
        return false;
    }


protected:
    int attackPoints;
    int healthPoints;
public:
    int maxHealthPoints;
    std::string name="MovingEntity";

};
#endif //MONKSANDDRAGONS_MOVINGENTITY_H
