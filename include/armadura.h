#pragma once
#include <iostream>

class Armadura
{
public:
    std::string nome;
    float hp;
    float def;
    Armadura(std::string nome, float hp, float def)
    {
        this->nome = nome;
        this->hp = hp;
        this->def = def;
    }
};
