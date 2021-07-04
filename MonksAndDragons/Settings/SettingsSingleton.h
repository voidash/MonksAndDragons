//
// Created by games on 7/3/2021.
//

#ifndef MONKSANDDRAGONS_SETTINGSSINGLETON_H
#define MONKSANDDRAGONS_SETTINGSSINGLETON_H

#include "SettingsModel.h"
#include <iostream>
class SettingsSingleton{
private:
    SettingsSingleton()=default;
public:
    Settings settings;
    static SettingsSingleton& getInstance(){
        static SettingsSingleton instance;
        return instance;
    }

    void initialize(){
        settings.randomLevel = false;
        settings.title = Title::ASCII;
        SettingsJSON json{};
        json.loadJSON();
        json.fromJSON(settings);
//        std::cout << settings.title << std::endl;


    }


};
#endif //MONKSANDDRAGONS_SETTINGSSINGLETON_H
