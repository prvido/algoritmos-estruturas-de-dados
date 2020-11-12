#include <stdio.h>
#include <stdlib.h>

struct Fila // Estrutura da Fila
{
    int *itens;
    int inicio, fim, tamanho;
};

void iniciaFila (struct Fila*, int);
void inserir(struct Fila *, int);
int remover(struct Fila *);
int checkVazia(struct Fila *);

int main()
{
    int n, x;
    scanf("%d", &n);

    struct Fila fila;
    iniciaFila(&fila, n);

    char op;
    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            // Inserir
            scanf("%d", &x);
            inserir(&fila, x);
        }
        else if (op == 'D')
        {
            // Remover
            if (fila.inicio != -1)
            {
                printf("%d\n", fila.itens[remover(&fila)]);
            }
            else printf("Runtime Error: Fila Vazia.\n");
        }
    }

    return 0;
}

void iniciaFila (struct Fila *f, int n)
{
    if (f->tamanho != n)
    {
    f->itens = malloc(sizeof(int) * n);
    f->tamanho = n;
    }

    f->inicio = -1;
    f->fim = -1;
}

void inserir(struct Fila *f, int x)
{
    if (f->fim != f->tamanho - 1)
    {
        if (f->inicio == -1 && f->fim == -1) f->inicio++;

        f->fim++;
        f->itens[f->fim] = x;
    }
    else printf("Runtime Error: Fila Cheia.\n");
}

int remover(struct Fila *f)
{
    int aux = -1;
    if (f->inicio != -1 && f->fim != -1)
    {
        aux = f->inicio;
        f->inicio++;
    }
    if (checkVazia(f)) iniciaFila(f, f->tamanho);
    return aux;
}

int checkVazia(struct Fila *f)
{
    if (f->inicio != -1 && f->inicio > f->fim) return 1;

    return 0;
}