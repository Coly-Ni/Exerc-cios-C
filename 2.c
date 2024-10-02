#include <stdio.h>

/* declaração das funções */
int PertenceFibonacci(int);

int main()
{
    int numero;
    printf("Escreva um número: ");
    scanf("%d", &numero);
    PertenceFibonacci(numero);
    return 0;
}

/* funções */
int PertenceFibonacci(int numero)
{
    int a, b, c;
    b = 1;
    a = 0;

    if (numero == 0 || numero == 1)
    {
        printf("O número %d pertence à sequência de Fibonacci.\n", numero); /* pertence a sequência */
        return 0;
    }

    while (a <= numero)
    {
        if (a == numero)
        {
            printf("O número %d pertence à sequência de Fibonacci.\n", numero); /* pertence a sequência */
            return 0;
        }

        c = a + b;
        a = b;
        b = c;
    }

    printf("O número %d não pertence à sequência de Fibonacci.\n", numero); /* caso o número não pertencer a sequência */
    return 0;
}
