#include <gtest/gtest.h>
#include "SettingsModel.h"
#include "SettingsSingleton.h"



TEST(SettingsTest,GenerateJSONFromSettingsAndCreateAFileThenReadFromIt){
   Settings l{};
   l.randomLevel = true;
   l.title = Title::REGULAR;
   SettingsJSON on(l);
   on.writeJSON();

   Settings n{};
   SettingsJSON off(n);
   off.loadJSON();
   off.fromJSON(n);

   ASSERT_EQ(l,n);
}


