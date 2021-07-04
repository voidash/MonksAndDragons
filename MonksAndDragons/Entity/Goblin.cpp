//
// Created by games on 7/3/2021.
//

#include "Goblin.h"

Goblin::Goblin() {

    //set healthpoints and attack points to 10
    setHealthPoints(10);
    maxHealthPoints = 10;
    setAttackPoints(2);
    name = "Goblin";
    setType(MonsterTypes::GOBLIN);
}

void Goblin::attack(MovingEntity &another, Subject &c) {
    Monster::attack(another, c);
}

