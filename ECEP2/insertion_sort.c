#include <stdlib.h>
#include <stdio.h>

void lerVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void imprimeVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1) printf("%d ", v[i]);
        else printf("%d\n", v[i]);
    }
}

void insertionSort(int *vetor, int tamanho)
{
	int i, j, aux, count = 0;
	for (i = 1; i < tamanho; i++)
	{
		aux = vetor[i];
		for (j = i; (j > 0) && (aux < vetor[j - 1]); j--)
		{
		    count++;
			vetor[j] = vetor[j-1];
		}
		vetor[j] = aux;
		imprimeVetor(vetor, tamanho);
	}
}


int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int *) malloc(sizeof(int) * n);

    lerVetor(v, n);

    insertionSort(v, n);

    return 0;
}