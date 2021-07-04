//
// Created by games on 7/4/2021.
//

#ifndef MONKSANDDRAGONS_LOGGER_H
#define MONKSANDDRAGONS_LOGGER_H
#define MAX_OBSERVERS 10

#include <string>
#include "Entity/Events.h"
#include <list>
/**
 * Observer pattern
 **/
class Observer
{
public:
    virtual ~Observer();
    virtual void onNotify(std::string detail,Events e) = 0;
    virtual void writeToFile()=0;
};

class TraverseLogger: public Observer{
private:
    std::list<std::string> traverseLog;
public:
    void onNotify(std::string detail, Events e) override;
    void writeToFile() override;
};

class FightLogger:public Observer{
private:
    std::list<std::string> fightlog;
public:
    void onNotify(std::string detail, Events e) override;

    void writeToFile() override;
};

class Subject {
private:
    Observer* observers[MAX_OBSERVERS];
    int numObservers;

public:
    void addObserver(Observer* observer){
       observers[numObservers] = observer;
       numObservers++;
    }
    void removeObserver(Observer* observer){
        observers[numObservers] = nullptr;
        numObservers--;
    }
    void notify(const std::string& detail,Events e){
        for(int i= 0; i<numObservers;i++){
            observers[i]->onNotify(detail,e);
            observers[i]->writeToFile();
        }
    }

};

#endif //MONKSANDDRAGONS_LOGGER_H
