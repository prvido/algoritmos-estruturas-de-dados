#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

void imprimeVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("%d\n", vetor[tamanho - 1]);
}

void troca(int *v, int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particiona(int *v, int inicio, int fim, int tamanho)
{
    int count = 0;
    int pivo = v[fim];
    int i = inicio;
    int j = inicio;
    int aux;
    while (j < fim)
    {
        if (v[j] <= pivo)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
        }
        j++;
        imprimeVetor(v, tamanho);
        count++;
    }
    aux = v[i];
    v[i] = v[fim];
    v[fim] = aux;
    return i;
}

void quickSort(int *v, int inicio, int fim, int tamanho)
{
    int pivo;
    if (fim > inicio)
    {
        pivo = particiona(v, inicio, fim, tamanho);
        imprimeVetor(v, tamanho);
        quickSort(v, inicio, pivo - 1, tamanho);
        quickSort(v, pivo + 1, fim, tamanho);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int *) malloc(n * sizeof(int));


    lerVetor(v, n);

    imprimeVetor(v, n);

    quickSort(v, 0, n - 1, n);

    imprimeVetor(v, n);

    return 0;
}