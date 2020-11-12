#include <stdio.h>
#include <stdlib.h>

struct Lista
{
    struct Item *inicio;
};

struct Item
{
    int nome, placar;
    struct Item *prox;
};

struct Lista * criaLista()
{
    struct Lista *lista = (struct Lista* ) malloc(sizeof(struct Item));
    if (lista != NULL)
    {
        lista->inicio = NULL;
    }
    return lista;
};

struct Item * criaItem(int nome, int placar)
{
    struct Item *item = (struct Item*) malloc(sizeof(struct Item));
    if (item != NULL)
    {
        item->prox = NULL;
        item->nome = nome;
        item->placar = placar;
    }
    return item;
}

void lerEntrada(int *v)
{
    for (int i = 0; i < 30; i++)
    {
        scanf("%d", &v[i]);
    }
}

void remover(struct Lista* lt, int nome)
{
    if (lt != NULL)
    {
        struct Item *ant = lt->inicio;
        struct Item *atual = lt->inicio;

        while (atual != NULL && atual->nome != nome)
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

void mostrar(struct Lista *lt)
{
    struct Item *atual = lt->inicio;
    while (atual != NULL)
    {
        if (atual->prox != NULL)
        {
            printf("%c ", atual->nome);
        }
        else
        {
            printf("%c\n", atual->nome);
        }
        atual = atual->prox;
    }
}

void print(int *v)
{
    for (int i = 0; i < 30; i++)
    {
        printf("%c ", v[i]);
    }
    printf("\n");
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

void inserir(struct Lista* lt, int nome, int placar)
{
    struct Item *novo = criaItem(nome, placar);

    if (lt->inicio == NULL)
    {
        lt->inicio = novo;
    }
    else
    {
        struct Item *atual = lt->inicio;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void rodada(struct Lista *lt, int *v)
{
    struct Item *atual = lt->inicio;

    int i = 0;
    while(atual->prox != NULL)
    {
        if (atual->placar > atual->prox->placar)
        {
            v[i] = atual->nome;
            remover(lt, atual->prox->nome);
        }
        else // removendo atual;
        {
            v[i] = atual->prox->nome;
            remover(lt, atual->nome);


            atual = lt->inicio;

            while(atual->nome != v[i]) atual = atual->prox;
        }
        printf("%c\n", atual->nome);
        i++;
        atual=atual->prox;
    }
}

int main()
{
    int *resultado;
    int vencedores[30];
    int nome = 65;

    for (int i = 0; i < 30; i++)
    {
        vencedores[i] = 0;
    }

    struct Lista *lista = criaLista();

    lerEntrada(resultado);

    for (int i = 0; i < 30; i++)
    {
        if (i < 16)
        {
            // Oitavas de Final
            inserir(lista, nome + i, resultado[i]);

            if (i == 15)
            {
                printf("Times nas Oitavas:\n");
                mostrar(lista);

                rodada(lista, vencedores);

                printf("\n Times que passaram:\n");
                mostrar(lista);

                destruirLista(lista);
                lista = criaLista();

            }
        }
        else if (i >= 16 && i < 24)
        {
            // Quartas
            inserir(lista, vencedores[i - 16], resultado[i]);

            if (i == 23)
            {
                printf("Quartas\n");
                rodada(lista, vencedores);
                destruirLista(lista);
                lista = criaLista();
            }
        }
        else if (i >= 24 && i < 28)
        {
            // Semi
            inserir(lista, vencedores[i - 24], resultado[i]);

            if (i == 27)
            {
                printf("Semi\n");
                rodada(lista, vencedores);
                destruirLista(lista);
                lista = criaLista();
            }
        }
        else
        {
            //Final
            inserir(lista, vencedores[i - 28], resultado[i]);

            if(i == 29)
            {
                printf("Final\n");
                rodada(lista, vencedores);
            }
        }
    }
    printf("%c\n", vencedores[0]);
    destruirLista(lista);
    return 0;
}