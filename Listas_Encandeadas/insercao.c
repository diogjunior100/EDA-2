#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x){
    celula *elem;
    elem = malloc(sizeof(celula));
    elem->dado = x;
    elem->prox = le->prox;
    le->prox = elem;
}

void insere_antes(celula *le, int x, int y){
    celula *i, *j, *elem;
    elem = malloc(sizeof(celula));
    elem->dado = x;
    i = le;
    j = le->prox;

    while (j != NULL && j->dado != y)
    {
        i = j;
        j = j->prox;
    }

    elem->prox = j;
    i->prox = elem;
    
}
