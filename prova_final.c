#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//questão 3
//mede comprimento de uma lista
typedef struct listano {
    int info;
    ListaNo *prox;
} ListaNo;

typedef struct lista {
    ListaNo *prim;
} Lista;

int lst_comprimento(Lista* lst) {
    int contador = 0;
    ListaNo* atual = lst->prim;

    while(atual != NULL) {
        contador++;
        atual = atual->prox;
    }

    return contador;
}

//questão 4
typedef struct conjunto {
    Lista* elems;
} Conjunto;

//cria um conjunto vazio inicializando a(s) estrutura(s) internas;
Conjunto* conj_cria(){
    Conjunto* novo_conjunto = (Conjunto*)malloc(sizeof(Conjunto));
    novo_conjunto->elems = (Lista*)malloc(sizeof(Lista));
    novo_conjunto->elems->prim = NULL;
    return novo_conjunto;
}

//verifica se elems pertence ao conjunto c
int pertence(Conjunto* c,int elem) {
    int lst_pertence(c->elems,elem);
}

//une dois conjuntos
Conjunto* conjunto_uniao(Conjunto* c1, Conjunto* c2) {
    atual = c1->elems->prim;
    Conjunto* new_conj = conj_cria();

    while(atual != NULL) {
        lst_insere(new_conj->elems, atual->info)
        atual = atual->prox;
    }

    atual = c2->elems->prim;

    while(atual != NULL) {
        lst_insere(new_conj, atual->info);
        atual = atual->prox;
    }

    return new_conj;

}