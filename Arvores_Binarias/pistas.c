#include <stdio.h>
#include <stdlib.h>

typedef struct pista {
    int identificador; 
    int valor; //valor da pista
    struct pista *prox; //endereco da proxima pista
} Pistas;

int main() {
    int n;
    scanf("%d", &n);

    // criar a lista ligada
    Pistas *primeira = NULL;
    Pistas *ultima = NULL;

    for (int i = 0; i < n; i++) 
    {
        int id, valor, prox_id;
        scanf("%d %d %d", &id, &valor, &prox_id);

        Pistas *nova_pista = (Pistas*) malloc(sizeof(Pistas));
        nova_pista->identificador = id;
        nova_pista->valor = valor;
        nova_pista->prox = NULL;

        if (primeira == NULL) 
        {
            primeira = nova_pista;
            ultima = nova_pista;
        } 
        else 
        {
            ultima->prox = nova_pista;
            ultima = nova_pista;
        }
    }


    Pistas *p = primeira;

    /*for (int i = 0; i < n; i++)
    {
        while (p != NULL) 
        {
            printf("%d ", p->valor);
            p = p->prox;
            printf("%d\n", p->identificador);
        }
    }*/
    p = p->prox;
    printf("%d\n", p->valor);

    p = primeira;
    while (p != NULL) 
    {
        Pistas *prox = p->prox;
        free(p);
        p = prox;
    }

    return 0;
}
