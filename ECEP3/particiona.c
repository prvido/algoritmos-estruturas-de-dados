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
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\n", v[i]);
    }
}

void particiona(int *v, int inicio, int fim, int p)
{
    int aux = v[fim];
    v[fim] = v[p];
    v[p] = aux;
    int pivo = v[fim];
    int i = inicio;
    int j = inicio;

    while (j < fim)
    {
        if (v[j] < pivo)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
        }
        j++;
    }
    aux = v[i];
    v[i] = v[fim];
    v[fim] = aux;
}

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);

    int *v = (int *) malloc(n * sizeof(int));

    lerVetor(v, n);

    particiona(v, 0, n - 1, p);

    imprimeVetor(v, n);

    return 0;
}