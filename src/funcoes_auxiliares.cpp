#include <iostream>
#include <inimigo.h>
#include <list>
#include <funcoes_auxiliares.h>

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
        if (!inimigo.esta_vivo())
        {
            inimigo.morrer();
        }
        else
        {
            inimigo.mostrar_dados_personagem();
        }
    }
}

bool verificar_inimigo_vivo(Inimigo *inimigo_escolhido)
{
    return inimigo_escolhido->esta_vivo();
}

void inicializar_espadas() {}