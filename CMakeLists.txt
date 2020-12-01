cmake_minimum_required(VERSION 3.0.0)
project(RPG VERSION 0.1.0)

include_directories(${PROJECT_SOURCE_DIR} include)

add_executable(RPG src/main.cpp src/global.cpp  src/espada.cpp src/armadura.cpp src/heroi.cpp src/inimigo.cpp src/personagem.cpp src/funcoes_auxiliares.cpp)
