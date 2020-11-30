#include <iostream>
#include <list>
#include "inimigo.h"
#include "funcoes_auxiliares.h"
#include "global.h"

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

void mensagem_e_input(int *escolha_ID)
{
    std::cout << "Quem você deseja atacar [ID]? \n> ";
    std::cin >> *escolha_ID;
}

void encontrando_ID(std::list<Inimigo> *inimigos_round, int *escolha_ID)
{

    while (!achar_inimigo(*inimigos_round, *escolha_ID))
    {
        std::cout << "\nInimigo não encontrado!\n";
        mensagem_e_input(escolha_ID);
    }
}

bool verificar_inimigos_todos_mortos(std::list<Inimigo> *lista_inimigos)
{
    std::list<Inimigo>::iterator it_inimigo1 = lista_inimigos->begin();
    bool inimigo1_estado = lista_inimigos->begin()->esta_vivo();

    std::list<Inimigo>::iterator it_inimigo2 = std::next(lista_inimigos->begin());
    bool inimigo2_estado = it_inimigo2->esta_vivo();

    bool inimigo3_estado = lista_inimigos->back().esta_vivo();

    return !inimigo1_estado && !inimigo2_estado && !inimigo3_estado;
}

void comeco_jogo()
{
    std::cout << R"(
                    8888888b.  8888888b.   .d8888b.
                    888   Y88b 888   Y88b d88P  Y88b
                    888    888 888    888 888    888
                    888   d88P 888   d88P 888
                    8888888P"  8888888P"  888  88888
                    888 T88b   888        888    888
                    888  T88b  888        Y88b  d88P
                    888   T88b 888         "Y8888P88


                    Pressione ENTER para começar o jogo!!
)";

    std::cin.get();
    limpar_tela();
}

void fim_round()
{
    std::cout << R"(
                      |  /                          _/_          _/_       /                   o       o         o
                      | /   __ _, _    _ _ _   __,  /   __ , ,   /   __ __/  __ (     __ (    ,  _ _  ,  _ _ _  ,  _,  __ (
                      |/   (_)(__(/_  / / / /_(_/(_(__ (_)(_/_  (__ (_)(_/_ (_)/_)_  (_)/_)_  (_/ / /_(_/ / / /_(_(_)_(_)/_)_o
                                                                                               /|
                                                                                              (/
                                         _ __
                                        ( /  )                /                 /   /   /   /
                                         /--'  __,  _   __,  /   _  _ _   (    /   /   /   /
                                        /     (_/(_/ (_(_/(_/_) (/_/ / /_/_)_ '   '   '   '
                                                                             o   o   o   o
)";

    std::cin.get();
}

void inicializar_espadas() {}