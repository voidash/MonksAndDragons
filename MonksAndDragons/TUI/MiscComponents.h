//
// Created by games on 7/3/2021.
//
#include <string>

struct TUIComponent {
static const std::string AsciiTitle;
static const std::string AsciiLevel;
static const std::string title;
static const std::string EmptyRoom;
static const std::string MonsterRoom;
static const std::string TreasureRoom;


static std::string ShowTitle(bool showAscii){
   if(showAscii) return AsciiTitle;
   return title;
}


};