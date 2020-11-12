#include <stdlib.h>
#include <stdio.h>

void lerVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void imprimeOrdenado(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1) printf(" %d", v[i]);
        else printf(" %d\n", v[i]);
    }
}

void imprimeDesordenado(int *v, int n, int i)
{
    for (; i < n; i++)
    {
        if (i < n - 1) printf(" %d", v[i]);
        else printf(" %d\n", v[i]);
    }
}

void insertionSort(int *vetor, int tamanho)
{
	int i, j, aux;
	for (i = 1; i < tamanho; i++)
	{
		aux = vetor[i];
		for (j = i; (j > 0)&& (aux < vetor[j - 1]); j--)
			vetor[j] = vetor[j-1];
		vetor[j] = aux;
	}
}


int main()
{
    int n;
    int quantidade = 0;
    scanf("%d", &n);

    int *v = (int *) malloc(sizeof(int) * n);
    int *m = (int *) malloc(sizeof(int) * n);

    lerVetor(v, n);

    for (int i = 0; i < n; i++)
    {
        quantidade++;
        m[i] = v[i];

        insertionSort(m, i + 1);

        printf("Sublista Ordenada:");
        imprimeOrdenado(m, i + 1);
        printf("Sublista Desordenada:");
        imprimeDesordenado(v, n, i + 1);
    }
    printf("\n");

    return 0;
}