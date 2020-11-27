#pragma once
#include <iostream>

class Personagem
{
public:
    std::string nome;
    float hp;
    float atk;
    float def;
    Personagem(std::string nome, float hp, float atk, float def)
    {
        this->nome = nome;
        this->hp = hp;
        this->atk = atk;
        this->def = def;
    }

    void mostrar_dados_personagem()
    {
        std::cout << "=> " << this->nome << std::endl;
        std::cout << "=> HP...:" << this->hp << std::endl;
        std::cout << "=> ATK..:" << this->atk << std::endl;
        std::cout << "=> DEF..:" << this->def << std::endl
                  << std::endl;
    }

    // float calcular_dano(Personagem personagemDefendendo) {}

    // void atacar(Personagem *personagemDefendendo) {}
};
