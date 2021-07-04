//
// Created by games on 7/4/2021.
//

#ifndef MONKSANDDRAGONS_ROOMNAVIGATOR_H
#define MONKSANDDRAGONS_ROOMNAVIGATOR_H

#include "MovingEntity.h"
#include "Level.h"
#include <array>
class RoomNavigator {
public:
    RoomNavigator(MovingEntity *entity, Level *l,bool testing);
    std::array<RoomType,2> getPreviousAndNextRooms();
    bool getNextRoom();
    bool getPreviousRoom();

    RoomType getCurrentRoom();
    Level* getLevel();

private:
    MovingEntity* e;
    Level* l;
    bool testing;

};


#endif //MONKSANDDRAGONS_ROOMNAVIGATOR_H
