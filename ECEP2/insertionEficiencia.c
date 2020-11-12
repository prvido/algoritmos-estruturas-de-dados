#include <stdlib.h>
#include <stdio.h>

void lerVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

int insertionSort(int *vetor, int tamanho)
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
	}
	return count;
}


int main()
{
    int n;
    int count;
    scanf("%d", &n);

    int *v = (int *) malloc(sizeof(int) * n);

    lerVetor(v, n);

    count = insertionSort(v, n);
    printf("%d\n", count);
    return 0;
}