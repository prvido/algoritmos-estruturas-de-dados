#include <stdio.h>
#include <stdlib.h>

struct Pessoa
{
    char nome[50];
    int ra;
};

struct Fila
{
    struct Pessoa *itens;
    int inicio, fim, tamanho, quantidade;
};

void iniciaFila(struct Fila *, int n);
struct Pessoa criaPessoa(int, char*);
void inserir(struct Fila *, struct Pessoa);
int remover(struct Fila *);
int checkVazia(struct Fila *);
void mostrarM(struct Fila);
void mostrarR(struct Fila);

int main()
{
    int n;
    scanf("%d", &n);

    struct Fila fila;
    iniciaFila(&fila, n);

    struct Pessoa p;

    char cod;
    while (scanf("\n%c", & cod) != EOF)
    {
        if (cod == 'I')
        {
            if (fila.quantidade < fila.tamanho)
            {
                // criar aluno
                char nome_[50];
                int ra;
                scanf("%d \n%s", &ra, nome_);

                p = criaPessoa(ra, nome_);

                // inserir aluno
                inserir(&fila, p);
            }
        }
        else if (cod == 'A')
        {
            if (fila.quantidade != 0)
            {
                // elimina aluno da fila FIFO
                int pos = remover(&fila);
                printf("[%d] %s\n", fila.itens[pos].ra, fila.itens[pos].nome);
            }
        }
        else if (cod == 'M')
        {
            if (fila.quantidade != 0)
            mostrarM(fila);
        }
        else if (cod == 'R')
        {
            // exibir fila, último até primeiro, [RA] nome
            if (fila.quantidade != 0)
            mostrarR(fila);
        }
        else if (cod == 'Q')
        {
            // exibir quantidade de alunos na fila
            printf("Quantidade: %d\n", fila.quantidade);
        }
    }
    return 0;
}

void iniciaFila(struct Fila *f, int n)
{
    if (f->tamanho != n)
    {
        f->itens = malloc(sizeof(struct Pessoa) * n);
        f->tamanho = n;
    }
    f->inicio = -1;
    f->fim = -1;
    f->quantidade = 0;
}

struct Pessoa criaPessoa(int ra, char nome[50])
{
    struct Pessoa p;
    for (int i = 0; i < 50; i++) p.nome[i] = nome[i];
    p.ra = ra;
    return p;
}

void inserir(struct Fila *f, struct Pessoa p)
{
    if (f->fim != f->tamanho - 1)
    {
        if (f->inicio == -1 & f->fim == -1) f->inicio++;

        f->quantidade++;
        f->fim++;
        f->itens[f->fim] = p;
    }
}

int remover(struct Fila *f)
{
    int aux = -1;
    if (f->inicio != -1 && f->inicio != -1)
    {
        aux = f->inicio;
        f->inicio++;
    }
    if (checkVazia(f)) iniciaFila(f, f->tamanho);
    return aux;
}

int checkVazia(struct Fila *f)
{
    if (f->inicio != -1 && f->inicio > f->fim) return 1;

    return 0;
}

void mostrarM(struct Fila f)
{
    for (int i = f.inicio; i <= f.fim; i++)
    {
        printf("[%d] %s\n", f.itens[i].ra, f.itens[i].nome);
    }
}

void mostrarR(struct Fila f)
{
    for (int i = f.fim; i >= f.inicio; i--)
    {
        printf("[%d] %s\n", f.itens[i].ra, f.itens[i].nome);
    }
}


/*
5
I 4838 PEDRO
I 4747 Marcos
I 7890 Bernardo
I 1234 Ana
I 88483 Merce
I 8484 Katia
*/