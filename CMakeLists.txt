cmake_minimum_required(VERSION 3.0.0)
project(RPG VERSION 0.1.0)

include_directories(${PROJECT_SOURCE_DIR} include)

#src main.cpp armadura.h espada.h global.h heroi.h inimigo.h limpar_tela.h personagem.h transicao.h
add_executable(RPG src/main.cpp)
