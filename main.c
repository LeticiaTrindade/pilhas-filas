#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int valor;
  struct Node* proximo;
}No;

// Fila
No* inserirFila (No* no, int valor){
  if (no != NULL){
    no->proximo = inserirFila(no->proximo, valor);
    return no;
  }
  else{
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
  }
}

No* imprimirFila(No* no){
  if(no->proximo != NULL){
  printf("%d ", no->valor);
  no->proximo = imprimirFila(no->proximo);
    return no;
  }
  else{
    printf("%d ", no->valor);
  }
}

No* removerFila (No* no){
  No* notemporario = no->proximo;
  free(no);
  return notemporario;
}

No* buscarFila (No* no, int valor){
  if (no == NULL)
  {
    printf("Não encontrado");
  }
  else{
    if (no->valor == valor)
    {
      printf("%d ", valor);
    }
    else
    {
      no->proximo = buscarFila(no->proximo, valor);
      return no;
    }
  }
  
}

// Pilha

No* inserirPilha(No* no, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = no;
    return novo;
}

No* imprimirPilha(No* no){
  if(no->proximo != NULL){
  printf("%d ", no->valor);
  no->proximo = imprimirPilha(no->proximo);
    return no;
  }
  else{
    printf("%d ", no->valor);
  }
}

No* removerPilha (No* no){
  No* notemporario = (No*)malloc(sizeof(No));
  free(no);
  return notemporario;
}

No* buscarPilha(No* no, int valor){
  if (no == NULL)
  {
    printf("Não encontrado");
  }
  else{
    if (no->valor == valor)
    {
      printf("%d ", valor);
    }
    else
    {
      no->proximo = buscarFila(no->proximo, valor);
      return no;
    }
  }  
}


int main(void){
  No* fila = NULL;//vazia
  No* pilha = NULL;
  printf("*** De acordo com o conceito de fila, devemos adicionar o dado no final e remover o dado que está armazenado há mais tempo. ***\n\n");
  printf("Inserindo e imprimindo 5, 10 e 20 na fila: \n");
   
  fila = inserirFila(fila, 5);
  fila = inserirFila(fila, 10);
  fila = inserirFila(fila, 20);
  fila = imprimirFila(fila);

  printf("\n\nBuscando 10 dentro da fila: \n");
  fila = buscarFila(fila, 10);

  printf("\n\nRemovendo valor da fila e imprimindo: \n");
  fila = removerFila(fila);
  imprimirFila(fila);


  printf("\n\n*** Já a pilha nós adicionamos o dado no começo e devemos remover o dado inserido recentemente.");
  printf("\n\nInserindo e imprimindo 30, 40 e 50 na pilha: \n");
  
  pilha = inserirPilha(pilha, 30);
  pilha = inserirPilha(pilha, 40);
  pilha = inserirPilha(pilha, 50);
  pilha = imprimirPilha(pilha);

  printf("\n\nBuscando 30 dentro da pilha: \n");
  pilha = buscarFila(pilha, 30);

  printf("\n\nRemovendo valor da pilha e imprimindo: \n");
  pilha = removerFila(pilha);
  imprimirFila(pilha);



  return 0;
}