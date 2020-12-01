#include <iostream>
#include <list>
#include "inimigo.h"
#include "funcoes_auxiliares.h"
#include "global.h"

void limpar_tela()
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "Não suportado"
#endif
}

void transicao()
{
    std::cout << "\n\nPressione ENTER para continuar!";
    std::cin.get();
    limpar_tela();
}

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

void drop_espada(Heroi *heroi, Inimigo *inimigo, Espada *espada)
{
    if (!inimigo->esta_vivo() && inimigo->acompanhar_tentativas_ataque_morto == 0)
    {
        if (heroi->espada_equipada)
        {
            std::cout << "Você já possui a " << espada->nome << " equipada!";
            transicao();
        }
        else
        {
            std::cout << inimigo->nome << " dropou " << espada->nome << std::endl;
            heroi->equipar_espada(espada);
        }
    }
}

void drop_armadura(Heroi *heroi, Inimigo *inimigo, Armadura *armadura)
{
    if (!inimigo->esta_vivo() && inimigo->acompanhar_tentativas_ataque_morto == 0)
    {
        if (heroi->armadura_equipada)
        {
            std::cout << "Você já possui a " << armadura->nome << " equipada!";
            transicao();
        }
        else
        {
            std::cout << inimigo->nome << " dropou " << armadura->nome << std::endl;
            heroi->equipar_armadura(armadura);
        }
    }
}

void drop(Heroi *heroi, Inimigo *inimigo, Espada *espada, Armadura *armadura)
{
    srand(time(0));
    bool chance_espada = rand() % 100 <= 50;
    bool chance_armadura = rand() % 100 >= 51;

    if (!inimigo->esta_vivo() && inimigo->acompanhar_tentativas_ataque_morto == 0)
    {
        if (retorna_chance())
        {
            if (chance_armadura)
            {
                drop_armadura(heroi, inimigo, armadura);
            }
            else if (chance_espada)
            {
                drop_espada(heroi, inimigo, espada);
            }
        }
    }
}

void comeco_jogo()
{
    limpar_tela();
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

void round(Heroi *heroi, std::list<Inimigo> *lista_inimigos_round, Espada *espada_round, Armadura *armadura_round)
{
    heroi->resetar_equip();
    while (!heroi->is_game_over())
    {
        heroi->mostrar_dados_personagem();
        mostrar_dados_inimigos(*lista_inimigos_round);

        mensagem_e_input(&escolha_ID);
        encontrando_ID(lista_inimigos_round, &escolha_ID);

        transicao();

        heroi->atacar(selecionar_inimigo(lista_inimigos_round, escolha_ID));
        drop(heroi, selecionar_inimigo(lista_inimigos_round, escolha_ID), espada_round, armadura_round);

        if (verificar_inimigos_todos_mortos(lista_inimigos_round))
        {
            fim_round();
            break;
        }

        for (Inimigo inimigo : *lista_inimigos_round)
        {
            inimigo.atacar(heroi);
            heroi->verificar_game_over();
        }
    }
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
    limpar_tela();
}

int retorna_chance()
{
    srand(time(0));
    bool chance_drop = (std::rand() % 100) <= 50;
    return chance_drop;
}