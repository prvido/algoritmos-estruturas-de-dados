#include <stdio.h>
#include <stdlib.h>

struct Lista
{
	struct Node *inicio;
};

struct Node
{
	int chave;
	struct Node *prox;
};

struct Lista *criaLista()
{
	struct Lista *lista = (struct Lista*) malloc(sizeof(struct Lista));
	if (lista != NULL)
	{
		lista->inicio = NULL;
	}
	return lista;
}

struct Node * criaItem(int ch)
{
	struct Node *it = (struct Node*) malloc(sizeof(struct Node));
	if (it != NULL)
	{
		it->chave = ch;
		it->prox = NULL;
	}
	return it;
}

void destruirLista(struct Lista *lt)
{
    struct Node *atual = lt->inicio;
    while (lt->inicio != NULL)
    {
        atual = lt->inicio;
        lt->inicio = lt->inicio->prox;
        free(atual);
    }
    free(lt);
}

void inserir(struct Lista *lt, int ch)
{
    struct Node *novo = criaItem(ch);

    if (lt->inicio == NULL) lt->inicio = novo;

    else
    {
        struct Node *atual = lt->inicio;

        while(atual->prox != NULL) atual = atual->prox;

        atual->prox = novo;
    }
}

void mostrar(struct Node *lt)
{
    struct Node *atual = lt;
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

struct Node * removeDuplicates(struct Node *node)
{
    struct Lista *lista_s = criaLista();

    struct Node *anterior = NULL;
    struct Node *atual = node;

    while(atual != NULL)
    {
        if (anterior == NULL)
        {
            if (atual != atual->prox) inserir(lista_s, atual->chave);
        }
        else
        {
            if (anterior->chave != atual->chave) inserir(lista_s, atual->chave);
        }

        anterior = atual;
        atual = atual->prox;
    }



    return lista_s->inicio;
}

int main()
{
    int q, n, x;

    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &n);
        struct Lista *lista = criaLista();

        for(int j = 0; j < n; j++)
        {
            scanf("%d", &x);
            inserir(lista, x);
        }

        struct Node *node = removeDuplicates(lista->inicio);

        mostrar(node);
        destruirLista(lista);
    }

    return 0;
}