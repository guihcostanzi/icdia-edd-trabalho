#include "pilha_estatica.h"
#include "pilha_estatica.c"
#include <stdio.h>

int main() {

    REGISTRO reg;

    PILHA pilha;
    inicializarPilha(&pilha);

    // Inserindo elemento na pilha (base de teste)
    reg.chave = 1;
    inserirElementoPilha(&pilha, reg);
    reg.chave = 2;
    inserirElementoPilha(&pilha, reg);
    reg.chave = 3;
    inserirElementoPilha(&pilha, reg);

    // Tentando imprimir a função implementada
    exibirPilhaInvertida(&pilha);

    // Difereça para função já existente
    exibirPilha(&pilha);

    return 0;
}