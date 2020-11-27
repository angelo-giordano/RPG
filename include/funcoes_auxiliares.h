#pragma once
#include <iostream>
#include <inimigo.h>
#include <list>

bool achar_inimigo(std::list<Inimigo> &lista_inimigos, int ID);

Inimigo *selecionar_inimigo(std::list<Inimigo> *lista_inimigos, int ID);

void mostrar_dados_inimigos(std::list<Inimigo> &lista_inimigos);

bool verificar_inimigo_vivo(Inimigo *inimigo_escolhido);

void inicializar_espadas();