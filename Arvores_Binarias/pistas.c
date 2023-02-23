#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int valor;
  int identificador;
  int prox;
}Item;

typedef struct no no;

struct no{
  Item e;
  no *prox;
};

typedef struct{
  no *inicio;
  int no_count;
  no *ultimo;
}cabeca_st;

int inicializaLista(cabeca_st *h){
  h->inicio = NULL;
  h->ultimo = NULL;
  h->no_count = 0;
  return 1;
}

int insere_inicio(cabeca_st *h, Item e){
  no *novo = malloc(sizeof(no));

  if(novo == NULL) return 0;

  novo->e = e;
  novo->prox = h->inicio;

  h->inicio = novo;
  h->no_count++;

  return 1;
}

void removeInicio(cabeca_st *h){
  printf("%d\n", h->inicio->e.valor);
  h->inicio = h->inicio->prox;
  h->no_count--;
  return;
}

int main(void){
  int n;
  scanf("%d", &n);
  Item item[n];

  cabeca_st h;
  inicializaLista(&h);

  for(int i = 0; i<n; i++){
    scanf("%d %d %d", &item[i].identificador, &item[i].valor, &item[i].prox);
    if(item[i].prox == -1){
      insere_inicio(&h, item[i]);
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(item[j].prox == h.inicio->e.identificador){
        insere_inicio(&h, item[j]);
      }
    }
  }

  for(int i = 0; i < n; i++){
    removeInicio(&h);
  }

  return 0;

} 

