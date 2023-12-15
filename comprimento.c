//essa função retorna o comprimento de uma lista
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listano {
    int info;
    ListaNo *prox;
} ListaNo;

typedef struct list {
    ListaNo *prim;
} Lista;

int lst_comprimento(Lista* lst) {
    int contador = 0;
    ListaNo* atual = lst->prim;

    while(atual != NULL) {
        contador++;
        atual = atual->prox;
    }

}