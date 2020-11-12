#include <stdio.h>
#include <stdlib.h>

struct Lista
{
	struct Node *inicio, *fim;
};

struct Node
{
	int chave;
	struct Node *prox, *ant;
};

struct Lista *criaLista()
{
	struct Lista *lista = (struct Lista*) malloc(sizeof(struct Lista));
	if (lista != NULL)
	{
		lista->inicio = NULL;
        lista->fim = NULL;
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
		it->ant = NULL;
	}
	return it;
}

void inserir(struct Lista *lt, int chave)
{
    struct Node *novo = criaItem(chave);

    if (lt->inicio == NULL)
    {
        lt->inicio = novo;
        lt->fim = novo;
    }
    else
    {
        struct Node *anterior = NULL;
        struct Node *atual = lt->inicio;

        while(atual->prox != NULL)
        {
            anterior = atual;
            atual = atual->prox;
        }
           atual->prox = novo;
           novo->ant = atual;
           lt->fim = atual->prox;
    }
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

void printReverseList(struct Node* inicio)
{
    if (inicio == NULL) return;

    struct Node *atual = inicio;

    while (atual->prox != NULL) atual = atual->prox;

    for (; atual != NULL; atual = atual->ant)
    {
        printf("%d\n", atual->chave);
    }
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

        printReverseList(lista->inicio);
        destruirLista(lista);
    }

    return 0;
}