#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*//---------------------------------------------------------------------------------------------------------

//Definir os Tipos (ED)

NoPilha
int chave
*NoPilha proximo
*NoPilhaTopo
int tamanho

*///---------------------------------------------------------------------------------------------------------

typedef struct NoPilha* PtrNoPilha;

typedef struct NoPilha{
  int chave;
  PtrNoPilha proximo; //NoPilha*
}NoPilha;

typedef struct{
  PtrNoPilha topo;
  int tamanho;
}PilhaDinamica;

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

//Pilha Dinâmica

//-----------------------------------------------------------------------------------------------------------
//1 -> inicialização-----------------------------------------------------------------------------------------
void iniciaPilhaDinamica(PilhaDinamica *pilha){
  //ponteiro do topo aponta para nulo
  pilha->topo = NULL;
  //quantidade de elementos se inicia em zero
  pilha->tamanho = 0;
}//iniciaPilhaDinamica

//-----------------------------------------------------------------------------------------------------------
//2 -> quantidade de elementos na estrutura------------------------------------------------------------------
int tamanhoPilhaDinamica(PilhaDinamica *pilha){
  return(pilha->tamanho);
}//tamanhoPilhaDinamica

//-----------------------------------------------------------------------------------------------------------
//3 -> está Vazia--------------------------------------------------------------------------------------------
bool estaVaziaPilhaDinamica(PilhaDinamica *pilha){
  return(pilha->tamanho == 0);
}//estaVaziaPilhaDinamica

//-----------------------------------------------------------------------------------------------------------
//4 -> inserção (push / empilha)-----------------------------------------------------------------------------
void empilhaPilhaDinamica(PilhaDinamica *pilha, int x){
  //cria um novo no
  PtrNoPilha aux;
  aux = (PtrNoPilha)malloc(sizeof(NoPilha));
  //copia o valor inserido no novo no
  aux->chave = x;
  //o proximo do novo no aponta para onde o topo apontava antes
  aux->proximo = pilha->topo;
  //topo aponta para o novo no
  pilha->topo = aux;
  //incrementa tamanho
  pilha->tamanho++;
}//empilhaPilhaDinamica

//-----------------------------------------------------------------------------------------------------------
//5 -> remoção (pop / desempilha)----------------------------------------------------------------------------
void desempilhaPilhaDinamica(PilhaDinamica *pilha, int* x){
  if(!estaVaziaPilhaDinamica(pilha)){
    *x = pilha->topo->chave;
    PtrNoPilha aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(aux);
    pilha->tamanho--;
  }//if
}//desempilhaPilhaDinamica

//-----------------------------------------------------------------------------------------------------------
//6 -> pesquisa/consulta (topo / top) - mostra o topo--------------------------------------------------------
void topoPilhaDinamica(PilhaDinamica *pilha, int *x){
  if(!estaVaziaPilhaDinamica(pilha)){
    *x = pilha->topo->chave;
  }//if
}//topoPilhaDinamica

//-----------------------------------------------------------------------------------------------------------
//7 -> imprimir estrutura (print)----------------------------------------------------------------------------
void imprimePilhaDinamica(PilhaDinamica *pilha){
  printf("Pilha = {");
  PtrNoPilha ptr;
  for(ptr = pilha->topo; ptr != NULL; ptr = ptr->proximo){
    printf("%d", ptr->chave);
  }//for
  printf("}\n");
}//imprimePilhaDinamica

//-----------------------------------------------------------------------------------------------------------
//8 -> destruir Versão 1-------------------------------------------------------------------------------------
void destroiPilhaDinamicaV1(PilhaDinamica *pilha){
  printf("Destruindo pilha!\n");
  PtrNoPilha toRemove;
  while(pilha->topo!= NULL){
    toRemove = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(toRemove);
  }//while
}//destroiPilhaDinamicaV1

//-----------------------------------------------------------------------------------------------------------
//9 -> destruir Versão 2-------------------------------------------------------------------------------------
void destroiPilhaDinamicaV2(PilhaDinamica *pilha){
  printf("Destruindo pilha!\n");
  int aux;
  while(!estaVaziaPilhaDinamica(pilha)){
      desempilhaPilhaDinamica(pilha, &aux);
  }//while
}//destroiPilhaDinamicaV2

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

int main(int argc, char const *argv[]) {

  PilhaDinamica pd;

  iniciaPilhaDinamica(&pd);

  if(estaVaziaPilhaDinamica(&pd)){
    printf("Está vazia\n");
  }else{
    printf("Tem algo ai dentro\n");
  }//if

  empilhaPilhaDinamica(&pd, 9);
  imprimePilhaDinamica(&pd);
  empilhaPilhaDinamica(&pd, 13);
  imprimePilhaDinamica(&pd);
  empilhaPilhaDinamica(&pd, 2);
  imprimePilhaDinamica(&pd);



  return 0;
}
