cmake_minimum_required(VERSION 3.16)

project(NebulaTahoe VERSION 3.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia Core Gui Svg Core5Compat)
find_package(PkgConfig REQUIRED)
pkg_check_modules(TAGLIB REQUIRED taglib)

qt_standard_project_setup()

qt_add_executable(appNebulaTahoe
    main.cpp
    player.h
    Main.qml
)

target_include_directories(appNebulaTahoe PRIVATE ${TAGLIB_INCLUDE_DIRS})
target_link_libraries(appNebulaTahoe PRIVATE 
    Qt6::Quick 
    Qt6::Multimedia 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Svg 
    Qt6::Core5Compat 
    ${TAGLIB_LIBRARIES}
)
install(TARGETS appNebulaTahoe DESTINATION bin)
install(FILES Main.qml DESTINATION bin)
