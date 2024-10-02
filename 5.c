#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], temp;
    int i, j, length;

    printf("Digite uma string:");
    scanf("%s", str);

    /*comprimento da string*/
    length = strlen(str);

    /*inverte a string*/
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        /*troca os caracteres*/
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("String invertida: %s\n", str);

    return 0;
}
