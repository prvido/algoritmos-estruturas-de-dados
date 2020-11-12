#include <stdio.h>
#include<stdlib.h>

struct Lista
{
    struct Item *inicio, *fim;
};

struct Item
{
  int chave;
  struct Item *prox, *ant;
};

struct Lista * criaLista()
{
    struct Lista *lista = (struct Lista*) malloc(sizeof(struct Lista));
    if (lista != NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

struct Item *criaItem(int chave)
{
    struct Item *item = (struct Item*) malloc(sizeof(struct Item));
    if (item != NULL)
    {
        item->prox = NULL;
        item->ant = NULL;
        item->chave = chave;
    }
    return item;
}

void inserir(struct Lista *lt, int chave)
{
    struct Item *novo = criaItem(chave);

    if (lt->inicio == NULL)
    {
        lt->inicio = novo;
        lt->fim = novo;
    }
    else
    {
        struct Item *anterior = NULL;
        struct Item *atual = lt->inicio;

        while(atual != NULL && novo->chave >= atual->chave)
        {
            if (atual->chave == chave) return;
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL) // inicio
        {
            lt->inicio->ant = novo;
            novo->prox = lt->inicio;
            lt->inicio = novo;
        }
        else
        {
            novo->prox = anterior->prox;
            novo->ant = anterior;
            anterior->prox = novo;
            if (atual != NULL)
                atual->ant = novo;
            else lt->fim = novo;
        }
    }
}

void remover(struct Lista *lt, int ch)
{
    if (lt->inicio == NULL) return;

    struct Item *atual = lt->inicio;

    while(atual != NULL && atual->chave != ch)
    {
        atual = atual->prox;
    }

    if (atual == NULL) return; // elemento não foi encontrado

    if (atual->ant == NULL) // removendo do início
    {
        lt->inicio = atual->prox;
    }
    else
    {
        atual->ant->prox = atual->prox; // tira o do meio e liga os dois dos lados
    }

    if (atual->prox != NULL) // quer dizer que não é o último
    {
        atual->prox->ant = atual->ant; // tira o do meio e liga os dois dos lados
    }
    else
    {
        lt->fim = atual->ant; // o antes pq vai dar free no atual
    }

    free(atual);

}

void destruirLista (struct Lista *lt)
{
    struct Item *atual;
    while(lt->inicio != NULL)
    {
        atual = lt->inicio;
        lt->inicio = lt->inicio->prox;
        free(atual);
    }
    free(lt);
}

void mostrar(struct Lista *lt, int n)
{
    if (n > 0)
    {
        for(struct Item *atual = lt->inicio; atual != NULL; atual = atual->prox)
        {
            printf("%d ", atual->chave);
        }
    }
    else
    {
        for(struct Item *atual = lt->fim; atual != NULL; atual = atual->ant)
        {
            printf("%d ", atual->chave);
        }
    }
}

int main()
{
    int x;
    char op;

    struct Lista *lista = criaLista();

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'I')
        {
            scanf("%d", &x);
            inserir(lista, x);
        }
        else if (op == 'E')
        {
            scanf("%d", &x);
            remover(lista, x);
        }
        else if (op == 'M')
        {

            if (lista->inicio != NULL)
            {
                mostrar(lista, 1);
            }
            printf("\n");
        }
        else if (op == 'R')
        {
            if (lista->inicio != NULL)
            {
                mostrar(lista, -1);
            }
            printf("\n");
        }
    }

    destruirLista(lista);
    return 0;
}