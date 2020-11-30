#pragma once
#include <iostream>
#include <list>
#include "inimigo.h"
#include "global.h"

bool achar_inimigo(std::list<Inimigo> &lista_inimigos, int ID);

Inimigo *selecionar_inimigo(std::list<Inimigo> *lista_inimigos, int ID);

void mostrar_dados_inimigos(std::list<Inimigo> &lista_inimigos);

bool verificar_inimigo_vivo(Inimigo *inimigo_escolhido);

void mensagem_e_input(int *escolha_ID);

void encontrando_ID(std::list<Inimigo> *inimigos_round, int *escolha_ID);

bool verificar_inimigos_todos_mortos(std::list<Inimigo> *lista_inimigos);

void comeco_jogo();

void fim_round();

void inicializar_espadas();