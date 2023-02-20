#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

struct pilha_no {
    struct no* dado;
    struct pilha_no* prox;
} p;

struct Stack {
    struct pilha* top;
};

struct no* createNode(int data) {
    struct no* no = (struct no*) malloc(sizeof(struct no));
    no->dado = data;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

struct pilha* cria_pilha(struct no* no) {
    struct p* pilha = (struct p*) malloc(sizeof(struct p));
    pilha->dado = no;
    pilha->prox = NULL;
    return pilha;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, struct no* no) {
    struct pilha* pilha = createStackNode(no);
    pilha->prox = stack->top;
    stack->top = pilha;
}

struct no* pop(struct Stack* stack) {
    if (stack->top == NULL) 
    {
        return NULL;
    }
    struct pilha* temp = stack->top;
    struct no* no = stack->top->dado;
    stack->top = stack->top->prox;
    free(temp);
    return no;
}

void pos_ordem(no* raiz) {

    if (raiz == NULL) 
    {
        return;
    }

    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();

    push(stack1, raiz);

    while (stack1->top != NULL) 
    {
        struct no* no = pop(stack1);
        push(stack2, no);
        if (no->esq != NULL) 
        {
            push(stack1, no->esq);
        }
        if (no->dir != NULL) 
        {
            push(stack1, no->dir);
        }
    }
    while (stack2->top) {
        struct no* no = pop(stack2);
        printf("%d ", no->dado);
    }
}

int main() {
    struct no* raiz = createNode(2);
    raiz->esq = createNode(5);
    raiz->dir = createNode(7);
    raiz->esq->esq = createNode(3);
    raiz->esq->dir = createNode(8);
    raiz->esq->dir->esq = createNode(4);
    raiz->dir->esq = createNode(1);
    raiz->dir->dir = createNode(6);
    raiz->dir->esq->dir = createNode(9);
    printf("Post-order traversal of the binary tree is: ");
    pos_ordem(raiz);
    return 0;
}
