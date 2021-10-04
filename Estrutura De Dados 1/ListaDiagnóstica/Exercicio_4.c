/*
Faça um programa que leia um valor N e crie dinamicamente um
vetor com essa quantidade de elementos. Em seguida, passe esse vetor para uma função que vai ler os
elementos desse vetor. Depois, no programa principal, imprima os valores do vetor preenchido. Além disso,
antes de finalizar o programa, lembre-se de liberar a área de memória alocada para armazenar os valores do
vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//função que vai criar um vetor dinâmicamente conforme o tamanho digitado na main
int CriaVetor(int valorN){
  int *vetor;

  vetor = (int*) malloc(valorN * sizeof(int));

  return vetor;
}//CriaVetor

//função que vai pedir, ler e armazenar os valores do vetor a serem preenchidos
void LeElementos(int *vetor, int valorN){
  for(int i = 0; i < valorN; i++){
    printf("Digite o valor da posição %i do vetor: ", i+1);
    scanf("%i", &vetor[i]);
  }
}//LeElementos

int main(){

  //declaração de variáveis
  int *vetor, valorN;

  //pede e armazena o tamanho do vetor a ser criado
  printf("Digite o tamanho do vetor a ser criado: ");
  scanf("%i", &valorN);
  printf("\n");

  //utiliza a funcão CriaVetor para criar e atribuir um vetor a variável vetor da main
  vetor = CriaVetor(valorN);

  //utiliza a função LeElementos para pedir, ler e armazenar os elementos do vetor que serão preenchidos
  LeElementos(vetor, valorN);
  printf("\n\n");

  //for para exibir todos os espaços presentes no vetor que foram preenchidos anteriormente
  for(int i = 0; i < valorN; i++){
    printf("Vetor %i : %i\n", i+1, vetor[i]);
  }
  printf("\n\n");

  //libera o vetor para liberação de memória
  free(vetor);
  vetor = NULL;

  return 0;
}//main
