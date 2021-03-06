#include <iostream>
#include <list>
#include <iomanip>
#include "global.h"
#include "espada.h"
#include "armadura.h"
#include "personagem.h"
#include "heroi.h"
#include "inimigo.h"
#include "funcoes_auxiliares.h"

int main()
{
    Heroi heroi("Herói", 100, 15, 0);

    Espada espada_de_madeira("Espada de Madeira", 5);
    Espada espada_de_ferro("Espada de Ferro", 15);
    Espada excalibur("Excalibur", 100);

    Armadura armadura_de_latao("Armadura de Latão", 25, 2);
    Armadura armadura_de_ferro("Armadura de Ferro", 50, 5);
    Armadura armadura_de_escamas_dragao("Armadura de Escamas de Dragão", 100, 10);

    Inimigo inimigo_demonio1(1, Inimigo::demonio, "Demônio 1", 30, 4, 0);
    Inimigo inimigo_demonio2(2, Inimigo::demonio, "Demônio 2", 30, 4, 0);
    Inimigo inimigo_demonio3(3, Inimigo::demonio, "Demônio 3", 30, 4, 0);

    Inimigo inimigo_golem1(1, Inimigo::golem, "Golem 1", 50, 8, 3);
    Inimigo inimigo_golem2(2, Inimigo::golem, "Golem 2", 50, 8, 3);
    Inimigo inimigo_golem3(3, Inimigo::golem, "Golem 3", 50, 8, 3);

    Inimigo inimigo_demonio_final(1, Inimigo::demonio, "Demônio 1", 30, 4, 0);
    Inimigo boss_final(2, Inimigo::boss, "Boss", 150, 20, 15);
    Inimigo inimigo_golem_final(3, Inimigo::golem, "Golem 3", 50, 8, 3);

    std::list<Inimigo> inimigos_round1({inimigo_demonio1, inimigo_demonio2, inimigo_demonio3});
    std::list<Inimigo> inimigos_round2({inimigo_golem1, inimigo_golem2, inimigo_golem3});
    std::list<Inimigo> inimigos_round3({inimigo_demonio_final, boss_final, inimigo_golem_final});

    comeco_jogo();

    round(&heroi, &inimigos_round1, &espada_de_madeira, &armadura_de_latao);
    round(&heroi, &inimigos_round2, &espada_de_ferro, &armadura_de_ferro);
    round(&heroi, &inimigos_round3, &excalibur, &armadura_de_escamas_dragao);

    fim_jogo();
}
