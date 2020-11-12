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

void selectionSort(int *vetor, int tamanho)
{
	int i, j, menor, troca, count = 0;
	imprimeVetor(vetor, tamanho);
	for (i = 0; i < tamanho - 1; i++)
	{
		menor = i;
		for (j = i + 1; j < tamanho; j++)
		{
			if (vetor[j] < vetor[menor])
			{
			    count++;
				menor = j;
			}
		}
		if (i != menor)
		{
			troca = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = troca;
		}
		imprimeVetor(vetor, tamanho);
    }
	imprimeVetor(vetor, tamanho);
	printf("%d\n", count);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int * ) malloc(sizeof(int) * n);

    lerVetor(v, n);

    selectionSort(v, n);

    return 0;
}