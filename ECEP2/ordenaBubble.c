#include <stdio.h>
#include <stdlib.h>

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

void bubbleSort(int *vetor, int tamanho)
{
    int trocas = 0;
    int aux;
    imprimeVetor(vetor, tamanho);

	for (int i = 0; i < tamanho; i++)
	{
		for (int j = 0; j < tamanho - 1; j++)
		{
			if (vetor[j] > vetor[j+1])
			{
			aux = vetor[j];
			vetor[j] = vetor[j+1];
			vetor[j+1] = aux;

			trocas++;
			imprimeVetor(vetor, tamanho);

			}
		}
	}
	imprimeVetor(vetor, tamanho);
	printf("Trocas: %d\n", trocas);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int * ) malloc(sizeof(int) * n);

    lerVetor(v, n);

    bubbleSort(v, n);

    return 0;
}