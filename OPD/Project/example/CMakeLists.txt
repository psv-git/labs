cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Application)

# Установка переменной со списком исходников для исполняемого файла
set(SOURCE_BIN main.cpp)

# Тоже самое, но для библиотеки
set(ENGINE_LIB  ../engine/parsers/tinyxml2.cpp
                ../engine/parsers/TmxParser.cpp
                ../engine/controllers/AObjectController.cpp
                ../engine/containers/Tile.cpp
                ../engine/containers/Object.cpp
                ../engine/containers/TileLayer.cpp
                ../engine/containers/ObjectLayer.cpp
                ../engine/containers/Scene.cpp
                ../engine/managers/SceneManager.cpp
                ../engine/managers/WindowManager.cpp
                ../engine/EventHandler.cpp
                ../engine/EngineCore.cpp)

set(APP_LIB controllers/ObjectController.cpp
            Application.cpp)

# Создание статической библиотеки
add_library(MYLIB STATIC ${ENGINE_LIB} ${APP_LIB})

# Создает исполняемый файл с именем main
add_executable(app ${SOURCE_BIN})

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "-std=c++17" ${CMAKE_CXX_FLAGS})

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
target_compile_definitions(app PRIVATE SFML_STATIC)

target_link_libraries(app MYLIB ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} "stdc++fs")
