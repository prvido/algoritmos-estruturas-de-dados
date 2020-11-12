#include <stdio.h>
#include <stdlib.h>

struct Fila
{
    struct Pessoa *itens;
    int inicio, fim, tamanho, quantidade;
};

struct Pessoa
{
    int ra;
    char *nome;
};

void iniciaFila(struct Fila*, int);
void iniciaPessoa(struct Pessoa*);

struct Pessoa* criaPessoa(char *, int);

void enfileirar(struct Fila *, struct Pessoa);
int desinfileirar(struct Fila *);


int main()
{
    int n, x;
    char nome[50];
    struct Fila fila;

    scanf("%d\n", &n);

    iniciaFila(&fila, n);
    printf("%d\n", fila.fim);

    char op;

    while(scanf("%c\n", &op) != EOF)
    {
        if (op == 'I')
        {
            //Inserir
            scanf("\n%d %s", &x, nome);
            struct Pessoa pessoa;
            criaPessoa(&pessoa, nome, x);
            enfileirar(&fila, pessoa);
        }
        else if (op == 'A')
        {
            //Eliminar da Fila
            int aux = desinfileirar(&fila);
            if (aux != -1)
            {
                printf("[%d] %s\n", fila.itens[aux].ra, fila.itens[aux].nome);
            }
        }
        else if (op == 'M')
        {
            //Mostrar Fila Primeir -> Ultimo
        }
        else if (op == 'R')
        {
            // Mostrar Fila Ultimo -> Primeiro
        }
        else if (op == 'Q')
        {
            //Mostrar quantidade
        }
    }
    return 0;
}

void iniciaFila(struct Fila *f, int n)
{
    if (f->tamanho != n)
    {
        f->itens = malloc(n * sizeof(struct Pessoa));
        f->tamanho = n;
    }
    f->inicio = -1;
    f->fim = -1;
    printf("%d\n", f->fim);
    f->quantidade = 0;
}

void iniciaPessoa(struct Pessoa* p)
{
    p->nome = malloc(50 * sizeof(char));
    p->ra = -1;
}

struct Pessoa* criaPessoa(char *nome, int ra)
{
    struct Pessoa *p;
    iniciaPessoa(p);
    p->ra = ra;
    for (int i = 0; i < 50; i++)
    {
        p->nome[i] = nome[i];
    }
    return p;
}

void enfileirar(struct Fila *f, struct Pessoa p)
{
    if (f->fim != f->tamanho - 1)
    {
        if (f->inicio == -1 && f->fim == -1) f->inicio++;

        f->fim++;
        f->itens[f->fim] = p;
    }
}

int desinfileirar(struct Fila *f)
{
    int aux = -1;

    if (f->inicio != -1 && f->fim != -1)
    {
        aux = f->inicio;
        f->inicio++;
    }
    //if (checkVazia(f)) iniciaFila(f, f->tamanho);
    return aux;
}