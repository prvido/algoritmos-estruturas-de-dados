#include <stdio.h>
#include <stdlib.h>

struct Lista
{
    float *itens;
    int quantidade;
    int tamanho;
};

// Funções
void iniciaLista(struct Lista *, int);
void imprimirLista(struct Lista);

void inserir(struct Lista *, float);
void remover(struct Lista *, float);

int buscaBinaria(float *, int, int, float);

void deslocaDir(struct Lista*, int);
void deslocaEsq(struct Lista*, int);

int main()
{
    int n;
    float x;
    char op = 'N';
    struct Lista lista;

    scanf("%d", &n);

    iniciaLista(&lista, n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            scanf("\n%f", &x); // elemento a ser inserido
            //Inserir na Lista
            if (lista.quantidade < lista.tamanho)
                inserir(&lista, x);
        }
        else if (op == 'R')
        {
            scanf("\n%f", &x); // elemento a ser removido
            //Remover da Lista
            remover(&lista, x);
        }
        else if (op == 'B')
        {
            scanf("\n%f", &x); // elemento a ser buscado
            //Buscar valor
            if (buscaBinaria(lista.itens, 0, lista.quantidade, x) != -1) printf("SIM\n");
            else printf("NAO\n");
        }
        else if (op == 'M')
        {
            //Mostrar Lista
            imprimirLista(lista);
        }
    }

    return 0;
}

void iniciaLista(struct Lista *l, int n)
{
    l->itens = malloc(n * sizeof(float));
    l->tamanho = n;
    l->quantidade = 0;
}

void inserir (struct Lista *l, float x)
{
    if (l->quantidade == 0)
    {
        l->itens[0] = x;
        l->quantidade++;
    }
    else if (buscaBinaria(l->itens, 0, l->quantidade-1, x) == -1)
    {
        int i = 0;
        while (i < l->quantidade && l->itens[i] < x) i++;

        deslocaDir(l, i);

        l->itens[i] = x;
        l->quantidade++;
    }
}

void remover(struct Lista *l, float x)
{
    if (buscaBinaria(l->itens, 0, l->quantidade, x) != -1)
    {
        deslocaEsq(l, buscaBinaria(l->itens, 0, l->quantidade, x));
        l->quantidade--;
    }
}

int buscaBinaria (float *v, int esq, int dir, float x)
{
    int meio;
    if (esq <= dir)
    {
        meio = (esq + dir) / 2;

        if (v[meio] == x) return meio;

        else if (v[meio] > x) return buscaBinaria(v, esq, meio - 1, x);

        else return buscaBinaria(v, meio + 1, dir, x);
    }
    return -1;
}

void deslocaDir(struct Lista *l, int i)
{
    int k;
    for (k = l->quantidade - 1; k >= i; k--)
    {
        l->itens[k + 1] = l->itens[k];
    }
}

void deslocaEsq(struct Lista *l, int i)
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
        if (i == l.quantidade - 1) printf("%f\n", l.itens[i]);
        else printf("%f ", l.itens[i]);
    }
}