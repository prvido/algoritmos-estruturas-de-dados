#include <stdio.h>
#include <stdlib.h>

struct Pilha
{
    int *itens;
    int topo, tamanho;
};

void iniciaPilha(struct Pilha *, int);
void empilhar(struct Pilha *, int);
void desempilhar(struct Pilha *);
void mostrarT(struct Pilha);
void mostrarB(struct Pilha);

int main()
{
    int n, x;
    scanf("%d", &n);

    char op;
    struct Pilha pilha;
    iniciaPilha(&pilha, n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &x);
            if (pilha.topo < pilha.tamanho - 1) empilhar(&pilha, x);
        }
        else if (op == 'D')
        {
            if (pilha.topo != -1) desempilhar(&pilha);
        }
        else if (op == 'T')
        {
            if (pilha.topo != -1) mostrarT(pilha);
        }
        else if (op == 'B')
        {
            if (pilha.topo != -1) mostrarB(pilha);
        }
    }
    return 0;
}

void iniciaPilha(struct Pilha *p, int n)
{
    p->itens = (int*)malloc(n * sizeof(int));
    p->topo = -1;
    p->tamanho = n;
}

void empilhar(struct Pilha *p, int x)
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
        printf("%d\n", p.itens[i]);
    }
}

void mostrarT(struct Pilha p)
{
    for (int i = p.topo; i >= 0; i--)
    {
        printf("%d\n", p.itens[i]);
    }
}