/*
Escreva uma função recursiva para calcular o valor de um número inteiro de base
x elevada a um expoente inteiro y.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//função recursiva
int func_elevar(int x, int y){

  //verifica o se o expoente y é diferente de 0
  if(y != 0){

    //retorna a base multiplicando ela mesma elavada ao expoente menos 1
    return x * func_elevar(x, y -1);

  }else{

    //se o expoente for zero automaticamente retorna 1
    return 1;
  }//else
}//func_elevar

int main(){

  //declaração de variáveis
  int x, y;

  //pede e salva a base e o expoente
  printf("Digitite a base: ");
  scanf("%i", &x);
  printf("Digitite o expoente: ");
  scanf("%i", &y);

  //exibe o resultado da operação em questão
  printf("A base elevada ao expoente resulta em %i\n", func_elevar(x, y));

  return 0;
}//main
