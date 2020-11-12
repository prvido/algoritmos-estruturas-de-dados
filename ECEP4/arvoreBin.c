#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
    int info;
    struct Node *esq;
    struct Node *dir;
};

typedef struct Node *Arvore;

Arvore * criaArvore()
{
    Arvore *raiz = (Arvore *) malloc(sizeof(Arvore));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void liberaNode(struct Node *node)
{
    if (node == NULL)
        return;

    liberaNode(node->esq);
    liberaNode(node->dir);
    free(node);
    node = NULL;
}

void liberaArvore(Arvore *raiz)
{
    if (raiz == NULL)
        return;

    liberaNode(*raiz);
    free(raiz);
}

void preOrdem(Arvore *raiz)
{
    if (raiz == NULL)
        return;

    if (*raiz != NULL)
    {
        printf("%d ", (*raiz)->info);
        preOrdem(&((*raiz)->esq));
        preOrdem(&((*raiz)->dir));
    }
}

void emOrdem(Arvore *raiz)
{
    if (raiz == NULL)
        return;

    if (*raiz != NULL)
    {
        emOrdem(&((*raiz)->esq));
        printf("%d ", (*raiz)->info);
        emOrdem(&((*raiz)->dir));
    }
}

void posOrdem(Arvore *raiz)
{
    if (raiz == NULL)
        return;
    if (*raiz != NULL)
    {
        posOrdem(&((*raiz)->esq));
        posOrdem(&((*raiz)->dir));
        printf("%d ", (*raiz)->info);
    }
}

struct Node* criaNode(int info)
{
    struct Node *novo = (struct Node *) malloc(sizeof(struct Node));

    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

void inserir(Arvore *raiz, int valor)
{
    if (raiz == NULL)
        return;

    struct Node *novo = criaNode(valor);

    if (*raiz == NULL)
        *raiz = novo;

    else
    {
        struct Node *atual = *raiz;
        struct Node *anterior = NULL;

        while (atual != NULL)
        {
            anterior = atual;

            if (valor >= atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if (valor >= anterior->info)
            anterior->dir = novo;
        else
            anterior->esq = novo;
    }
}

struct Node* removerNode(struct Node *atual)
{
    struct Node *no1, *no2;

    if (atual->dir == NULL)
    {
        no2 = atual->esq;
        printf("%d\n", atual->info);
        free(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->dir;

    while (no2->esq != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }

    if (no1 != atual)
    {
        no1->esq = no2->dir;
        no2->dir = atual->dir;
    }

    no2->esq = atual->esq;

    printf("%d\n", atual->info);

    free(atual);

    return no2;
}


int remover(Arvore *raiz, int valor)
{

    if (raiz == NULL)
        return 0;

    struct Node *anterior = NULL;
    struct Node *atual = *raiz;

    while (atual != NULL)
    {
        if (valor == atual->info)
        {
            if (atual == *raiz)
                *raiz = removerNode(atual);
            else
            {
                if (anterior->dir == atual)
                    anterior->dir = removerNode(atual);
                else
                    anterior->esq = removerNode(atual);
            }
            return 1;
        }

        anterior = atual;
        if (valor >= atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int main()
{
    char op[50];
    int x;
    Arvore *arvore = criaArvore();

    while(scanf("%s", op) != EOF)
    {
        if (strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            inserir(arvore, x);
        }
        else if (strcmp(op, "delete") == 0)
        {
            scanf("%d", &x);
            remover(arvore, x);
        }
        else if (strcmp(op, "pre-order") == 0)
        {
            preOrdem(arvore);
            printf("\n");
        }
        else if(strcmp(op, "in-order") == 0)
        {
            emOrdem(arvore);
            printf("\n");
        }
        else if (strcmp(op, "post-order") == 0)
        {
            posOrdem(arvore);
            printf("\n");
        }
    }

    liberaArvore(arvore);
    return 0;
}
