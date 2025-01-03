#include "lista_ligada.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(LISTA* l) {
  l->inicio = NULL;
}

void exibirLista(LISTA* l) {
  PONT end = l->inicio;
  printf("Lista: \" ");
  while (end != NULL) {
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

int tamanho(LISTA* l) {
  PONT end = l->inicio;
  int tam = 0;
  while (end != NULL) {
    tam++;
    end = end->prox;
  }
  return tam;
}

int tamanhoEmBytes(LISTA* l) {
  return (tamanho(l) * sizeof(ELEMENTO)) + sizeof(LISTA);
}

PONT buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  PONT pos = l->inicio;
  while (pos != NULL) {
    if (pos->reg.chave == ch) return pos;
    pos = pos->prox;
  }
  return NULL;
}

PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch) {
  PONT pos = l->inicio;
  while (pos != NULL && pos->reg.chave < ch) pos = pos->prox;
  if (pos != NULL && pos->reg.chave == ch) return pos;
  return NULL;
}

PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* ant) {
  *ant = NULL;
  PONT atual = l->inicio;
  while (atual != NULL && atual->reg.chave < ch) {
    *ant = atual;
    atual = atual->prox;
  }
  if (atual != NULL && atual->reg.chave == ch) return atual;
  return NULL;
}

// Alterando essa função para ter a dupla ligação funcional
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
  PONT ant, i;
  i = buscaSeqExc(l, ch, &ant);
  if (i == NULL) return false;

  // Mudanças na lógica 

  if (ant == NULL) {
    l->inicio = i->prox;
    i->prox->ant = NULL;
  }
  else {
    ant->prox = i->prox;
    i->prox->ant = i->ant;
  }
  free(i);
  return true;
}

void reinicializarLista(LISTA* l) {
  PONT end = l->inicio;
  while (end != NULL) {
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  l->inicio = NULL;
}

// Edição feita nesta função para comportar a mudança para lista duplamente ligada
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  TIPOCHAVE ch = reg.chave;
  PONT ant, i;
  i = buscaSeqExc(l, ch, &ant);
  if (i != NULL) return false;
  i = (PONT)malloc(sizeof(ELEMENTO));
  i->reg = reg;

  // Mudanças na lógica 
  if (ant == NULL) {
    i->prox = l->inicio;
    i->ant = NULL;
    l->inicio = i;
  } else {
    i->prox = ant->prox;
    i->ant = ant;
    ant->prox = i;
  }

  return true;
}

PONT retornarPrimeiro(LISTA* l, TIPOCHAVE *ch) {
  if (l->inicio != NULL) *ch = l->inicio->reg.chave;
  return l->inicio;
}

PONT retornarUltimo(LISTA* l, TIPOCHAVE *ch) {
  PONT ultimo = l->inicio;
  if (l->inicio == NULL) return NULL;
  while (ultimo->prox != NULL) ultimo = ultimo->prox;
  *ch = ultimo->reg.chave;
  return ultimo;
}

void imprimirAnteriorEProximo(LISTA* l, TIPOCHAVE ch) {
    PONT pos = buscaSequencial(l, ch);
    if (pos == NULL) {
        printf("Elemento com chave %d não encontrado.\n", ch);
        return;
    }

    printf("Elemento encontrado: %d\n", pos->reg.chave);

    if (pos->ant != NULL) {
        printf("Anterior: %d\n", pos->ant->reg.chave);
    } else {
        printf("Anterior: NULL\n");
    }

    if (pos->prox != NULL) {
        printf("Próximo: %d\n", pos->prox->reg.chave);
    } else {
        printf("Próximo: NULL\n");
    }
}
