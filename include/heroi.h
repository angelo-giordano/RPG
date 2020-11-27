#pragma once
#include "personagem.h"
#include "espada.h"
#include "armadura.h"
#include "transicao.h"
#include "inimigo.h"
#include "global.h"

class Heroi : public Personagem
{
public:
    bool game_over_control = false;
    std::string img_heroi = R"(
                               *     :=:.
                               *   #**#*-
                                 =+:#+=#*#:
                               :-:+:--.+: .
                             ..- :==+=+*+-:
                             .. . **%******-  .:
                             . ... #%*#++*+
                               =+*#*+###:.
                                 =*#+**#=-..
                                 *#=*#+#==..
                                 *####**##+ .
                               -*#*+*#*-: - .
                               *##***##*=-.  :
                               =+++***+--*:   +
                               .=-==:-:.:-*+.
                                 :--: .::.. :*+:
                               .-:::  :::..  :+*:
                                 #%    .++:    .+#
                                 +#:    %%:
                                 :###   :%%:
                             ::-++::   .##.
                                       -*#.        )";
    using Personagem::Personagem;

    bool is_game_over()
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

    void resetar_hp()
    {
        this->hp = 100;
    }

    void resetar_atk()
    {
        this->atk = 5;
    }

    void resetar_def()
    {
        this->def = 0;
    }

    void desenhar_personagem()
    {
        std::cout << this->img_heroi << std::endl;
    }

    void equipar_espada(Espada espada)
    {
        resetar_atk();
        transicao();
        std::cout << espada.nome << " equipada!!!\n\n";
        Personagem::mostrar_dados_personagem();
        this->atk += espada.atk;
        std::cout << "     |\n"
                  << "     V\n\n";

        Personagem::mostrar_dados_personagem();
        transicao();
    }

    void equipar_armadura(Armadura armadura)
    {
        resetar_hp();
        resetar_def();
        transicao();
        std::cout << armadura.nome << " equipada!!!\n\n";
        Personagem::mostrar_dados_personagem();
        this->hp += armadura.hp;
        this->def += armadura.def;
        std::cout << "     |\n"
                  << "     V\n\n";

        Personagem::mostrar_dados_personagem();
        transicao();
    }

    float calcular_dano(Personagem personagemDefendendo)
    {
        return this->atk - (1 + personagemDefendendo.def);
    }

    void atacar(Inimigo *inimigo)
    {
        inimigo->hp = inimigo->hp - calcular_dano(*inimigo);
        std::cout << this->nome << " deu " << calcular_dano(*inimigo) << " de dano ao " << inimigo->nome << std::endl
                  << std::endl;
        hp_personagem_atual = inimigo->hp;
        transicao();
    }

    void verificar_game_over()
    {
        if (this->is_game_over())
        {
            this->game_over();
        }
    }

    void game_over()
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
};
