#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *v, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &v[i]);
    }
}

int posicao (int *v, int tamanho, int x)
{
    int posicao = 0;

    while  (v[posicao] != x && posicao < tamanho)
        posicao++;

    int contMenor = 0, contMaior = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (v[i] <= x && i != posicao)
            contMenor++;
    }
    return contMenor;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int *) malloc(n * sizeof(int));
    lerVetor(v, n);

    int x;
    scanf("%d", &x);

    printf("%d\n",posicao(v, n, x));


    return 0;
}