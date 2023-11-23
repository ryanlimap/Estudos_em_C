#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO 
{
    int dado;
    struct NO *prox;
}NO;

typedef struct FILA
{
    NO *ini;
    NO *fim;
}FILA;

void inicializaFila(FILA *f)
{
    f->ini = NULL;
    f->fim = NULL;
}

void enfileira(int dado, FILA *f)
{
    NO *ptr = (NO*)malloc(sizeof(FILA));
    if(ptr == NULL)
    {
        printf("Erro de alocação!.\n");
        return;
    }

    else
    {
        ptr->dado = dado;
        ptr->prox = NULL;
        if(f->ini == NULL) //verifica se é o primeiro nó da fila
        {
            f->ini = ptr;
        }
        else
        {
            f->fim->prox = ptr; //caso não seja o primeiro nó, ele aponta que o último e próximo nó é o novo nó a ser inserido
        }

        f->fim = ptr; //atualiza o nó fim para o novo nó que foi inserido
    }
}

void printfila(FILA *f)
{
    NO *ptr = f->ini;
    if(ptr != NULL)
    {
        while(ptr != NULL)
        {
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
    }
    else
    {
        printf("Fila vazia.\n");
        return;
    }
}

int main() {

    FILA *f1 = (FILA*)malloc(sizeof(FILA));
    if(f1 == NULL){
        printf("Erro na alocação.\n");
    }
    else
    {
        inicializaFila(f1);

        enfileira(10, f1);
        enfileira(20,f1);
        enfileira(30,f1);

        printfila(f1);
    }
}