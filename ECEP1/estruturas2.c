#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Lista
{
    struct Estrutura *itens;
    int tamanho, quantidade;
};

struct Estrutura
{
    struct Node *inicio, *fim;
    int  id, quantidade;
};

struct Node
{
    struct Node *ref;
    int chave;
};

void iniciaLista (struct Lista *lt, int n)
{
    lt->itens = (struct Estrutura *) malloc(sizeof(struct Estrutura) * n);
    lt->tamanho = n;
    lt->quantidade = 0;
}

struct Estrutura * criaEstrutura(int id)
{
    struct Estrutura *estrutura = (struct Estrutura* ) malloc(sizeof(struct Node));
    if (estrutura != NULL)
    {
        estrutura->inicio = NULL;
        estrutura->quantidade = 0;
        estrutura->id = id;
    }
    return estrutura;
}

struct Node * criaItem(int ch)
{
    struct Node *item = (struct Node*) malloc(sizeof(struct Node));
    if (item != NULL)
    {
        item->chave = ch;
        item->ref = NULL;
    }
    return item;
}

void inserirEstrutura(struct Lista *lt, struct Estrutura *et)
{
    if (lt->quantidade == 0)
    {
        lt->itens[0] = *et;
    }
    else
    {
        int i = 0;
        while (i < lt->quantidade) i++;

        lt->itens[i] = *et;
    }
    lt->quantidade++;
}

void inserir(struct Estrutura *et, int chave)
{
    struct Node *novo = criaItem(chave);

    if (et->id == 0) // LDE
    {
        if (et->inicio == NULL)
        {
            et->inicio = novo;
        }
        else
        {
            struct Node *ant = NULL;
            struct Node *atual = et->inicio;

            while (atual != NULL && atual->chave <= chave)
            {
                if (atual->chave == chave) return;
                ant = atual;
                atual = atual->ref;
            }

            if (ant == NULL)
            {
                novo->ref = et->inicio;
                et->inicio = novo;
            }
            else
            {
                novo->ref = atual;
                ant->ref = novo;
            }
        }
        et->quantidade++;
    }
    else if (et->id == 1) // FILA
    {

        if (et->inicio == NULL)
        {
            et->inicio = novo;
        }
        else
        {
            et->fim->ref = novo;
        }
        et->fim = novo;
        et->quantidade++;
    }
    else if (et->id == 2) // PILHA
    {
        novo->ref = et->fim;
        et->fim = novo;

        et->quantidade++;
    }
}

void remover(struct Estrutura *et, int chave)
{
    if (et->id == 0) // LDE
    {
        if (et->inicio != NULL)
        {
            struct Node *ant = et->inicio;
            struct Node *atual = et->inicio;

            while (atual != NULL && atual->chave != chave)
            {
                ant = atual;
                atual = atual->ref;
                et->quantidade--;
            }

            if (atual != NULL)
            {
                if (atual == et->inicio)
                {
                    et->inicio = atual->ref;
                }
                else
                {
                    ant->ref = atual->ref;
                }
                printf("REMOVIDO: %d\n", atual->chave);
                free(atual);
                et->quantidade--;
            }
        }
    }
    else if (et->id == 1) // FILA
    {
        if (et->inicio != NULL)
        {
            struct Node *atual = et->inicio;

            printf("REMOVIDO: %d\n", et->inicio->chave);

            et->inicio = et->inicio->ref;
            free(atual);

            if(et->inicio == NULL) et->fim == NULL;
            et->quantidade--;
        }
    }
    else if (et->id == 2) // PILHA
    {
        if (et->fim != NULL)
        {
            printf("REMOVIDO: %d\n", et->fim->chave);

            struct Node *atual = et->fim;
            et->fim = et->fim->ref;
            if (et->fim == NULL) et->inicio = NULL;

            free(atual);
            et->quantidade--;
        }
    }
}

void mostrar(struct Estrutura *et)
{
    if (et->id == 0)
    {
        struct Node *atual = et->inicio;
        while (atual != NULL)
        {
            if (atual->ref != NULL)
            {
                printf("%d ", atual->chave);
            }
            else
            {
                printf("%d\n", atual->chave);
            }
            atual = atual->ref;
        }
    }
    else if (et->id == 1)
    {
        if (et->inicio != NULL)
        {
            struct Node *atual = et->inicio;

            while(atual != NULL)
            {
                if (atual->ref == NULL) printf("%d\n", atual->chave);
                else printf("%d ", atual->chave);

                atual = atual->ref;
            }
        }
    }
    else if (et->id == 2)
    {
        if (et->fim != NULL)
        {
            struct Node *atual = et->fim;

            int *v = (int *) malloc(sizeof (int) * et->quantidade);
            int i = 0;

            while (atual != NULL)
            {
                v[i] = atual->chave;
                atual = atual->ref;
                i++;
            }

            for (int j = i - 1; j >= 0; j--)
            {
                if (j != 0) printf("%d ", v[j]);
                else printf("%d\n", v[j]);
            }

        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Lista lista;
    iniciaLista(&lista, n);

    char nome[100];

    for (int i = 0; i < n; i++)
    {
        struct Estrutura *estrutura;

        scanf("\n%s", nome);

        if (strcmp(nome, "LDE") == 0)
        {
            estrutura = criaEstrutura(0);
            inserirEstrutura(&lista, estrutura);
        }
        else if (strcmp(nome, "FILA") == 0)
        {
            estrutura = criaEstrutura(1);
            inserirEstrutura(&lista, estrutura);
        }
        else if (strcmp(nome, "PILHA") == 0)
        {
            estrutura = criaEstrutura(2);
            inserirEstrutura(&lista, estrutura);
        }
    }

    int x, pos;
    char op;

    while (scanf("%d %c", &pos ,&op) != EOF)
    {
        if (op == 'I')
        {
            scanf("%d", &x);

            inserir(&lista.itens[pos], x);
        }
        else if (op == 'M')
        {
            mostrar(&lista.itens[pos]);
        }
        else if (op == 'R')
        {
            if (lista.itens[pos].id == 0) // caso a estrutura seja uma lista
            {
                scanf("%d", &x);

                remover(&lista.itens[pos], x);
            }
            else
            {
                remover(&lista.itens[pos], 0);
            }
        }
    }
    return 0;
}