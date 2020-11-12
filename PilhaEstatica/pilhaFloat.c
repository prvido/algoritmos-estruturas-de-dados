#include <stdio.h>
#include <stdlib.h>

struct Pilha
{
    double *itens;
    int topo, tamanho;
};

void iniciaPilha(struct Pilha *, int);
void empilhar(struct Pilha *, double);
void desempilhar(struct Pilha *);
void mostrarT(struct Pilha);
void mostrarB(struct Pilha);

int main()
{
    int n;
    double x;
    scanf("%d", &n);

    char op;
    struct Pilha pilha;
    iniciaPilha(&pilha, n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%lf", &x);
            if (pilha.topo < pilha.tamanho - 1) empilhar(&pilha, x);
        }
        else if (op == 'D')
        {
            if (pilha.topo != -1) desempilhar(&pilha);
        }
        else if (op == 'X')
        {
            if (pilha.topo != -1) mostrarT(pilha);
        }
        else if (op == 'B')
        {
            if (pilha.topo != -1) mostrarB(pilha);
        }
        else if (op == 'T')
        {
            if (pilha.topo != -1) printf("%.1lf\n", pilha.itens[pilha.topo]);
        }
    }
    return 0;
}

void iniciaPilha(struct Pilha *p, int n)
{
    p->itens = (double*)malloc(n * sizeof(double));
    p->topo = -1;
    p->tamanho = n;
}

void empilhar(struct Pilha *p, double x)
{
    p->topo++;
    p->itens[p->topo] = x;
}

void desempilhar(struct Pilha *p)
{
    p->topo--;
}

void mostrarB(struct Pilha p)
{
    for (int i = 0; i <= p.topo; i++)
    {
        if (i == p.topo)
        {
            printf("%.1lf\n", p.itens[i]);
        }
        else
        {
            printf("%.1lf ", p.itens[i]);
        }
    }
}

void mostrarT(struct Pilha p)
{
    for (int i = p.topo; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%.1lf\n", p.itens[i]);
        }
        else
        {
            printf("%.1lf ", p.itens[i]);
        }
    }
}