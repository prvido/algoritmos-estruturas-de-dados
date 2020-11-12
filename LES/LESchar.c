#include <stdio.h>
#include <stdlib.h>

struct Lista
{
    char *chaves;
    int tamanho;
    int quantidade;
};

void iniciarLista(struct Lista*, int);
void inserir(struct Lista*, char);
void remover(struct Lista*, char);
int buscaBinaria(char *, int, int, char);
void deslocarDir(struct Lista*, int);
void deslocaEsq(struct Lista *, int);
void imprimirLista(struct Lista);

int main()
{
    int n;
    char op, x;

    scanf("%d", &n);

    struct Lista lista;
    iniciarLista(&lista, n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            // Inserir
            scanf("\n%c", &x);
            inserir(&lista, x);

        }
        else if (op == 'R')
        {
            // Remover
            scanf("\n%c", &x);
            remover(&lista, x);
        }
        else if (op == 'B')
        {
            // Buscar
            scanf("\n%c", &x);
            if (buscaBinaria(lista.chaves, 0, lista.quantidade - 1, x) != -1)
                printf("SIM\n");
            else printf("NAO\n");
        }
        else if (op == 'M')
        {
            imprimirLista(lista);
        }
    }
    return 0;
}

void iniciarLista(struct Lista *l, int n)
{
    l->chaves = malloc(n * sizeof(char));
    l->tamanho = n;
    l->quantidade = 0;
}

void inserir(struct Lista *l, char x)
{
    if (l->quantidade == 0)
    {
        l->chaves[0] = x;
        l->quantidade++;
    }
    else if (buscaBinaria(l->chaves, 0, l->quantidade, x) == -1)
    {
        int i = 0;

        while (i < l->quantidade && l->chaves[i] < x) i++;

        deslocarDir(l, i);

        l->chaves[i] = x;
        l->quantidade++;
    }
}

void remover(struct Lista *l, char x)
{
    int i = 0;
    if (buscaBinaria(l->chaves, 0, l->quantidade - 1, x) != -1)
    {
        while (i < l->quantidade && l->chaves[i] != x)
            i++;
        deslocaEsq(l, i);
        l->quantidade --;
    }
}

int buscaBinaria(char *v, int esq, int dir, char x)
{
    int meio;
    if (esq <= dir)
    {
        meio = (esq + dir) / 2;
        if (v[meio] == x)
        {
            return meio;
        }
        else if (v[meio] > x)
        {
            return buscaBinaria (v, esq, meio - 1, x);
        }
        else
        {
            return buscaBinaria (v, meio + 1, dir, x);
        }
    }

    return -1;
}

void deslocarDir(struct Lista *l, int i)
{
    int k;
    for (k = l->quantidade - 1; k >= i; k--)
    {
        l->chaves[k+1] = l->chaves[k];
    }
}

void deslocaEsq(struct Lista *l, int i)
{
    int k;
    for (int k = i; k <= l->quantidade; k++)
    {
        l->chaves[k] = l->chaves[k+1];
    }
}

void imprimirLista (struct Lista l)
{
    for (int i = 0; i < l.quantidade; i++)
    {
        if (i == l.quantidade - 1) printf("%c\n", l.chaves[i]);
        else printf("%c ", l.chaves[i]);
    }
}