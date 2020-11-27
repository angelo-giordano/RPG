#include <iostream>
#include "transicao.h"
#include "limpar_tela.h"

void transicao()
{
    std::cout << "\nPressione ENTER para continuar!";
    std::cin.get();
    limpar_tela();
}
