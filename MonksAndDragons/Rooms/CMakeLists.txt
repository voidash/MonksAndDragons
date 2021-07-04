add_library(rooms Level.h Level1.h Level2.h RoomFactory.h)

set_target_properties(rooms PROPERTIES LINKER_LANGUAGE CXX)
#target_sources(rooms PUBLIC Room.h EmptyRoom.h EmptyRoom.cpp MonsterRoom.h MonsterRoom.cpp TreasureRoom.h TreasureRoom.cpp)
target_sources(rooms PUBLIC Room.h EmptyRoom.h MonsterRoom.h TreasureRoom.h EmptyRoom.cpp MonsterRoom.cpp TreasureRoom.cpp RoomNavigator.cpp RoomNavigator.h)
target_link_libraries(rooms PUBLIC entity logger)
target_include_directories(rooms PUBLIC ${CMAKE_CURRENT_LIST_DIR})
