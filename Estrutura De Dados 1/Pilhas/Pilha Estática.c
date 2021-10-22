#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*//----------------------------------------------------------------------------------------------------------//

//operações de modificação

1 -> inicialização
2 -> inserção
3 -> remoção
4 -> pesquisa/consulta
5 -> destruir

//----------------------------------------------------------------------------------------------------------//

//operações adicionais/informação (ED)

6 -> está Vazia
7 -> está Cheia
8 -> maior elemento na estrutura
9 -> menor elemento na estrutura
10 -> quantidade de elementos na estrutura
11 -> proximo elemento, elemento seguinte a "x"
12 -> elemento anterior, elemento antes a "x"

//------------------------------------------------------------------------------------------------------------

//Definir os Tipos (ED)

array (vetor) -> elementos
topo (indexador)

*///---------------------------------------------------------------------------------------------------------

#define MAXTAM 8

typedef struct {
  int vetor[MAXTAM];
  int topo;
}PilhaEstatica;

//-----------------------------------------------------------------------------------------------------------

//Pilha Estática

//1 -> inicialização-----------------------------------------------------------------------------------------
void iniciaPilhaEstatica(PilhaEstatica *pilha){
  pilha->topo = 0;
  //A primeira posição para a inserção na pilha, é a posição 0 do vetor
}//iniciaPilhaEstatica

//2 -> está Vazia--------------------------------------------------------------------------------------------
bool estaVaziaPilhaEstatica(PilhaEstatica *pilha) {
  return(pilha->topo == 0);
}//estaVaziaPilhaEstatica

//3 -> está Cheia--------------------------------------------------------------------------------------------
bool estaCheiaPilhaEstatica(PilhaEstatica *pilha){
  return(pilha->topo == MAXTAM);
}//estaCheiaPilhaEstatica

//4 -> inserção (push / empilha)-----------------------------------------------------------------------------
void empilhaPilhaEstatica(PilhaEstatica *pilha, int x){
  //se a pilha não estiver cheia:
  if(!estaCheiaPilhaEstatica(pilha)) {
    //atribui o "x" no vetor na posição do topo
    pilha->vetor[pilha->topo] = x;
    //incrementa o topo (topo++)
    //pilha -> topo+=1
    pilha->topo++;
  }else{
    //Informa que não pode mais inserir
    printf("Não cabe mais nada parceiro\n");
  }
}//empilhaPilhaEstatica

//5 -> remoção (pop / desempilha)-----------------------------------------------------------------------------
void desempilhaPilhaEstatica(PilhaEstatica *pilha) {
  //inicializa uma variável auxiliar:
  int x = 0;
  //se a pilha não estiver vazia:
  if(!estaVaziaPilhaEstatica(pilha)) {
    //atribui a "x" o último valor válido da pilha
    x = pilha->vetor[pilha->topo-1];
    //decrementa topo
    pilha->topo--;
  }else{
    //Informa que não pode mais retirar
    printf("Não da pra tirar mais nada parceiro\n");
  }
}//desempilhaPilhaEstatica

//6 -> pesquisa/consulta (topo / top) - mostra o topo---------------------------------------------------------
int topoPilhaEstatica(PilhaEstatica *pilha) {
  return(pilha->vetor[pilha->topo-1]);
}//topoPilhaEstatica

//7 -> quantidade de elementos na estrutura-------------------------------------------------------------------
int tamanhoPilhaEstatica(PilhaEstatica *pilha) {
  return(pilha->topo);
}//tamanhoPilhaEstatica

//8 -> imprimir estrutura (print)-----------------------------------------------------------------------------
void imprimePilhaEstatica(PilhaEstatica *pilha) {
  //pilha->vetor, pilha->topo
  printf("Pilha = {");
  for(int i = 0; i < tamanhoPilhaEstatica(pilha); i++) {
    printf("%d", pilha->vetor[i]);
    if(i != tamanhoPilhaEstatica(pilha)-1){
      printf(" ");
    }//if
  }//for
  printf("}\n");
}//imprimePilhaEstatica

//------------------------------------------------------------------------------------------------------------

int main(int argc, char const *argv[]){

  PilhaEstatica p;
  iniciaPilhaEstatica(&p);
  printf("teste drive porra\n");

  //vazia
  if(estaVaziaPilhaEstatica(&p)){
    printf("Está vazia\n");
  }else{
    printf("Tem algo ai dentro\n");
  }//if

  //cheia
  if(estaCheiaPilhaEstatica(&p)){
    printf("Está cheia\n");
  }else{
    printf("Não esta cheia\n");
  }//if

  int tmp = tamanhoPilhaEstatica(&p);
  printf("Tamanho = %d\n", tmp);


  //8 elementos------------------------------------------------------------------------------------------------

  imprimePilhaEstatica(&p);
  //Pilha = {}-------------------------------------------------------------------------------------------------

  empilhaPilhaEstatica(&p, 7);
  imprimePilhaEstatica(&p);
  //Pilha = {7}------------------------------------------------------------------------------------------------

  empilhaPilhaEstatica(&p, 23);
  imprimePilhaEstatica(&p);
  //Pilha = {7 23}---------------------------------------------------------------------------------------------

  empilhaPilhaEstatica(&p, 10);
  imprimePilhaEstatica(&p);
  //Pilha = {7 23 10}------------------------------------------------------------------------------------------

  empilhaPilhaEstatica(&p, 47);
  imprimePilhaEstatica(&p);
  //Pilha = {7 23 10 47}---------------------------------------------------------------------------------------

  empilhaPilhaEstatica(&p, 19);
  imprimePilhaEstatica(&p);
  //Pilha = {7 23 10 47 19}------------------------------------------------------------------------------------

  empilhaPilhaEstatica(&p, 14);
  imprimePilhaEstatica(&p);
  //Pilha = {7 23 10 47 19 14}---------------------------------------------------------------------------------

  empilhaPilhaEstatica(&p, 41);
  imprimePilhaEstatica(&p);
  //Pilha = {7 23 10 47 19 14 41}------------------------------------------------------------------------------

  empilhaPilhaEstatica(&p, 4);
  imprimePilhaEstatica(&p);
  //Pilha = {7 23 10 47 19 14 41 4}----------------------------------------------------------------------------

  empilhaPilhaEstatica(&p, 69);
  imprimePilhaEstatica(&p);
  //Não cabe mais nada parceiro
  //Pilha = {7 23 10 47 19 14 41 4}----------------------------------------------------------------------------

  tmp = tamanhoPilhaEstatica(&p);
  printf("Tamanho = %d\n", tmp);

  for(int i = 0; i <= MAXTAM; i++){
    desempilhaPilhaEstatica(&p);
    imprimePilhaEstatica(&p);
  }

  return 0;

}
