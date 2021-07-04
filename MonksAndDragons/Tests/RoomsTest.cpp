#include <gtest/gtest.h>
#include "RoomFactory.h"
#include "Level1.h"
#include "Level2.h"
#include "Monk.h"
#include "RoomNavigator.h"
#include "SubjectInstance.h"


Subject SubjectInstance::subject{};
TEST(TestForRooms,TestLevel1){
    ASSERT_EQ(1,1);

//    ASSERT_EQ(Setting,l);
Level1 lvl; // Level 1 starts with empty room, goblin room, and treasure room
ASSERT_EQ(RoomType::EMPTY,lvl.start->roomType);
lvl.start = lvl.start->next;
ASSERT_EQ(RoomType::MONSTER,lvl.start->roomType);
lvl.start = lvl.start->next;
ASSERT_EQ(RoomType::TREASURE,lvl.start->roomType);
}

TEST(TestForRooms,TestLevel2){
    ASSERT_EQ(1,1);

//    ASSERT_EQ(Setting,l);
    Level2 lvl; // Level 1 starts with empty room, goblin room, and treasure room
    ASSERT_EQ(RoomType::EMPTY,lvl.start->roomType);
    lvl.start = lvl.start->next;
    ASSERT_EQ(RoomType::MONSTER,lvl.start->roomType);
    lvl.start = lvl.start->next;
    ASSERT_EQ(RoomType::MONSTER,lvl.start->roomType);
    lvl.start = lvl.start->next;
    ASSERT_EQ(RoomType::TREASURE,lvl.start->roomType);
}

TEST(TestForRooms,RoomNavigationGetNextRoomStopAtNullTest){
    Monk* m = new Monk{};
    auto* lvl = new Level1{};

    RoomNavigator nvgn(m,dynamic_cast<Level*>(lvl),true);

    //start of level , we cant go to previous room as previous room doesn't exist
    ASSERT_EQ(nvgn.getPreviousRoom(),false);
    //check current room as empty room
    ASSERT_EQ(nvgn.getCurrentRoom(),RoomType::EMPTY);
    // go to next room
    ASSERT_EQ(nvgn.getNextRoom(),true);
    ASSERT_EQ(nvgn.getCurrentRoom(),RoomType::MONSTER);
    ASSERT_EQ(nvgn.getNextRoom(),true);
    ASSERT_EQ(nvgn.getCurrentRoom(),RoomType::TREASURE);
    ASSERT_EQ(nvgn.getNextRoom(),false);

    //check if current room is
}
