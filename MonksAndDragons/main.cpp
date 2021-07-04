#include <iostream>
//#include "TUI/SplashScreen.h"
#include "MovingEntity.h"
#include "Monk.h"
#include "Room.h"
#include "RoomNavigator.h"
#include "SubjectInstance.h"
#include "SettingsSingleton.h"
#include "Level1.h"
#include "Level2.h"
#include "Level.h"
#include <cstdlib>
#include "TUI/SplashScreen.h"

Subject SubjectInstance::subject{};

void GameLogic(RoomNavigator &navigator);

using namespace std;

void startGame(){
    //create a Monk
    // create Observers{fightLogger and traverseLogger}
    // create a room traversal instance
    // add observers to subject
    Monk player{};

    std::string buffer;
    std::cout << "enter the name of player >" << std::endl;
    std::cin >> buffer;
    player.setName(buffer);
    std::cout << "Customized Description of player > "<< std::endl;
    std::cin >> buffer;
    player.setDescription(buffer);

    //Observer pattern
    TraverseLogger lg{};
    FightLogger fg{};
    SubjectInstance::subject.addObserver(&lg);
    SubjectInstance::subject.addObserver(&fg);
    std::array<Level*,2> levels = {new Level1{}, new Level2{}};

    //check if random level is setup or not
    if(SettingsSingleton::getInstance().settings.randomLevel){
        int randomData = rand() % 2;
        std::cout << "You are now playing level " << randomData << std::endl;
        RoomNavigator navigator(&player,levels[randomData],false);
        GameLogic(navigator);
    }else{
        for(Level *a: levels){
            std::cout << "You are now playing " << a->name << std::endl;
            RoomNavigator navigator(&player,a,false);
            GameLogic(navigator);
        }
        //room traversal
//        RoomNavigator
    }



}

void GameLogic(RoomNavigator &navigator) {
    //now player is free to navigate.
// play until you don't get to final room
    while(true) {
        auto getPreviousAndNextRooms = navigator.getPreviousAndNextRooms();
        cout << "choose which room to go into" << endl;
        if (getPreviousAndNextRooms[0] != NULLROOM) {
            cout << "1. Get to previous room" << endl;
        }
        if (getPreviousAndNextRooms[1] != NULLROOM) {
            cout << "2. Get to next room" << endl;
        }

        int roomChoose;
        cin >> roomChoose;
        if (roomChoose == 1) {
            if (navigator.getPreviousRoom()) {
                cout << "changing rooms " << endl;
            } else {
                cout << "wrong choice" << endl;
            }
        }

        if (roomChoose == 2) {
            if (navigator.getNextRoom()) {
                cout << "changing rooms " << endl;
            } else {
                cout << "wrong choice" << endl;
            }
        }
        if(navigator.getPreviousAndNextRooms()[1] == NULLROOM || navigator.getLevel()->start->roomType == TREASURE){
            cout << "you won " << navigator.getLevel()->name << endl;
            cout << "------------------------------x-----------------------------"  << endl;
            //ASCII character here

//            if(SettingsSingleton::getInstance().settings.title == Title::ASCII){
//               cout << TUIComponent::AsciiTitle << endl;
//            }
            break;
        }
    }
}

int main() {
    SplashScreen s{};
    s.showTitle();
    startGame();
    //start game now
};
