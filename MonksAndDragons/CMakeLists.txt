cmake_minimum_required(VERSION 3.19)
project(MonksAndDragons)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
# For JSON parsing and serializing
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
## end nlohmann json
add_subdirectory(Entity)

add_library(logger)
target_sources(logger PUBLIC Logger.h Logger.cpp Entity/Events.h SubjectInstance.h)
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(Settings)
add_subdirectory(TUI)
add_subdirectory(Rooms)



add_executable(MonksAndDragons main.cpp SubjectInstance.h)
target_link_libraries(MonksAndDragons settings tui rooms entity logger nlohmann_json::nlohmann_json)

enable_testing()
add_subdirectory(Tests)
