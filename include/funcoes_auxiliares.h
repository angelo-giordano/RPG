#pragma once
#include <iostream>
#include <list>
#include "inimigo.h"
#include "global.h"

class Inimigo;

void limpar_tela();

void transicao();

bool achar_inimigo(std::list<Inimigo> &lista_inimigos, int ID);

Inimigo *selecionar_inimigo(std::list<Inimigo> *lista_inimigos, int ID);

void mostrar_dados_inimigos(std::list<Inimigo> &lista_inimigos);

void mensagem_e_input(int *escolha_ID);

void encontrando_ID(std::list<Inimigo> *inimigos_round, int *escolha_ID);

bool verificar_inimigos_todos_mortos(std::list<Inimigo> *lista_inimigos);

void comeco_jogo();

void fim_round();