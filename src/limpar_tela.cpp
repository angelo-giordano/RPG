#include <iostream>
#include "limpar_tela.h"

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
