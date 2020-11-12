#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
    int info;
    char texto[1000];
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
        printf("[%d]:%s\n", (*raiz)->info, (*raiz)->texto);
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
        printf("[%d]:%s\n", (*raiz)->info, (*raiz)->texto);
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
        printf("[%d]:%s\n", (*raiz)->info, (*raiz)->texto);
    }
}

int converter(char texto[1000])
{
    int soma = 0;
    for (int i = 0; i < strlen(texto); i++)
    {
        soma += texto[i];
    }
    return soma;
}

struct Node* criaNode(char texto[1000])
{
    struct Node *novo = (struct Node *) malloc(sizeof(struct Node));

    novo->info = converter(texto);
    for (int i = 0; i < strlen(texto); i++)
    {
        novo->texto[i] = texto[i];
    }
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

void inserir(Arvore *raiz, char texto[1000])
{
    if (raiz == NULL)
        return;

    struct Node *novo = criaNode(texto);
    int valor = converter(texto);

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
        //printf("%c\n", atual->info);
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

    //printf("%c\n", atual->info);

    free(atual);

    return no2;
}


int remover(Arvore *raiz, char texto[1000])
{

    int valor = converter(texto);

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
    char x[1000];
    Arvore *arvore = criaArvore();

    while(scanf("%s", op) != EOF)
    {
        if (strcmp(op, "insert") == 0)
        {
            scanf("\n%s", x);
            inserir(arvore, x);
        }
        else if (strcmp(op, "delete") == 0)
        {
            scanf("\n%s", x);
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