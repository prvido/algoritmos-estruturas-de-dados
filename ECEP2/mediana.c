#include <stdlib.h>
#include <stdio.h>

void lerVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void insertionSort(int *vetor, int tamanho)
{
	int i, j, aux;
	for (i = 1; i < tamanho; i++)
	{
		aux = vetor[i];
		for (j = i; (j > 0) && (aux < vetor[j - 1]); j--)
		{
			vetor[j] = vetor[j-1];
		}
		vetor[j] = aux;
	}
}

float mediana(int *v, int n)
{
    float mediana;
    if (n % 2 == 0)
    {
        mediana = (float)(v[(n / 2) - 1] + v[(n/2)]) / 2.0;
    }
    else
    {
        mediana = (float)v[n / 2];
    }
    return mediana;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int *) malloc(sizeof(int) * n);

    lerVetor(v, n);

    insertionSort(v, n);

    printf("%.2f\n", mediana(v, n));

    return 0;
}