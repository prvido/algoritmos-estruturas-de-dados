#include <stdio.h>
#include <stdlib.h>

struct Lista
{
    int *itens;
    int tamanho;
    int quantidade;
};

//Funções
void iniciaLista (struct Lista *, int n);
void inserir (struct Lista *, int);
void remover(struct Lista *, int);
int buscaBinaria(int *, int, int, int);
void deslocaDir(struct Lista *, int);
void deslocaEsq(struct Lista *, int);
void imprimirLista(struct Lista);

int main()
{
    int n, x;
    char op;
    struct Lista lista;

    scanf("%d", &n);

    iniciaLista(&lista, n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            // Inserir na lista
            scanf("\n%d", &x);
            inserir(&lista, x);
        }
        else if (op == 'R')
        {
            // Remover da Lista
            scanf("\n%d", &x);
            remover(&lista, x);
        }
        else if (op == 'B')
        {
            scanf("\n%d", &x);
            if (buscaBinaria(lista.itens, 0, lista.quantidade - 1, x) != -1)
                printf("SIM\n");
            else
                printf("NAO\n");
        }
        else if (op == 'M') imprimirLista(lista);
    }

    return 0;
}

void iniciaLista(struct Lista *l, int n)
{
    l->itens = malloc(n * sizeof(int));
    l->quantidade = 0;
    l->tamanho = n;
}

void inserir (struct Lista *l, int x)
{
    if (l->quantidade == 0)
    {
        l->itens[0] = x;
        l->quantidade++;
    }
    else if (buscaBinaria(l->itens, 0, l->quantidade - 1, x) == -1)
    {
        int i = 0;

        while (i < l->quantidade && l->itens[i] < x) i++;
        deslocaDir (l, i);

        l->itens[i] = x;
        l->quantidade++;
    }
}

void remover(struct Lista *l, int x)
{
    if (buscaBinaria(l->itens, 0, l->quantidade - 1, x) != -1)
    {
        deslocaEsq(l, buscaBinaria(l->itens, 0, l->quantidade - 1 , x));
        l->quantidade--;
    }
}

int buscaBinaria(int *v, int esq, int dir, int x)
{
	int meio;
	if(esq <= dir)
	{
		meio = (esq+dir)/2;
		if(v[meio] == x)
		{
			return meio;
		}
		else if(v[meio] > x)
		{
			return buscaBinaria(v, esq, meio-1, x);
		}
		else
		{
			return buscaBinaria(v, meio+1, dir, x);
		}
	}
	return -1;
}

void deslocaDir (struct Lista *l, int i)
{
    int k;
    for (k = l->quantidade - 1; k >= i; k--)
    {
        l->itens[k+1] = l->itens[k];
    }
}

void deslocaEsq (struct Lista *l, int i)
{
    int k;
    for (k = i; k < l->quantidade; k++)
    {
        l->itens[k] = l->itens[k+1];
    }
}
void imprimirLista(struct Lista l)
{
    for (int i = 0; i < l.quantidade; i++)
    {
        if (i == l.quantidade - 1) printf("%d\n", l.itens[i]);
        else printf("%d ", l.itens[i]);
    }
}