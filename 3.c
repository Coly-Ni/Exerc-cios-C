#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

/* declaração das funções */
float CalculaFaturamento(float[], int);
float CalculaMediaMensal(float[], int);
int LerDadosFaturamento(float[]);

int main()
{
    float Faturamento[31];
    int diasNoMes;

    diasNoMes = LerDadosFaturamento(Faturamento);

    if (diasNoMes > 0)
    {
        /* calcula menor, maior dia e superior à média mensal */
        CalculaFaturamento(Faturamento, diasNoMes);
    }
    else
    {
        printf("Erro ao ler os dados do faturamento.\n");
    }

    return 0;
}

/* função para ler os dados do faturamento de um arquivo JSON */
int LerDadosFaturamento(float Faturamento[])
{
    FILE *file = fopen("dados.json", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = (char *)malloc(length + 1);
    fread(data, 1, length, file);
    fclose(file);

    cJSON *json = cJSON_Parse(data);
    if (json == NULL)
    {
        printf("Erro ao analisar o JSON.\n");
        free(data);
        return 0;
    }

    int i = 0;
    cJSON *dia;
    cJSON_ArrayForEach(dia, json)
    {
        cJSON *valor = cJSON_GetObjectItem(dia, "valor");
        if (cJSON_IsNumber(valor))
        {
            Faturamento[i] = valor->valuedouble;
            i++;
        }
    }

    cJSON_Delete(json);
    free(data);
    return i;
}

/* função para calcular a média mensal */
float CalculaMediaMensal(float Faturamento[], int diasNoMes)
{
    int i, diasfaturados;
    float mediamensal = 0;

    diasfaturados = 0;

    for (i = 0; i < diasNoMes; i++)
    {
        if (Faturamento[i] != 0)
        {
            diasfaturados++;
            mediamensal += Faturamento[i];
        }
    }

    if (diasfaturados > 0)
        mediamensal = mediamensal / diasfaturados;
    else
        mediamensal = 0;

    return mediamensal;
}

/* função para calcular o faturamento */
float CalculaFaturamento(float Faturamento[], int diasNoMes)
{
    int i, diasmaioresmedia, diamaior, diamenor;
    float maior, menor, mediamensal;

    diasmaioresmedia = 0;
    maior = 0;
    menor = 999999;

    mediamensal = CalculaMediaMensal(Faturamento, diasNoMes);

    for (i = 0; i < diasNoMes; i++)
    {
        if (Faturamento[i] > maior) /* maior faturamento */
        {
            maior = Faturamento[i];
            diamaior = i + 1;
        }
        if (Faturamento[i] < menor && Faturamento[i] != 0) /* menor faturamento ignorando dias sem faturamento */
        {
            menor = Faturamento[i];
            diamenor = i + 1;
        }
        if (Faturamento[i] > mediamensal) /* maiores que a média mensal */
        {
            diasmaioresmedia++;
            printf("O dia %d teve faturamento maior que a média mensal, com valor de %.2f\n", i + 1, Faturamento[i]);
        }
    }

    printf("A média mensal foi de: %.2f\n", mediamensal);
    printf("O maior faturamento foi de %.2f, no dia %d\n", maior, diamaior);
    printf("O menor faturamento foi de %.2f, no dia %d\n", menor, diamenor);

    return 0;
}
