#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p){
    celula *remove;
    if(p != NULL && p->prox != NULL)
    {
        remove = p->prox;
        p->prox = remove->prox;
        free(remove);
        return 1;
    }
    return 0;   
}

void remove_elemento(celula *le, int x){
    celula *p, *q;
    p = le;
    q = le->prox;

    while (q != NULL && q->dado != x)
    {
        p = q;
        q = q->prox;
    }
    
    if (q != NULL)
    {
        p->prox = q->prox;
        free(q);
    }
    
}

void remove_todos_elementos(celula *le, int x){
    if (le->prox != NULL)
    {
        celula *lixo = le->prox;
        if (lixo->dado == x)
        {
            le->prox = lixo->prox;
            free(lixo);
            remove_todos_elementos(le, x);
        }
        else
        {
            remove_todos_elementos(le->prox,x);
        }
        
    }
}
