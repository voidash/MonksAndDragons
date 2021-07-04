add_library(settings )


set_target_properties(settings PROPERTIES LINKER_LANGUAGE CXX)
target_sources(settings PUBLIC SettingsSingleton.h SettingsModel.h)
target_link_libraries(settings PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(settings PUBLIC ${CMAKE_CURRENT_LIST_DIR})



