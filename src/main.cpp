#include <iostream>
#include <list>
#include <iomanip>
#include "global.h"
#include "limpar_tela.h"
#include "transicao.h"
#include "espada.h"
#include "armadura.h"
#include "personagem.h"
#include "heroi.h"
#include "inimigo.h"
#include "funcoes_auxiliares.h"

int main()
{
  Heroi heroi("Herói", 100, 20, 0);
  Espada espada_de_madeira("Espada de Madeira", 2);
  Armadura armadura_de_latao("Armadura de latão", 20, 2);

  Inimigo inimigo_demonio1(1, Inimigo::demonio, "Demônio 1", 20, 2, 0);
  Inimigo inimigo_demonio2(2, Inimigo::demonio, "Demônio 2", 20, 50, 0);
  Inimigo inimigo_demonio3(3, Inimigo::demonio, "Demônio 3", 20, 2, 0);

  Inimigo inimigo_golem1(4, Inimigo::golem, "golem 1", 40, 5, 3);
  Inimigo inimigo_golem2(5, Inimigo::golem, "golem 2", 40, 5, 3);
  Inimigo inimigo_golem3(6, Inimigo::golem, "golem 3", 40, 5, 3);

  Inimigo boss_final(0, Inimigo::boss, "Boss", 150, 30, 20);

  std::list<Inimigo> inimigos_round1({inimigo_demonio1, inimigo_demonio2, inimigo_demonio3});
  std::list<Inimigo> inimigos_round2({inimigo_golem1, inimigo_golem2, inimigo_golem3});
  std::list<Inimigo> inimigo_round3({inimigo_demonio1, boss_final, inimigo_golem1});

  comeco_jogo();

  while (!heroi.is_game_over())
  {
    heroi.mostrar_dados_personagem();
    mostrar_dados_inimigos(inimigos_round1);

    mensagem_e_input(&escolha_ID);
    encontrando_ID(&inimigos_round1, &escolha_ID);

    transicao();

    heroi.atacar(selecionar_inimigo(&inimigos_round1, escolha_ID));
    verificar_inimigo_vivo(selecionar_inimigo(&inimigos_round1, escolha_ID));
    if (verificar_inimigos_todos_mortos(&inimigos_round1))
    {
      fim_round();
      break;
    }

    for (Inimigo inimigo : inimigos_round1)
    {
      inimigo.atacar(&heroi);
      heroi.verificar_game_over();
    }
  }
}