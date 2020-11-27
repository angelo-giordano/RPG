#include <iostream>
#include <list>
#include <iomanip>
#include "global.h"

void limpar_tela()
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "Não suportado"
#endif
}

void transicao()
{
    std::cout << "\nPressione ENTER para continuar!";
    std::cin.get();
    limpar_tela();
}

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

    void atacar(Personagem *inimigo)
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

/* class InimigoDemonio : Inimigo
{
public:
  std::string img_inimigo = "                                \n"
                            "           -+       :+          \n"
                            "           *=   .    -#         \n"
                            "           *-.. .:-.:*-         \n"
                            "           := = .= ==-          \n"
                            "         #-=== .====-#*-        \n"
                            "           +=#+--++=++= .  ..   \n"
                            "           ==+++++==  -:..:.    \n"
                            "             -**-*-   -::::     \n"
                            "           .-*+++#*+ . -.....   \n"
                            "           : *--=--*:-     .:   \n"
                            "         -=.:::=---.=*- -       \n"
                            "         *  --:=--=  -++**      \n"
                            "         -  =**#**+             \n"
                            "             =+**+*=            \n"
                            "             *  *  *            \n"
                            "             +     *            \n"
                            "             .     ..           \n";

  using Inimigo::Inimigo;
  void mostrar_dados_personagem()
  {
    std::cout << img_inimigo << std::endl;
    Personagem::mostrar_dados_personagem();
  }
};

class InimigoSlime : Inimigo
{
public:
  std::string img_inimigo = "                                    \n"
                            "           +*--+=-*==               \n"
                            "           #--=------=*             \n"
                            "         #=*=-*-=--=-=*             \n"
                            "         -@-==@.+-==--=+            \n"
                            "         =#*==#*+--=+--=#           \n"
                            "         =-=---------==--=:         \n"
                            "         ==============--==:        \n"
                            "         ##@@@@@#@@*+===--=-==      \n"
                            "       ##+#@%****%@#-=*#=-:-@       \n"
                            "       %=#+==--::====-=++@==-==     \n"
                            "     #:=#+====--===--==+@@=-==      \n"
                            "     =--++++==-=::=---==+@====      \n"
                            "     @==+@+++=-===---==++@---+@     \n"
                            "     *+=@#++*++=+==--=+#@=-=-#      \n"
                            "     == #=-++#::::#=-==+ ##:=       \n"
                            "         +--=+#     #==++  =        \n"
                            "         ==-=#       +==+@          \n"
                            "         =--=#       ++==+%         \n"
                            "       #=--=+=     =+=+-===         \n"
                            "       :.:::::     =:::::.:=        \n";

  using Inimigo::Inimigo;
  void mostrar_dados_personagem()
  {
    std::cout << img_inimigo << std::endl;
    Personagem::mostrar_dados_personagem();
  }
};

class Boss : Inimigo
{
public:
  std::string img_inimigo = "                                        \n"
                            "            =+%%      +#%*==            \n"
                            "        =%*#%=       %%#%#%@-:          \n"
                            "      -#*#%%%        @#%%%##*#%=        \n"
                            "    %%*=+#*# =      %##-*:=:###%=       \n"
                            "    ###=  *%#%#%=:   #%%-=    +%##=     \n"
                            "    =###   %@%###%% =#%#:%%    *#*##    \n"
                            "    @=:+= #% %@%#%=%#%*%:+%#   ==:=:    \n"
                            "      @=#*=+@%%@##+# %*#*%# ==          \n"
                            "        %= @*@#**%##  #%= =*%           \n"
                            "      =#  %#@%##%#*%#*#   *#*           \n"
                            "      #+ *##%%#@++## %#    ##           \n"
                            "      ##  %=%##%=%=%=#%    ##+          \n"
                            "      %#  %#@##%==*==*%@  ##%%          \n"
                            "      @#-:-#%####@==*+###  =-#%         \n"
                            "      %# ++%#%=#%%###+%#%  . =%         \n"
                            "      %    %*@+**@@%%-*%%     *         \n"
                            "      #    %@@+#%%@@% *%=     :         \n"
                            "      =    @@%%@*%%%%@*%                \n"
                            "            @%#%%%#%%%=                 \n"
                            "            @%##%%+#%%.                 \n"
                            "            =#**%%**%=*                 \n"
                            "              +%%@@%+ -                 \n"
                            "              ##- **#                   \n"
                            "              +=  %#                    \n"
                            "              =   @=                    \n";

  using Inimigo::Inimigo;
  void mostrar_dados_personagem()
  {
    std::cout << img_inimigo << std::endl;
    Personagem::mostrar_dados_personagem();
  }
};
 */

