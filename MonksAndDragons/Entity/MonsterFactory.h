//
// Created by games on 7/4/2021.
//

#ifndef MONKSANDDRAGONS_MONSTERFACTORY_H
#define MONKSANDDRAGONS_MONSTERFACTORY_H
#include "MonsterTypes.h"
#include "Monster.h"
#include "Goblin.h"

struct MonsterFactory{
public:
    static Monster* generate(MonsterTypes type){
        Monster *m;
        switch(type){
            case GOBLIN:
            {
                m = new Goblin();
                break;
            }
        }
        return m;
    }
};
#endif //MONKSANDDRAGONS_MONSTERFACTORY_H
