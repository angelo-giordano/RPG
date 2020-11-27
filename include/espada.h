#pragma once
#include <iostream>

class Espada
{
public:
    std::string nome;
    float atk;
    Espada(std::string nome, float atk)
    {
        this->nome = nome;
        this->atk = atk;
    }
};