bool achar_inimigo(std::list<Inimigo> &lista_inimigos, int ID)
{
    for (Inimigo inimigo : lista_inimigos)
    {
        if (inimigo.ID == ID)
        {
            return true;
        }
    }

    return false;
}

Inimigo *selecionar_inimigo(std::list<Inimigo> *lista_inimigos, int ID)
{
    Inimigo *local_ptr;
    for (Inimigo &inimigo : *lista_inimigos)
    {
        if (inimigo.ID == ID)
        {
            local_ptr = &inimigo;
        }
    }
    return local_ptr;
}

void mostrar_dados_inimigos(std::list<Inimigo> &lista_inimigos)
{
    for (Inimigo inimigo : lista_inimigos)
    {
        inimigo.mostrar_dados_personagem();
    }
}

bool verificar_inimigo_vivo(Inimigo *inimigo_escolhido)
{
    return inimigo_escolhido->esta_vivo();
}

void inicializar_espadas() {}

int main()
{
    Heroi heroi("Herói", 100, 20, 0);
    Espada espada_de_madeira("Espada de Madeira", 2);
    Armadura armadura_de_latao("Armadura de latão", 20, 2);

    Inimigo inimigo_demonio1(inimigo_demonio1.ID = 1, Inimigo::demonio, "Demônio 1", 20, 2, 0);
    Inimigo inimigo_demonio2(2, Inimigo::demonio, "Demônio 2", 20, 2, 0);
    Inimigo inimigo_demonio3(3, Inimigo::demonio, "Demônio 3", 20, 50, 0);

    Inimigo inimigo_golem1(4, Inimigo::golem, "golem 1", 40, 5, 3);
    Inimigo inimigo_golem2(5, Inimigo::golem, "golem 2", 40, 5, 3);
    Inimigo inimigo_golem3(6, Inimigo::golem, "golem 3", 40, 5, 3);

    Inimigo boss_final(0, Inimigo::boss, "Boss", 150, 30, 20);

    std::list<Inimigo> inimigos_round1({inimigo_demonio1, inimigo_demonio2, inimigo_demonio3});
    std::list<Inimigo> inimigos_round2({inimigo_golem1, inimigo_golem2, inimigo_golem3});
    std::list<Inimigo> inimigo_round3({inimigo_demonio1, boss_final, inimigo_golem1});

    while (!heroi.is_game_over())
    {
        heroi.mostrar_dados_personagem();
        mostrar_dados_inimigos(inimigos_round1);

        int escolha_ID;

        std::cout << "Quem você deseja atacar [ID]? \n> ";
        std::cin >> escolha_ID;

        while (!achar_inimigo(inimigos_round1, escolha_ID))
        {
            std::cout << "\nInimigo não encontrado!\n";
            std::cout << "Quem você deseja atacar [ID]? \n> ";
            std::cin >> escolha_ID;
        }

        transicao();
        heroi.atacar(selecionar_inimigo(&inimigos_round1, escolha_ID));
        verificar_inimigo_vivo(selecionar_inimigo(&inimigos_round1, escolha_ID));

        for (Inimigo inimigo : inimigos_round1)
        {
            inimigo.atacar(&heroi);
        }

        heroi.verificar_game_over();

        for (Inimigo inimigo : inimigos_round1)
        {
            heroi.mostrar_dados_personagem();
            mostrar_dados_inimigos(inimigos_round1);
            std::cout << "Quem você deseja atacar [ID]? \n> ";
            std::cin >> escolha_ID;

            while (!achar_inimigo(inimigos_round1, escolha_ID))
            {
                std::cout << "\nInimigo não encontrado!\n";
                std::cout << "Quem você deseja atacar [ID]? \n> ";
                std::cin >> escolha_ID;
            }
            transicao();
            heroi.atacar(selecionar_inimigo(&inimigos_round1, escolha_ID));
            verificar_inimigo_vivo(selecionar_inimigo(&inimigos_round1, escolha_ID));

            for (Inimigo inimigo : inimigos_round1)
            {
                inimigo.atacar(&heroi);
            }
        }
    }
}