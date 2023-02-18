#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado[1001];
    struct No* prox;
} No;

No* cria_pilha() {
    No* novo_no = (No*) calloc(1, sizeof(No));
    novo_no->prox = NULL;
    return novo_no;
}

int push(No* top, const char *str) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) 
    {
        return 0;
    }
    
    strcpy(novo_no->dado, str);
    novo_no->prox = top->prox;
    top->prox = novo_no;
    return 1;
}

int pop(No* top, char str[1001]) {
    if (top->prox == NULL) {
        return 0;
    }
    
    No* lixo = top->prox;
    strcpy(str, lixo->dado);
    top->prox = lixo->prox;
    free(lixo);
    return 1;
}

int main() {
    int success;
    char input[1001], output[1001];

    No* stack = cria_pilha();
    
    while (scanf(" %s", input) != EOF) 
    {
        if (input[0] == 'd') 
        {
            success = pop(stack, output);

            if (success) 
            {
                printf("%s\n", output);
            } 
            else 
            {
                printf("NULL\n");
            }
        } 
        else if (input[0] == 'i') 
        {
            scanf(" %[^\n]s", input);
            push(stack, input);
        }
    }
    return 0;
}
