#include <gtest/gtest.h>
#include "Monk.h"
#include "Logger.h"
#include "Level1.h"
#include "RoomNavigator.h"
#include "SubjectInstance.h"
#include <fstream>
Subject SubjectInstance::subject{};
//Check the file traverse.txt to see if logging is happening correctly or not
TEST(LoggerTest,LogCurrentRoomWhileNavigatingRoomsLevel1){
    Monk* m = new Monk{};
    auto* lvl = new Level1{};

    TraverseLogger tvl{};
    SubjectInstance::subject.addObserver(&tvl);

    RoomNavigator nvgn(m,dynamic_cast<Level*>(lvl),true);
//    nvgn.getLevel()->start->log(sc);
    nvgn.getNextRoom();
//    nvgn.getLevel()->start->log(sc);
    nvgn.getNextRoom();
//    nvgn.getLevel()->start->log(sc);
    std::string requiredContent = R"(traversal: Visited Empty Room
traversal: Visited Monster room
traversal: Visited Treasure Room
)";

    std::string fileContent;
    std::ifstream file;
    file.open("traverse.txt");
    std::stringstream strStream;
    strStream << file.rdbuf();
    fileContent = strStream.str();
    ASSERT_EQ(requiredContent,fileContent);



}

//Subject SubjectInstance::subject{};
//TEST(LoggerTest,GoblinVSMonk){
//    Monk* m = new Monk{};
//    auto* lvl = new Level1{};
//    FightLogger fl;
//    SubjectInstance::subject.addObserver(&fl);
//    RoomNavigator nvgn(m,dynamic_cast<Level*>(lvl),false);
//    nvgn.getNextRoom();
//}
