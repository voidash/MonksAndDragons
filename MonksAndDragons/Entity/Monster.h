//
// Created by games on 7/4/2021.
//

#ifndef MONKSANDDRAGONS_MONSTER_H
#define MONKSANDDRAGONS_MONSTER_H
#include "MovingEntity.h"
#include "MonsterTypes.h"
class Monster: public MovingEntity{
public:
    Monster() {
        type = MonsterTypes::UNRECOGNIZED;
        name = "Monster";
    }

    void attack(MovingEntity &another, Subject &c) override {
        c.notify(name+std::string(" attacked ")+another.name,Events::FIGHT);
        another.setHealthPoints(another.getHealthPoints()-getAttackPoints());
    }

    MonsterTypes getType() const {
        return type;
    }

    void setType(MonsterTypes ty) {
        Monster::type = ty;
    }

protected:
    MonsterTypes type;

};

#endif //MONKSANDDRAGONS_MONSTER_H
