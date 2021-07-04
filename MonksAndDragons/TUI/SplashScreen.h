//
// Created by games on 7/3/2021.
//

#ifndef MONKSANDDRAGONS_SPLASHSCREEN_CPP_H
#define MONKSANDDRAGONS_SPLASHSCREEN_CPP_H
#include <iostream>
#include "SettingsSingleton.h"
#include "MiscComponents.h"

using namespace std;

class SplashScreen{
public:
    SplashScreen();
    void showTitle();
    void startGame();
    void configureSettings();
};

void SplashScreen::showTitle() {
    bool show_ascii = false;

    if(SettingsSingleton::getInstance().settings.title == Title::ASCII)
        show_ascii = true;

    cout << TUIComponent::ShowTitle(show_ascii) << endl;
    cout << "choose option (1/2) >>" << endl;
    int option;
    cin >> option;
    if(option == 1){
       startGame();
    }else if(option == 2){
       configureSettings();
    }

}



void SplashScreen::startGame() {
    cout << "game started " << endl;
}

void SplashScreen::configureSettings() {
    // settings are change the type of title, or play at random level
    Settings s{};
    std::string ran;
    cout << "Do you want random level generation ?(y/n) >>"<< endl;
    cin >> ran;
    if(ran == "y") s.randomLevel = true;
    else s.randomLevel = false;

    ran = "";
    cout << "Do you want ASCII art ?(y/n) >>"<< endl;
    cin >> ran;
    if(ran == "y") s.title = Title::ASCII;
    else s.title = Title::REGULAR;

    SettingsJSON d(s);
    d.writeJSON();
    d.fromJSON(SettingsSingleton::getInstance().settings);
    showTitle();
}
/**
 * initialize the splashScreen
 *
 *
 * **/
SplashScreen::SplashScreen() {
    SettingsSingleton::getInstance().initialize();
}


#endif //MONKSANDDRAGONS_SPLASHSCREEN_CPP_H
