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

void inicializaFila(FILA *f) //inicializa os campos da fila como nulos para não dar erro
{
    f->ini = NULL;
    f->fim = NULL;
}

void enfileira(int dado, FILA *f) //função pra enfileirar
{
    NO *ptr = (NO*)malloc(sizeof(FILA)); //aloca dinâmicamente memória pra um nó ptr
    if(ptr == NULL) //se esse nó estiver nulo quer dizer que alocação não foi feita corretamente
    {
        printf("Erro de alocação!.\n");
        return;
    }

    else
    {
        ptr->dado = dado; //o dado do nó ptr recebe o dado que a função recebe
        ptr->prox = NULL; //e o próximo nó do ptr é dado como nulo (como se os nó estivessem 1 (exemplo) e dps nulo)
        if(f->ini == NULL) //verifica se é o primeiro nó da fila
        {
            f->ini = ptr; //aqui adiciona o ptr como primeiro item da fila
        }
        else //se não
        {
            f->fim->prox = ptr; //caso não seja o primeiro nó, ele aponta que o último nó é o ptr (não é literalmente o último da fila aqui e sim "o próximo depois do que tava antes")
        }

        f->fim = ptr; //atualiza o final da fila pra ser o ptr
    }
}

void printfila(FILA *f)
{
    NO *ptr = f->ini; //define o ptr como o primeiro (dado e proximo) da fila
    if(ptr != NULL) 
    {
        while(ptr != NULL) //enquanto o ptr for diferente de nulo
        {
            printf("%d ", ptr->dado); //printa o dado
            ptr = ptr->prox; //ptr recebe o proximo dado
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