#include <iostream>
#include "armadura.h"

Armadura::Armadura(std::string nome, float hp, float def)
{
    this->nome = nome;
    this->hp = hp;
    this->def = def;
}
