//Minha função strcpy, que copia os caracteres de uma string src para uma string dest
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* transferir_string(char vetor[])
{
    int tamanho = strlen(vetor); //aqui "medimos" o tamanho da string vetor
    char* destino = (char*)malloc((tamanho + 1) * sizeof(char)); //alocamos espaço para o destino do tamanho da string vetor
    strcpy(destino, vetor);
    return destino;

}

int main()
{
    char* vetor = "teste.";
    printf("src: %s\n", vetor);
    printf("dest: %s\n",transferir_string(vetor));

}