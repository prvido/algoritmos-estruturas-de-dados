#include <stdio.h>
#include <stdlib.h>

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

void criaHeap(int *v, int pai, int fim)
{
    int aux = v[pai];
    int filho = 2 * pai + 1;

    while (filho <= fim)
    {
        if (filho < fim)
        {
            if (v[filho] < v[filho + 1])
                filho++;
        }
        if (aux < v[filho])
        {
            v[pai] = v[filho];
            pai = filho;
            filho = 2 * pai + 1;
        }
        else
        {
            filho = fim + 1;
        }
    }
    v[pai] = aux;
}

void heapSort(int * v, int n)
{
    int i, aux;
    for (i = (n - 1) / 2; i >= 0; i--)
    {
        criaHeap(v, i, n -1);
    }
    for (i = n - 1; i >= 0; i--)
    {
        imprimeVetor(v, i + 1);
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaHeap(v, 0, i - 1);
    }
}

int main()
{
    int n;
    int *v = (int *) malloc(n * sizeof(int));

    scanf("%d", &n);

    lerVetor(v, n);

    imprimeVetor(v, n);

    heapSort(v, n);

    imprimeVetor(v, n);

    return 0;
}