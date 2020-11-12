#include <stdio.h>
#include <stdlib.h>
#include<math.h>

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

int parent(int i)
{
    return (i - 1) / 2;
}

int esquerda(int i)
{
    return 2 * i + 1;
}

int direita(int i)
{
    return 2 * i + 2;
}

void maxheapify(int *v, int n, int i)
{
    int esq, dir, maior, aux;

    dir = esquerda(i);
    esq = direita(i);

    if(esq < n && v[esq] > v[i])
        maior = esq;
    else
        maior = i;

    if(dir < n && v[dir] > v[maior])
        maior = dir;

    if(maior != i)
    {
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;

        maxheapify(v, n, maior);
    }
}

void constroiMaxHeap (int *v, int n)
{
    for(int i = (n - 1) / 2; i >= 0; i--)
            maxheapify(v,n,i);
}

int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0) return 0;

        int *v = (int *) malloc(n * sizeof(int));

        lerVetor(v, n);

        constroiMaxHeap(v, n);

        imprimeVetor(v, n);

        free(v);
    }
    return 0;
}