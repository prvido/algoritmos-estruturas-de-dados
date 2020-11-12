#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lerVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

int transform(int x)
{
    int xo;
    switch (x)
    {
        case 5:
        xo = 1;
        break;

        case 6:
        xo = 2;
        break;

        case 4:
        xo = 3;
        break;

        case 8:
        xo = 4;
        break;

        case 9:
        xo = 5;
        break;

        case 7:
        xo = 6;
        break;

        case 3:
        xo = 7;
        break;

        case 1:
        xo = 8;
        break;

        case 2:
        xo = 9;
        break;

        default:
        xo = 0;
    }
    return xo;
}

int countCasas(int x)
{
    int count = 0;
    while (x != 0)
    {
        count++;
        x = x / 10;
    }
    return count;
}

int potencia(int x, int y)
{
    int xo = 1;
    for(int i = 0; i < y; i++)
    {
        xo = xo * x;
    }
    return xo;
}

int comp(int x, int y)
{
    int xo, yo;
    int countX = countCasas(x);
    int countY = countCasas(y);

    if (countX != countY)
    {
        if (countX < countY) return 0;
        else return 1;
    }
    else
    {
        while (countX != 0)
        {

            xo = x / potencia(10, countX - 1);
            yo = y / potencia(10, countX - 1);


            if (transform(xo) > transform(yo)) return 1;
            else if (transform(xo) < transform(yo)) return 0;

            x = x % potencia(10, countX - 1);
            y = y % potencia(10, countX - 1);
            countX--;
        }
    }
    return 0;
}

void bubbleSort(int *vetor, int tamanho)
{
    int aux;

	for (int i = 0; i < tamanho; i++)
	{
		for (int j = 0; j < tamanho - 1; j++)
		{
		    if (comp(vetor[j], vetor[j + 1]))
			{
    			aux = vetor[j];
    			vetor[j] = vetor[j+1];
    			vetor[j+1] = aux;
			}
		}
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

int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int *) malloc(sizeof(int) *n);
    lerVetor(v, n);

    bubbleSort(v, n);

    imprimeVetor(v, n);

    return 0;
}