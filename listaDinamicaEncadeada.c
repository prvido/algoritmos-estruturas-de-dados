#include <stdio.h>
#include <stdlib.h>

struct Lista
{
    struct Item *inicio;
};

struct Item
{
    int chave;
    struct Item *prox;
};

struct Lista * criaLista();
struct Item * criaItem(int);

void inserir(struct Lista*, int);
void remover(struct Lista*, int);
int buscar(struct Lista*, int);
void mostrar(struct Lista *);
void destruirLista(struct Lista *);

int main()
{
    char op;
    struct Lista *lista = criaLista();

    int x;

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            scanf("%d", &x);
            // INSERIR
            inserir(lista, x);
        }
        else if (op == 'R')
        {
            scanf("%d", &x);
            remover(lista, x);
        }
        else if (op == 'B')
        {
            scanf("%d", &x);
            // BUSCAR
            int b = (buscar(lista, x));

            if (b == -1) printf("NAO\n");
            else if (b == 1) printf("SIM\n");
        }
        else if (op == 'L')
        {
            // MOSTRAR
            mostrar(lista);
        }
    }
    destruirLista(lista);
    return 0;
}

struct Lista * criaLista()
{
    struct Lista *lista = (struct Lista* ) malloc(sizeof(struct Item));
    if (lista != NULL)
    {
        lista->inicio = NULL;
    }
    return lista;
}

struct Item * criaItem(int ch)
{
    struct Item *item = (struct Item*) malloc(sizeof(struct Item));
    if (item != NULL)
    {
        item->chave = ch;
        item->prox = NULL;
    }
    return item;
}

void inserir(struct Lista* lt, int ch)
{
    struct Item *novo = criaItem(ch);

    if (lt->inicio == NULL)
    {
        lt->inicio = novo;
    }
    else
    {
        struct Item *ant = NULL;
        struct Item *atual = lt->inicio;

        while (atual != NULL && atual->chave <= ch)
        {
            if (atual->chave == ch) return;
            ant = atual;
            atual = atual->prox;
        }

        if (ant == NULL)
        {
            novo->prox = lt->inicio;
            lt->inicio = novo;
        }
        else
        {
            novo->prox = atual;
            ant->prox = novo;
        }
    }
}

void remover(struct Lista* lt, int ch)
{
    if (lt != NULL)
    {
        struct Item *ant = lt->inicio;
        struct Item *atual = lt->inicio;

        while (atual != NULL && atual->chave != ch)
        {
            ant = atual;
            atual = atual->prox;
        }

        if (atual != NULL)
        {
            if (atual == lt->inicio)
            {
                lt->inicio = atual->prox;
            }
            else
            {
                ant->prox = atual->prox;
            }
            free(atual);
        }
    }
}

int buscar(struct Lista* lt, int ch)
{
    struct Item *atual = lt->inicio;

    while (atual != NULL && atual->chave != ch)
    {
        atual = atual->prox;
    }

    if (atual == NULL) return -1;
    else return 1;
}

void mostrar(struct Lista *lt)
{
    struct Item *atual = lt->inicio;
    while (atual != NULL)
    {
        if (atual->prox != NULL)
        {
            printf("%d ", atual->chave);
        }
        else
        {
            printf("%d\n", atual->chave);
        }
        atual = atual->prox;
    }
}

void destruirLista(struct Lista *lt)
{
    struct Item *atual = lt->inicio;
    while (lt->inicio != NULL)
    {
        atual = lt->inicio;
        lt->inicio = lt->inicio->prox;
        free(atual);
    }
    free(lt);
}