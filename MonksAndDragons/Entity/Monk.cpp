//
// Created by games on 7/3/2021.
//

#include "Monk.h"

Monk::Monk() {
    //set health points of monk to 30
    healthPoints = 20;
    attackPoints = 4;
    maxHealthPoints = 20;
}


const std::__cxx11::basic_string<char> &Monk::getName() const {
    return name;
}

void Monk::setName(const std::__cxx11::basic_string<char> &name) {
    Monk::name = name;
}

const std::__cxx11::basic_string<char> &Monk::getDescription() const {
    return description;
}

void Monk::setDescription(const std::__cxx11::basic_string<char> &des) {
    Monk::description = des;
}

void Monk::healMonk() {
    healthPoints = maxHealthPoints;
    //send to logger
}

void Monk::attack(MovingEntity &another, Subject& c) {
    c.notify(name+std::string(" attacked ")+another.name,Events::FIGHT);
    another.setHealthPoints(another.getHealthPoints()-getAttackPoints());
}

