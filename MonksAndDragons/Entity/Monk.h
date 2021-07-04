//
// Created by games on 7/3/2021.
//
#ifndef MONKSANDDRAGONS_MONK_H
#define MONKSANDDRAGONS_MONK_H

#include "MovingEntity.h"
#include "Events.h"
#include <string>
using namespace std;
class Monk : public MovingEntity{
public:
    void attack(MovingEntity &another,Subject& c) override;

    Monk();

private:
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getDescription() const;

    void setDescription(const string &description);

    void healMonk();

private:
    std::string description;
};


#endif //MONKSANDDRAGONS_MONK_H
