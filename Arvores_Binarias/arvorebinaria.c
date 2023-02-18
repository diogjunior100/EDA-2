#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

//typedef struct no no;

void pos_ordem (no *raiz) {
    if (no == NULL){
        return;
    }
    pos_ordem(no->esq);
    
    pos_ordem(no->dir);
 
    printf("%d ", no->dado);

    while (no->dado != NULL)
    {
        
    }
    
}

