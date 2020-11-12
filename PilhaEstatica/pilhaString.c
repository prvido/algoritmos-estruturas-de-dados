#include <stdio.h>
#include <stdlib.h>

struct Pilha
{
    char **itens;
    int topo, tamanho;
};

void iniciaPilha(struct Pilha *, int);
void empilhar(struct Pilha *, char *);
void desempilhar(struct Pilha *);
void mostrarT(struct Pilha);
void mostrarB(struct Pilha);

int main()
{
    int n;
    char x[100];
    scanf("%d", &n);

    char op;
    struct Pilha pilha;
    iniciaPilha(&pilha, n);

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("\n%s", x);
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
            if (pilha.topo != -1) printf("%s\n", pilha.itens[pilha.topo]);
        }
    }
    return 0;
}

void iniciaPilha(struct Pilha *p, int n)
{
    p->itens = (char**) malloc(n * 100 * sizeof(char));
    p->topo = -1;
    p->tamanho = n;
}

void empilhar(struct Pilha *p, char *x)
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
            printf("%s\n", p.itens[i]);
        else
            printf("%s ", p.itens[i]);
    }
}

void mostrarT(struct Pilha p)
{
    for (int i = p.topo; i >= 0; i--)
    {
        if (i == 0)
            printf("%s\n", p.itens[i]);
        else
            printf("%s ", p.itens[i]);
    }
}