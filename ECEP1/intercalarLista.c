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

void mostrar(struct Node *no)
{
    struct Node *atual = no;
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

void inserirOrd(struct Lista* lt, int ch)
{
    struct Node *novo = criaItem(ch);

    if (lt->inicio == NULL)
    {
        lt->inicio = novo;
    }
    else
    {
        struct Node *ant = NULL;
        struct Node *atual = lt->inicio;

        while (atual != NULL && atual->chave <= ch)
        {
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

struct Node * mergeLists(struct Node *nodeA, struct Node *nodeB)
{
    struct Lista *lt = criaLista();

    struct Node *atualA = nodeA;
    struct Node* atualB = nodeB;

    while (atualA != NULL)
    {
        inserirOrd(lt, atualA->chave);
        atualA = atualA->prox;
    }

    while (atualB != NULL)
    {
        inserirOrd(lt, atualB->chave);
        atualB = atualB->prox;
    }

    return lt->inicio;
}

int main()
{
    int q, na, nb, x;

    scanf("%d", &q);

    for(int i = 0; i < q; i++)
    {

        struct Lista *listaA = criaLista();
        struct Lista *listaB = criaLista();

        scanf("%d", &na);
        for (int j = 0; j < na; j++)
        {
            scanf("%d", &x);
            inserir(listaA, x);
        }

        scanf("%d", &nb);
        for(int j = 0; j < nb; j++)
        {
            scanf("%d", &x);
            inserir(listaB, x);
        }

        struct Node *no = mergeLists(listaA->inicio, listaB->inicio);

        mostrar(no);

        destruirLista(listaA);
        destruirLista(listaB);
    }

    return 0;
}