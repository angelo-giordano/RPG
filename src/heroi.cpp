#include <iostream>
#include <iomanip>
#include "personagem.h"
#include "espada.h"
#include "armadura.h"
#include "inimigo.h"
#include "global.h"
#include "heroi.h"
#include "funcoes_auxiliares.h"

Heroi::Heroi(std::string nome, float hp, float atk, float def) : Personagem(nome, hp, atk, def){};

void Heroi::mostrar_dados_personagem()
{
    std::cout << "=> " << this->nome << std::endl;
    std::cout << "=> HP...:" << this->hp << std::endl;
    std::cout << "=> ATK..:" << this->atk << std::endl;
    std::cout << "=> DEF..:" << this->def << std::endl
              << std::endl;
}

bool Heroi::is_game_over()
{
    if (this->hp <= 0)
    {
        this->hp = 0;
        this->game_over_control = true;
    }
    else
    {
        this->game_over_control = false;
    }

    return this->game_over_control;
}

void Heroi::resetar_hp()
{
    this->hp = 100;
}

void Heroi::resetar_atk()
{
    this->atk = 20;
}

void Heroi::resetar_def()
{
    this->def = 0;
}

void Heroi::resetar_equip()
{
    this->espada_equipada = false;
    this->armadura_equipada = false;
}

void Heroi::desenhar_personagem()
{
    std::cout << this->img_heroi << std::endl;
}

void Heroi::equipar_espada(Espada *espada)
{
    this->espada_equipada = true;
    transicao();
    std::cout << espada->nome << " equipada!!!\n\n";
    mostrar_dados_personagem();
    resetar_atk();

    this->atk += espada->atk;

    std::cout << "     |\n"
              << "     V\n\n";

    mostrar_dados_personagem();
    transicao();
}

void Heroi::equipar_armadura(Armadura *armadura)
{
    this->armadura_equipada = true;
    transicao();
    std::cout << armadura->nome << " equipada!!!\n\n";
    mostrar_dados_personagem();
    this->resetar_hp();
    this->resetar_def();

    this->hp += armadura->hp;
    this->def += armadura->def;

    std::cout << "     |\n"
              << "     V\n\n";

    mostrar_dados_personagem();
    transicao();
}

float Heroi::calcular_dano(Personagem personagemDefendendo)
{
    return this->atk - (1 + personagemDefendendo.def);
}

void Heroi::atacar(Inimigo *inimigo)
{
    if (inimigo->esta_vivo())
    {
        inimigo->hp = inimigo->hp - calcular_dano(*inimigo);

        std::cout << this->nome << " deu " << calcular_dano(*inimigo) << " de dano ao " << inimigo->nome << "." << std::endl
                  << std::endl;

        hp_personagem_atual = inimigo->hp;

        if (inimigo->hp <= 0)
        {
            std::cout << inimigo->nome << " morreu! F... " << std::endl
                      << std::endl;
        }
    }
    else
    {
        ++inimigo->acompanhar_tentativas_ataque_morto;
        std::cout << this->nome << " atacou o corpo de " << inimigo->nome << ", por isso não causou dano! Acerte alguém vivo da próxima vez :)" << std::endl
                  << std::endl;
    }

    transicao();
}

void Heroi::verificar_game_over()
{
    if (this->is_game_over())
    {
        this->game_over();
    }
}

void Heroi::game_over()
{
    this->mostrar_dados_personagem();

    std::cout << R"(
                              .g8"""bgd        db      `7MMM.     ,MMF'`7MM"""YMM
                            .dP'     `M       ;MM:       MMMb    dPMM    MM    `7
                            dM'       `      ,V^MM.      M YM   ,M MM    MM   d
                            MM              ,M  `MM      M  Mb  M' MM    MMmmMM
                            MM.    `7MMF'   AbmmmqMA     M  YM.P'  MM    MM   Y  ,
                            `Mb.     MM    A'     VML    M  `YM'   MM    MM     ,M
                              `"bmmmdPY  .AMA.   .AMMA..JML. `'  .JMML..JMMmmmmMMM




                              .g8""8q.   `7MMF'   `7MF'`7MM"""YMM  `7MM"""Mq.
                            .dP'    `YM.   `MA     ,V    MM    `7    MM   `MM.
                            dM'      `MM    VM:   ,V     MM   d      MM   ,M9
                            MM        MM     MM.  M'     MMmmMM      MMmmdM9
                            MM.      ,MP     `MM A'      MM   Y  ,   MM  YM.
                            `Mb.    ,dP'      :MM;       MM     ,M   MM   `Mb.
                              `"bmmd"'         VF      .JMMmmmmMMM .JMML. .JMM.   )"
              << std::endl;
    std::exit(0);
}