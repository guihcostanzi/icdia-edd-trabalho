#include <stdio.h>
#include <stdlib.h>
#define ERRO -1
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct aux {
  REGISTRO reg;
  struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
  PONT cabeca; // Aponta para o nó-cabeça
  PONT fim;    // Aponta para o último elemento válido
} FILA;

/* Inicialização da fila ligada (a fila já está criada e é apontada pelo endereço em f) */
void inicializarFila(FILA* f){
    PONT cabeca = (PONT) malloc(sizeof(ELEMENTO));
    if (cabeca == NULL) {
        // Falha na alocação de memória
        return;
    }
    cabeca->reg.chave = ERRO; // Valor indicando que é um nó-cabeça
    cabeca->prox = NULL;
    f->cabeca = cabeca;
    f->fim = cabeca;
} /* inicializarFila */

/* Retornar o tamanho da fila (número de elementos válidos) */
int tamanho(FILA* f) {
    PONT end = f->cabeca->prox; // Ignora o nó-cabeça
    int tam = 0;
    while (end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
} /* tamanho */

/* Retornar o tamanho em bytes da fila */
int tamanhoEmBytes(FILA* f) {
    return (tamanho(f) * sizeof(ELEMENTO)) + sizeof(FILA);
} /* tamanhoEmBytes */

/* Destruição da fila - libera a memória de todos os elementos válidos da fila */
void destruirFila(FILA* f) {
    PONT end = f->cabeca->prox; // Ignora o nó-cabeça
    while (end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->cabeca->prox = NULL;
    f->fim = f->cabeca;
} /* destruirFila */

/* retornarPrimeiro - retorna o endereço do primeiro elemento válido da fila e, caso não esteja vazia, retorna a chave desse elemento na memória apontada pelo ponteiro ch */
PONT retornarPrimeiro(FILA* f, TIPOCHAVE *ch){
    if (f->cabeca->prox != NULL) {
        *ch = f->cabeca->prox->reg.chave;
        return f->cabeca->prox;
    }
    return NULL;
} /* retornarPrimeiro */

/* retornarUltimo - retorna o endereço do último elemento válido da fila e, caso não esteja vazia, retorna a chave desse elemento na memória apontada pelo ponteiro ch */
PONT retornarUltimo(FILA* f, TIPOCHAVE* ch){
    if (f->fim != f->cabeca) { // Verifica se há elementos válidos além do nó-cabeça
        *ch = f->fim->reg.chave;
        return f->fim;
    }
    return NULL;
} /* retornarUltimo */

/* Inserção no fim da fila */
bool inserirNaFila(FILA* f, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) {
        return false;
    }
    novo->reg = reg;
    novo->prox = NULL;

    if (f->cabeca->prox == NULL) {
        // A fila está vazia (após o nó-cabeça), o novo elemento se torna o início e o fim
        f->cabeca->prox = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return true;
} /* inserirNaFila */

/* Exclusão do início da fila */
bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->cabeca->prox == NULL) {
        return false; // A fila está vazia (após o nó-cabeça)
    }
    
    *reg = f->cabeca->prox->reg;
    PONT apagar = f->cabeca->prox;
    f->cabeca->prox = apagar->prox;
    free(apagar);

    if (f->cabeca->prox == NULL) {
        f->fim = f->cabeca;
    }
    return true;
} /* excluirDaFila */

/* Exibição da fila sequencial, ignorando o nó-cabeça */
void exibirFila(FILA* f){
    PONT end = f->cabeca->prox; // Ignora o nó-cabeça
    printf("Fila: \"");
    while (end != NULL){
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
} /* exibirFila */

/* Busca sequencial, ignorando o nó-cabeça */
PONT buscaSeq(FILA* f, TIPOCHAVE ch){
    PONT pos = f->cabeca->prox; // Ignora o nó-cabeça
    while (pos != NULL){
        if (pos->reg.chave == ch) return pos;
        pos = pos->prox;
    }
    return NULL;
} /* buscaSeq */
