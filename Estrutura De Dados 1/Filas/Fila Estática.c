//Declaração de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//-----------------------------------------------------------------------------
//----------------------------Estrutura da Fila--------------------------------


#define MAXTAM  5

typedef struct {
  int vetor[MAXTAM];
  int qtdeElementos;
  int inicio;
  int fim;
} FilaEstatica;


//-----------------------------------------------------------------------------
//------------------------Funções da Fila Estática-----------------------------


void iniciaFilaEstatica(FilaEstatica *fila) {
  //Inicializa a fila com 0 elementos
  fila->qtdeElementos = 0;
  //Inicializa o inicio apontando para 0
  fila->inicio = 0;
  //Inicializa o fim apontando para -1
  fila->fim = -1;
}//iniciaFilaEstatica


bool estaVaziaFilaEstatica(FilaEstatica *fila) {
  //Analisa se a quantidade de elementos é igual a 0
  return(fila->qtdeElementos == 0);
}//estaVaziaFilaEstatica


bool estaCheiaFilaEstatica(FilaEstatica *fila) {
  //Analisa se a quantidade de elementos é igual ao tamanho máximo
  return(fila->qtdeElementos == MAXTAM);
}//estaCheiaFilaEstatica


int incrementaIndice(int i) {
  //Declara uma variável que retornará um valor 0 (caso tenha atingido a capacidade máxima de tamanho do vetor), ou incrementará no índice
  int novoValor = (i+1) % MAXTAM;
  //Retorna o valor da variável
  return novoValor;
}//incrementaIndice


void enfileiraFilaEstatica(FilaEstatica *fila, int x) {
  //Verifica se não está cheia, para poder inserir mais elementos
  if(!estaCheiaFilaEstatica(fila)) {
    //Incrementa o fim com a função incrementaIndice para verificar se atingiu a capacidade máxima da fila ou se incrementará o fim
    fila->fim = incrementaIndice(fila->fim);
    //Atribui o novo elemento na posição final do vetor
    fila->vetor[fila->fim] = x;
    //Incrementa a quantidade de elementos na fila
    fila->qtdeElementos++;
  }//if
}//enfileiraFilaEstatica


int tamanhoFilaEstatica(FilaEstatica *fila) {
  //Função que verifica o tamanho da fila e retorna seu valor
  return (fila->qtdeElementos);
}//tamanhoFilaEstatica


void imprimeFilaEstatica(FilaEstatica *fila) {
  printf("Fila = { ");
  //Looping enquanto uma variável i é menor que o tamanho da fila
  for(int i = 0; i < tamanhoFilaEstatica(fila); i++) {
    //Retorna o resto da divisão do indice de inicio da fila mais a variável i com a quantidade de tamamnho máxima da fila
    int indice = (fila->inicio + i) % MAXTAM;
    //Escreve o vetor na posição obtida da variável que armazena o resultado do calculo anteior
    printf("%d ", fila->vetor[indice]);
  }//for
  printf("}\n");
}//imprimeFilaEstatica


int desenfileiraFilaEstatica(FilaEstatica *fila) {
  //Declara uma variável auxiliar e a inicializa
  int ret = 0;
  //Verifica se a fila não está vazia
  if(!estaVaziaFilaEstatica(fila)) {
    //Salva na variável auxiliar o valor que será retornado (desenfileirado)
    ret = fila->vetor[fila->inicio];
    //Retorna o resto da divisão do indice de inicio da fila mais a variável i com a quantidade de tamamnho máxima da fila e salva como índice inicio
    fila->inicio = incrementaIndice(fila->inicio);
    //Decresce a quantidade de elementos da fila
    fila->qtdeElementos--;
  //Caso a fila estiver vazia
  }else{
    //Escreve o erro
    printf("WARNING: Não existem elementos na fila\n");
  }//else
  return(ret);
}//desenfileiraFilaEstatica


int primeiroFilaEstatica(FilaEstatica *fila) {
  //Retorna a posição inicio do vetor da fila
  return(fila->vetor[fila->inicio]);
}//primeiroFilaEstatica


int ultimoFilaEstatica(FilaEstatica *fila) {
  //Retorna a posição fim do vetor da fila
  return(fila->vetor[fila->fim]);
}//ultimoFilaEstatica


//-----------------------------------------------------------------------------
//----------------------------Função Principal---------------------------------

//Para Testes:
int main(int argc, char const *argv[]) {
  FilaEstatica f;
  iniciaFilaEstatica(&f);
  if(estaCheiaFilaEstatica(&f)) {
    printf("Está vazia!\n");
  }//if
  if(!estaCheiaFilaEstatica(&f)) {
    printf("Não está cheia!\n");
  }

  enfileiraFilaEstatica(&f, 5);
  imprimeFilaEstatica(&f);
  enfileiraFilaEstatica(&f, 7);
  imprimeFilaEstatica(&f);
  enfileiraFilaEstatica(&f, 20);
  imprimeFilaEstatica(&f);
  enfileiraFilaEstatica(&f, -99);
  imprimeFilaEstatica(&f);
  enfileiraFilaEstatica(&f, 0);
  imprimeFilaEstatica(&f);
  enfileiraFilaEstatica(&f, 10);
  // 5x 7x 20x -99 0

  int removido;
  removido = desenfileiraFilaEstatica(&f);
  imprimeFilaEstatica(&f);
  removido = desenfileiraFilaEstatica(&f);
  imprimeFilaEstatica(&f);
  removido = desenfileiraFilaEstatica(&f);
  imprimeFilaEstatica(&f);

  enfileiraFilaEstatica(&f, 16);
  imprimeFilaEstatica(&f);
  enfileiraFilaEstatica(&f, 23);
  imprimeFilaEstatica(&f);
  enfileiraFilaEstatica(&f, 42);
  imprimeFilaEstatica(&f);
  //  16 23 42(f) -99(i) 0 -> -99 0 12 23 42

  printf("Tamanho = %d\n", tamanhoFilaEstatica(&f));
  printf("-> Sucesso\n");

  return 0;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
