#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lerVetor(int *v, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &v[i]);
    }
}

void imprimeVetor(int *v, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[tamanho - 1]);
}

void merge(int *v, int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *)malloc(sizeof(int) * tamanho);

    if (temp != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2) // se fim1 e fim2 são iguais a zero
            {
                if (v[p1] < v[p2])
                {
                    temp[i] = v[p1];
                    p1++;
                }
                else
                {
                    temp[i] = v[p2];
                    p2++;
                }

                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            }
            else
            {
                if (!fim1) // se o fim for igual a
                {
                    temp[i] = v[p1];
                    p1++;
                }
                else
                {
                    temp[i] = v[p2];
                    p2++;
                }
            }
        }
        for (j = 0, k = inicio; j < tamanho ; j++, k++)
            v[k] = temp[j];
    }
    free(temp);
}

void mergeSort (int *V, int inicio, int fim, int tamanho)
{
    int meio;
    if (inicio < fim)
    {
        meio = floor((inicio + fim)/2);
        mergeSort(V, inicio, meio, tamanho); // quebra a primeira metade em varios pedaçoes
        mergeSort(V, meio + 1, fim, tamanho); // quebra a segunda metade em varios pedaçoes
        imprimeVetor(V, tamanho);
        merge(V, inicio, meio, fim); // intercala
    }
}


int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int *)malloc(sizeof(int) * n);
    lerVetor(v, n);

    imprimeVetor(v, n);

    mergeSort(v, 0, n - 1, n);

    imprimeVetor(v, n);

    return 0;
}