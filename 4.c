#include <stdio.h>

/* declaração das funções */
float Faturamentototal(int Nestados, float faturamento[]);
void Percentualestados(const char *estados[], float faturamento[], int Nestados);

int main()
{
    float faturamento[] = {67836.43, 36678.66, 29229.88, 27165.48, 19849.53};
    const char *estados[] = {"SP", "RJ", "MG", "ES", "Outros"};
    int Nestados = 5; /* Número de estados */

    /* chamada da função para calcular e exibir os percentuais */
    Percentualestados(estados, faturamento, Nestados);
    
    return 0;
}

/* função para calcular o faturamento total */
float Faturamentototal(int Nestados, float faturamento[])
{
    float total = 0;
    for (int i = 0; i < Nestados; i++) {
        total += faturamento[i];
    }
    return total;
}

/* função para calcular os percentuais de cada estado */
void Percentualestados(const char *estados[], float faturamento[], int Nestados)
{
    int i;
    float percentual;
    float totalfaturamento = Faturamentototal(Nestados, faturamento);
    
    for ( i = 0; i < Nestados; i++) {
        percentual = (faturamento[i] / totalfaturamento) * 100;
        printf("%s: %.2f%%\n", estados[i], percentual);
    }
}
