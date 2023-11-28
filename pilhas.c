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
void inicializaPilha(PILHA *p) //inicializa a pilha com os campos em NULL para não dar erro
{
    p->topo = NULL;
}

//Funcao para empilhar os dados
void empilhar(int dado, PILHA *p)
{
    NO *ptr = (PILHA*)malloc(sizeof(PILHA)); //Aloca espaço dinamicamente para um no ptr 
    if(ptr == NULL)
    {
        printf("Erro de alocação"); //se esse no ptr estiver como NULL da erro de alocacao
    }
    else
    {
        ptr->dado = dado; //ptr dado recebe o dado da funcao
        ptr->prox = p->topo; //ptr prox recebe para o topo da pilha
        p->topo = ptr; //topo da pilha recebe o ptr
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

//Funcao push empilha
//Funca pop desempilha
