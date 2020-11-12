#include <stdio.h>
#include <stdlib.h>

struct Fila
{
    struct Item *inicio, *fim;
};

struct Item
{
    int dado;
    struct Item *prox;
};

struct Fila * criaFila();
struct Item * criaItem(int);

void enfileirar(struct Fila *, int);
int desenfileirar(struct Fila *);
void mostrar(struct Fila *);

void destroiFila(struct Fila *);

int main()
{
    char op;
    int x;
    struct Fila *fila = criaFila();

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &x);
            // Enfileirar
            enfileirar(fila, x);
        }
        else if (op == 'D')
        {
            // Desenfileirar
            desenfileirar(fila);
        }
        else if (op == 'M')
        {
            // Exibir
            mostrar(fila);
        }
    }
    destroiFila(fila);
    return 0;
}

struct Fila * criaFila()
{
    struct Fila *fila = (struct Fila *) malloc(sizeof(struct Fila));
    if (fila != NULL)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

struct Item * criaItem(int dado)
{
    struct Item *item = (struct Item *) malloc(sizeof(struct Item));
    if (item != NULL)
    {
        item->prox = NULL;
        item->dado = dado;
    }
    return item;
}

void enfileirar(struct Fila *f, int dado)
{
    struct Item *novo = criaItem(dado);

    if (f->inicio == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
    }

    f->fim = novo;
}

int desenfileirar(struct Fila *f)
{
    if (f->inicio != NULL)
    {
        struct Item *atual = f->inicio;

        printf("<%d>\n", f->inicio->dado);
        f->inicio = f->inicio->prox;
        free(atual);

        if(f->inicio == NULL) f->fim == NULL;
    }
    else printf("Underflow Error: Fila Vazia.\n");
}

void mostrar(struct Fila *f)
{
    if (f->inicio != NULL)
    {
        struct Item *atual = f->inicio;

        while(atual != NULL)
        {
            if (atual->prox == NULL) printf("%d\n", atual->dado);
            else printf("%d ", atual->dado);

            atual = atual->prox;
        }
    }
    else printf("Underflow Error: Fila Vazia.\n");
}

void destroiFila(struct Fila * f)
{
    if (f != NULL)
    {
        struct Item *atual;
        while(f->inicio != NULL)
        {
            atual = f->inicio;
            f->inicio = f->inicio->prox;
            free(atual);
        }
        free(f);
    }
}