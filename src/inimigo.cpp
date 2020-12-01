#include <iostream>
#include "heroi.h"
#include "inimigo.h"
#include "funcoes_auxiliares.h"

Inimigo::Inimigo(int ID, tipo_inimigo tipo_do_inimigo, std::string nome, float hp, float atk, float def) : Personagem(nome, hp, atk, def)
{
    this->ID = ID;
    this->tipo_do_inimigo = tipo_do_inimigo;
    this->nome = nome;
    this->hp = hp;
    this->atk = atk;
    this->def = def;
}

void Inimigo::mostrar_dados_personagem()
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
    std::cout << "=> " << this->nome << std::endl;
    std::cout << "=> HP...:" << this->hp << std::endl;
    std::cout << "=> ATK..:" << this->atk << std::endl;
    std::cout << "=> DEF..:" << this->def << std::endl
              << std::endl;
}

void Inimigo::desenhar_personagem()
{
    std::cout << this->img_inimigo << std::endl;
}

bool Inimigo::esta_vivo()
{
    hp_personagem_atual = this->hp;
    if (hp_personagem_atual <= 0)
    {
        this->vivo = false;
    }

    return this->vivo;
}

float Inimigo::calcular_dano(Heroi heroi)
{
    return this->atk - (1 + heroi.def);
}

void Inimigo::atacar(Heroi *heroi)
{
    if (!this->esta_vivo())
    {
    }

    else
    {
        heroi->hp = heroi->hp - calcular_dano(*heroi);
        std::cout << this->nome << " deu " << calcular_dano(*heroi) << " de dano ao " << heroi->nome << std::endl
                  << std::endl;
        heroi->verificar_game_over();
        transicao();
    }
}

void Inimigo::morrer()
{
    this->hp = 0;
    std::cout << "   MORTO\n";
    this->mostrar_dados_personagem();
}
