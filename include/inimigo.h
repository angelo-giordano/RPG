#pragma once
#include "personagem.h"
#include "heroi.h"
#include "global.h"
#include "funcoes_auxiliares.h"

class Heroi;

class Inimigo : public Personagem
{
public:
  enum tipo_inimigo
  {
    demonio,
    golem,
    boss
  };

  int ID;
  int acompanhar_tentativas_ataque_morto = 0;
  bool vivo = true;
  tipo_inimigo tipo_do_inimigo;
  std::string img_inimigo = "";
  std::string nome;
  float hp;
  float atk;
  float def;

  Inimigo(int ID, tipo_inimigo tipo_do_inimigo, std::string nome, float hp, float atk, float def);

  void mostrar_dados_personagem();

  void desenhar_personagem();

  bool esta_vivo();

  float calcular_dano(Heroi heroi);

  void atacar(Heroi *heroi);

  void morrer();
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
