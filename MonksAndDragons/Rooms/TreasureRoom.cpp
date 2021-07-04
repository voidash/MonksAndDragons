//
// Created by games on 7/3/2021.
//

#include <TUI/MiscComponents.h>
#include "TreasureRoom.h"


void TreasureRoom::roomSpeciality(MovingEntity &player) {
    finishGame(player);
}

void TreasureRoom::finishGame(MovingEntity &player) {
}

TreasureRoom::TreasureRoom() {
    roomType = RoomType::TREASURE;
}

void TreasureRoom::log(Subject &subject) {

    subject.notify("Visited Treasure Room",Events::TRAVERSE);

}
