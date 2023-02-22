#include <stdlib.h>

#define TAM 100

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

struct Pilha
{
    int tamanho;
    int topo;
    struct no** vetor;
};

struct no* novoNo (int dado){
    struct no* no = (struct no*)malloc(sizeof(struct no));
    no->dado = dado;
    no->esq = no->dir = NULL;
    return no;
}

struct Pilha* cria_pilha (int tamanho){
    struct Pilha* pilha = (struct Pilha*)malloc(sizeof(struct Pilha));
    pilha->tamanho = tamanho;
    pilha->topo = -1;
    pilha->vetor = (struct no**)malloc(pilha->tamanho * sizeof(struct no*));
    return pilha;
}

int completa (struct Pilha* pilha){
    return pilha->topo - 1 == pilha->tamanho;
}

void insere (struct Pilha* pilha, struct no* no){
    if (completa(pilha))
    {
        return;
    }
    pilha->vetor[++pilha->topo] = no;
    
}

struct no* remove(struct Pilha* pilha)
{
	if (pilha->topo == -1){
		return NULL;
    }
	return pilha->vetor[pilha->topo--];
}

struct no* peek(struct Pilha* pilha)
{
	if (pilha->topo == -1){
		return NULL;
    }
	return pilha->vetor[pilha->topo];
}

void pos_ordem (no *raiz){
    if (raiz == NULL)
    {
        return;
    }

    struct Pilha* pilha = cria_pilha(TAM);

    do
    {
        while (raiz)
        {
            if(raiz->dir){
                insere(pilha, raiz->dir);
            }
            insere(pilha, raiz);

            raiz = raiz->esq;
        }

        raiz = remove(pilha);

        if (raiz->dir && peek(pilha) == raiz->dir)
        {
            remove(pilha);
            insere(pilha, raiz);
            raiz = raiz->dir;
        }
        else
        {
            printf("%d ", raiz->dado);
            raiz = NULL;
        }
        
    } while (pilha->topo != -1);
}

