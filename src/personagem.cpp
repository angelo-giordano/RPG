#include <iostream>
#include "global.h"
#include "personagem.h"

Personagem::Personagem(std::string nome, float hp, float atk, float def)
{
    this->nome = nome;
    this->hp = hp;
    this->atk = atk;
    this->def = def;
}
