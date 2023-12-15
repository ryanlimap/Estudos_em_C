//aqui é a mesma coisa do arquivo strcpy.c, porém, agora não podemos usar a função strcpy, apenas a strlen!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stringcpy(char *dest, const char *src)
{
    int tamanho = strlen(src);
    for(int i = 0; i <= (tamanho); i++)
    {
        dest[i] = src[i];
    }
    return dest;

}

int main()
{
    const char *src = "teste";
    printf("src: %s", src);
    char *dest = "a";
    printf("dest: %s", stringcpy(dest, src));
}