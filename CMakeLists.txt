cmake_minimum_required(VERSION 3.16)

# Название проекта
project(dukasino)

# Стандарт C++17 (требуется для D++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Собираем исполняемый файл (.exe) из исходников в src/
add_executable(dukasino
    main.cpp
)

find_package(dpp CONFIG REQUIRED)            # найти установленную библиотеку D++
target_link_libraries(dukasino PRIVATE dpp::dpp)  # подключить её к проекту