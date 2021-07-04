add_library(entity)

set_target_properties(entity PROPERTIES LINKER_LANGUAGE CXX)
target_sources(entity PUBLIC MovingEntity.h Monk.h Monk.cpp Goblin.h Goblin.cpp Events.h MonsterTypes.h Monster.h MonsterFactory.h)
target_link_libraries(entity logger)
target_include_directories(entity PUBLIC ${CMAKE_CURRENT_LIST_DIR})
