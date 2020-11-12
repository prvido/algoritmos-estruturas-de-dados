#include <stdio.h>
#include <stdlib.h>

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

int notaDeCorte(int *v, int n, int k)
{
    int i, soma = 0;
    for (i = n - k; i < n; i++)
    {
        soma += v[i];
    }

    return soma / k;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int *v = (int *) malloc(sizeof(int) * n);
    lerVetor(v, n);

    insertionSort(v, n);

    int x = notaDeCorte(v, n, k);

    printf("%d\n", x);

    return 0;
}