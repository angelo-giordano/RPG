#pragma once
#include "heroi.h"

class Inimigo : public Personagem
{
public:
    enum tipo_inimigo
    {
        demonio,
        golem,
        boss
    };
    bool vivo = true;
    int ID;
    tipo_inimigo tipo_do_inimigo;
    std::string img_inimigo = "";
    std::string nome;
    float hp;
    float atk;
    float def;
    Inimigo(int ID, tipo_inimigo tipo_do_inimigo, std::string nome, float hp, float atk, float def) : Personagem(nome, hp, atk, def)
    {
        this->ID = ID;
        this->tipo_do_inimigo = tipo_do_inimigo;
        this->nome = nome;
        this->hp = hp;
        this->atk = atk;
        this->def = def;
    }

    void mostrar_dados_personagem()
    {
        switch (this->tipo_do_inimigo)
        {
        case demonio:
            img_inimigo = "                    \n"
                          "  -+       :+       \n"
                          "  *=   .    -#      \n"
                          "  *-.. .:-.:*-      \n"
                          "  := = .= ==-       \n"
                          "#-=== .====-#*-     \n"
                          "  +=#+--++=++= .  ..\n"
                          "  ==+++++==  -:..:. \n"
                          "    -**-*-   -::::  \n"
                          "  .-*+++#*+ . -.....\n"
                          "  : *--=--*:-     .:\n"
                          "-=.:::=---.=*- -    \n"
                          "*  --:=--=  -++**   \n"
                          "-  =**#**+          \n"
                          "    =+**+*=         \n"
                          "    *  *  *         \n"
                          "    +     *         \n"
                          "    .     ..        \n";
            break;
        case golem:
            img_inimigo = "                          \n"
                          "      +*--+=-*==          \n"
                          "      #--=------=*        \n"
                          "    #=*=-*-=--=-=*        \n"
                          "    -@-==@.+-==--=+       \n"
                          "    =#*==#*+--=+--=#      \n"
                          "    =-=---------==--=:    \n"
                          "    ==============--==:   \n"
                          "    ##@@@@@#@@*+===--=-== \n"
                          "  ##+#@%****%@#-=*#=-:-@  \n"
                          "  %=#+==--::====-=++@==-==\n"
                          "#:=#+====--===--==+@@=-== \n"
                          "=--++++==-=::=---==+@==== \n"
                          "@==+@+++=-===---==++@---+@\n"
                          "*+=@#++*++=+==--=+#@=-=-# \n"
                          "== #=-++#::::#=-==+ ##:=  \n"
                          "    +--=+#     #==++  =   \n"
                          "    ==-=#       +==+@     \n"
                          "    =--=#       ++==+%    \n"
                          "  #=--=+=     =+=+-===    \n"
                          "  :.:::::     =:::::.:=   \n";
            break;
        case boss:
            img_inimigo = "                                \n"
                          "        =+%%      +#%*==        \n"
                          "    =%*#%=       %%#%#%@-:      \n"
                          "  -#*#%%%        @#%%%##*#%=    \n"
                          "%%*=+#*# =      %##-*:=:###%=   \n"
                          "###=  *%#%#%=:   #%%-=    +%##= \n"
                          "=###   %@%###%% =#%#:%%    *#*##\n"
                          "@=:+= #% %@%#%=%#%*%:+%#   ==:=:\n"
                          "  @=#*=+@%%@##+# %*#*%# ==      \n"
                          "    %= @*@#**%##  #%= =*%       \n"
                          "  =#  %#@%##%#*%#*#   *#*       \n"
                          "  #+ *##%%#@++## %#    ##       \n"
                          "  ##  %=%##%=%=%=#%    ##+      \n"
                          "  %#  %#@##%==*==*%@  ##%%      \n"
                          "  @#-:-#%####@==*+###  =-#%     \n"
                          "  %# ++%#%=#%%###+%#%  . =%     \n"
                          "  %    %*@+**@@%%-*%%     *     \n"
                          "  #    %@@+#%%@@% *%=     :     \n"
                          "  =    @@%%@*%%%%@*%            \n"
                          "        @%#%%%#%%%=             \n"
                          "        @%##%%+#%%.             \n"
                          "        =#**%%**%=*             \n"
                          "          +%%@@%+ -             \n"
                          "          ##- **#               \n"
                          "          +=  %#                \n"
                          "          =   @=                \n";
            break;

        default:

            img_inimigo = "Vazio";
            break;
        }

        std::cout << "=> ID ---> " << this->ID << std::endl;
        Personagem::mostrar_dados_personagem();
    }

    void desenhar_personagem()
    {
        std::cout << this->img_inimigo << std::endl;
    }

    bool esta_vivo()
    {
        if (hp_personagem_atual <= 0)
        {
            this->vivo = false;
        }

        return this->vivo;
    }

    float calcular_dano(Heroi heroi)
    {
        return this->atk - (1 + heroi.def);
    }

    void atacar(Heroi *heroi)
    {
        heroi->hp = heroi->hp - calcular_dano(*heroi);
        std::cout << this->nome << " deu " << calcular_dano(*heroi) << " de dano ao " << heroi->nome << std::endl
                  << std::endl;
        heroi->verificar_game_over();
        transicao();
    }
};
