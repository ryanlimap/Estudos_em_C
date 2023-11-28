#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Estrutura do Nó
typedef struct NO
{
    int dado;
    struct NO *prox;
}NO;

//Estrutura da Pilha
typedef struct PILHA
{
    NO *topo;
}PILHA;

//Funcao para inicializar a pilha
void inicializaPilha(PILHA *p)
{
    p->topo = NULL;
}

//Funcao para empilhar os dados
void empilhar(int dado, PILHA *p)
{
    NO *ptr = (PILHA*)malloc(sizeof(PILHA));
    if(ptr == NULL)
    {
        printf("Erro de alocação");
    }
    else
    {
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}

//Funcao para imprimir a pilha
void imprimePilha(PILHA *p)
{   
    NO *ptr = p->topo;
    if(ptr == NULL)
    {
        printf("Pilha vazia");
        return;
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }
}

//main
int main(){
    PILHA *p1 = (PILHA*)malloc(sizeof(PILHA));
    if(p1 == NULL)
    {
        printf("Erro de alocação de pilha\n");
    }
    else
    {
        inicializaPilha(p1);

        empilhar(10,p1);
        empilhar(20,p1);
        empilhar(30,p1);

        imprimePilha(p1);

    }
}

