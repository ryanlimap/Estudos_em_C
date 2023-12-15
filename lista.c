#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Estrutura do NÓ
typedef struct NO
{
   int *info;  // Data associated with the node (in this case, a Student structure).
   struct NO *next;    // A pointer to the next node in the linked list.
   struct NO *prev;    // A pointer to the previous node in the linked list.
}NO;

//Estrutura da lista
typedef struct LISTA
{
   int count; // Number of elements in the linked list.
    NO *first; // A pointer to the first node in the linked list.
    NO *last;  // A pointer to the last node in the linked list.
}LISTA;

//Funcao para inicializar lista
void lista_create(LISTA *l)
{
    l->count = 0;
    l->first = NULL;
    l->last = NULL;
}

int ll_is_empty(NO *l)
{
    return ll_size(l) == 0;
}

//Funcao para imprimir a lista
void lista_print(LISTA *l)
{
    for(NO *p = l->first; p != NULL; p = p->next)   
    {
        printf("%d ", p->info);
    }
}


int main()
{
    LISTA *lista = (LISTA*)malloc(sizeof(LISTA));

    lista_create(lista);
    
    lista_insert(lista,10);
    lista_insert(lista,20);
    lista_insert(lista,30);
}