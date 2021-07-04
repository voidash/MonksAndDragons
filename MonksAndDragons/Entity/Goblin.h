//
// Created by games on 7/3/2021.
//

#ifndef MONKSANDDRAGONS_GOBLIN_H
#define MONKSANDDRAGONS_GOBLIN_H

#include <string>
#include "MovingEntity.h"
#include "MonsterTypes.h"
#include "Monster.h"


class Goblin: public Monster {
public:
    Goblin();

    void attack(MovingEntity &another, Subject &c) override;

};


#endif //MONKSANDDRAGONS_GOBLIN_H
