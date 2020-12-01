#pragma once
#include <iostream>
#include <list>
#include "inimigo.h"
#include "heroi.h"
#include "global.h"

class Inimigo;
class Heroi;

void limpar_tela();

void transicao();

bool achar_inimigo(std::list<Inimigo> &lista_inimigos, int ID);

Inimigo *selecionar_inimigo(std::list<Inimigo> *lista_inimigos, int ID);

void mostrar_dados_inimigos(std::list<Inimigo> &lista_inimigos);

void mensagem_e_input(int *escolha_ID);

void encontrando_ID(std::list<Inimigo> *inimigos_round, int *escolha_ID);

bool verificar_inimigos_todos_mortos(std::list<Inimigo> *lista_inimigos);

void drop_espada(Heroi *heroi, Inimigo *inimigo, Espada *espada);

void drop_armadura(Heroi *heroi, Inimigo *inimigo, Armadura *armadura);

void comeco_jogo();

void round(Heroi *heroi, std::list<Inimigo> *lista_inimigos_round, Espada *espada_round, Armadura *armadura_round);

void fim_round();

int retorna_chance();