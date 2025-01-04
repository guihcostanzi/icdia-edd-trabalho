#include <stdio.h>
#include <stdlib.h>

#include "fila_no_cabeca.c"

int main() {
    FILA fila;
    inicializarFila(&fila);

    // Insere elementos na fila
    REGISTRO reg;
    reg.chave = 1; 
    if (inserirNaFila(&fila, reg)) {
        printf("Elemento 1 inserido.\n");
    }

    reg.chave = 2; 
    if (inserirNaFila(&fila, reg)) {
        printf("Elemento 2 inserido.\n");
    }

    reg.chave = 3; 
    if (inserirNaFila(&fila, reg)) {
        printf("Elemento 3 inserido.\n");
    }

    // Exibe a fila
    exibirFila(&fila);

    // Exclui elementos da fila
    REGISTRO excluido;
    if (excluirDaFila(&fila, &excluido)) {
        printf("Elemento excluído: %d\n", excluido.chave);
    }

    // Exibe a fila após exclusão
    exibirFila(&fila);

    // Busca um elemento na fila
    TIPOCHAVE chaveBuscada = 2;
    PONT pos = buscaSeq(&fila, chaveBuscada);
    if (pos != NULL) {
        printf("Elemento encontrado: %d\n", pos->reg.chave);
    } else {
        printf("Elemento não encontrado.\n");
    }

    // Exclui até que a fila fique vazia
    while (excluirDaFila(&fila, &excluido)) {
        printf("Elemento excluído: %d\n", excluido.chave);
    }

    // Exibe a fila vazia
    exibirFila(&fila);

    // Libera a memória da fila
    destruirFila(&fila);

    return 0;
}
