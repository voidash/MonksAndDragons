# gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# test for settings
add_executable(SettingsTest SettingsTest.cpp)
target_link_libraries(SettingsTest settings gtest_main nlohmann_json::nlohmann_json)

# test for rooms
add_executable(RoomsTest RoomsTest.cpp)
target_link_libraries(RoomsTest rooms tui entity gtest_main)

#test for loggers
add_executable(LoggerTest LoggerTest.cpp ${PROJECT_SOURCE_DIR}/SubjectInstance.h)
target_link_libraries(LoggerTest rooms tui entity logger gtest_main)


# test for dungeon Generator
# end gtest
