#pragma once
#include <nlohmann/json.hpp>
#include <fstream>
#include <iomanip>
#include <filesystem>
using json = nlohmann::json;

enum Title{
    REGULAR='R',
    ASCII='A'
};

struct Settings{

    char title;
    bool randomLevel;

    // for test
    bool operator==(const Settings &rhs) const {
        return title == rhs.title &&
               randomLevel == rhs.randomLevel;
    }

    bool operator!=(const Settings &rhs) const {
        return !(rhs == *this);
    }
};

struct SettingsJSON{
    explicit SettingsJSON(Settings& p)  {
        //Default Configuration if file fails to create or load
        toJSON(p);
    }
    SettingsJSON()=default;

    void toJSON(Settings& p){
        j = json{{"title",p.title},{"randomLevel", p.randomLevel}};
    }

    void fromJSON(Settings& p){
        j.at("title").get_to(p.title);
        j.at("randomLevel").get_to(p.randomLevel);
    }

    /**
     * Load Settings.json if it is present, else create settings.json
     **/
    void loadJSON(){
        std::ifstream i("settings.json");
        if(i.good())
            i >> j;
        else {
            writeJSONForNew();
        }

    }

    /**
     * Write settings to JSON File
     *
     **/
    void writeJSON(){
        std::ofstream o("settings.json");
        //set width number to 4
        o << std::setw(4) << j << std::endl;
    }
    void writeJSONForNew(){
        j = json{{"title",Title::ASCII},{"randomLevel", false}};
        std::ofstream o("settings.json");
        //set width number to 4
        o << std::setw(4) << j << std::endl;

    }

private:
    json j;
};
