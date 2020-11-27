#pragma once
#include <iostream>

class Personagem
{
public:
    std::string nome;
    float hp;
    float atk;
    float def;

    Personagem(std::string nome, float hp, float atk, float def);

    void mostrar_dados_personagem();
};
