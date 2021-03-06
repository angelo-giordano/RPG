#pragma once
#include <iostream>
#include <iomanip>
#include "personagem.h"
#include "espada.h"
#include "armadura.h"
#include "inimigo.h"
#include "global.h"
#include "funcoes_auxiliares.h"

class Inimigo;

class Heroi : public Personagem
{
public:
  bool espada_equipada = false;
  bool armadura_equipada = false;
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
             -*#.
)";

  Heroi(std::string nome, float hp, float atk, float def);

  void mostrar_dados_personagem();

  bool is_game_over();

  void resetar_hp();

  void resetar_atk();

  void resetar_def();

  void resetar_equip();

  void desenhar_personagem();

  void equipar_espada(Espada *espada);

  void equipar_armadura(Armadura *armadura);

  float calcular_dano(Personagem personagemDefendendo);

  void atacar(Inimigo *inimigo);

  void verificar_game_over();

  void game_over();
};
