//
// Created by games on 7/3/2021.
//

#include "MonsterRoom.h"
#include "MonsterFactory.h"
#include <ctime>
#include <cstdlib>
#include "Monster.h"
#include "SubjectInstance.h"




void MonsterRoom::roomSpeciality(MovingEntity &player) {
    confrontGoblins(player);
}

void MonsterRoom::confrontGoblins(MovingEntity &player) {
std::cout << (player.name)+std::string(" has confronted a goblin") <<std::endl;

auto *m = dynamic_cast<MovingEntity *>(MonsterFactory::generate(MonsterTypes::GOBLIN));

bool playerTurn = true;
while(!player.checkDead() && !m->checkDead()){
    //take turns
    std::cout <<"Player health points: "<< player.getHealthPoints()<< std::endl;
    std::cout <<"Goblin health points: "<< m->getHealthPoints()<< std::endl;
    if(playerTurn){
        srand((unsigned) time(0));
        std::cout << "Your turn" << std::endl;
        std::cout << "Do you wish to attack or defend?(1/2)" << std::endl;
        int inf;
        std::cin >> inf;
        if(inf == 1) {
            // 50% 50% chance
            if (rand() % 2 == 1) {
                player.attack(*m, SubjectInstance::subject);
            } else {
                std::cout << "missed" << std::endl;
            }
        }else{
                std::cout << "Player is defending" << std::endl;
            }
        playerTurn = false;
        continue;
        }
    std::cout << "goblin is trying to attack" <<std::endl;
    if (rand() % 2 == 1) {
        std::cout << "attacking player "<< std::endl;
        m->attack(player, SubjectInstance::subject);
    } else {
        std::cout << "missed" << std::endl;
    }
       playerTurn=true;
    }
if(player.checkDead()){
    std::cout << "Player is dead" << std::endl;
    exit(0);
}else{
    std::cout <<player.name << " killed goblin" << std::endl;
}



}



MonsterRoom::MonsterRoom() {
    roomType = RoomType::MONSTER;

}

void MonsterRoom::log(Subject &subject) {
    subject.notify("Visited Monster room",Events::TRAVERSE);
}

