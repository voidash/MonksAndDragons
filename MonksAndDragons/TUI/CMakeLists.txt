add_library(tui SplashScreen.h )

set_target_properties(tui PROPERTIES LINKER_LANGUAGE CXX)
target_sources(tui PUBLIC MiscComponents.h TUIDef.cpp)
