//
// Created by games on 7/3/2021.
//
#include "EmptyRoom.h"
#include "Logger.h"

void EmptyRoom::healMana(MovingEntity &player) {
    std::string shouldHeal;
    std::cout << "Do you want to heal yourself (y/n) >>" << std::endl;
    std::cin >> shouldHeal;
    if(shouldHeal == "y")
        std::cout << "healing player to full health" << std::endl;
        player.setHealthPoints(player.maxHealthPoints);
}

void EmptyRoom::roomSpeciality(MovingEntity &player) {
    healMana(player);
}


EmptyRoom::EmptyRoom() {
    roomType = RoomType::EMPTY;
}

void EmptyRoom::log(Subject &subject) {
    subject.notify("Visited Empty Room",Events::TRAVERSE);
}
