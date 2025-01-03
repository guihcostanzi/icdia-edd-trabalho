#include "lista_ligada.h"
#include "lista_ligada.c"
#include <stdio.h>

int main() {
    LISTA lista;
    inicializarLista(&lista);

    REGISTRO reg1 = {10};
    REGISTRO reg2 = {20};
    REGISTRO reg3 = {15};

    printf("Inserindo elementos...\n");
    inserirElemListaOrd(&lista, reg1);
    inserirElemListaOrd(&lista, reg2);
    inserirElemListaOrd(&lista, reg3);

    printf("Lista após inserções:\n");
    exibirLista(&lista);

    printf("Tamanho da lista: %d\n", tamanho(&lista));
    printf("Tamanho em bytes: %d\n", tamanhoEmBytes(&lista));

    // Testando alteração solicitada
    imprimirAnteriorEProximo(&lista, reg3.chave);

    printf("Removendo elemento com chave 15...\n");
    excluirElemLista(&lista, 15);

    printf("Lista após remoção:\n");
    exibirLista(&lista);

    // Testando alteração solicitada
    imprimirAnteriorEProximo(&lista, reg1.chave);

    reinicializarLista(&lista);
    printf("Lista após reinicialização:\n");
    exibirLista(&lista);

    return 0;
}