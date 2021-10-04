/*
Um ponteiro pode ser usado para dizer a uma função onde ela deve depositar
o resultado de seus cálculos. Escreva uma função que converta uma quantidade de minutos na notação
horas/minutos. A função recebe como parâmetro:
• um número inteiro (totalMinutos); e
• os endereços de duas variáveis inteiras, horas e minutos.
A função deve então atribuir valores às variáveis passadas por referência, de modo que os valores atribuídos
respeitem as seguintes condições:
minutos < 60
60 ∗ horas + minutos = totalMinutos
Escreva também a função principal (main) que use a função desenvolvida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//função para converter os minutos
void conversor(int totalMinutos, int* horas, int* minutos){

    //enquanto os minutos forem maiores que 60
    while(totalMinutos >= 60){

      //horas mais 1
      *horas = *horas + 1;

      //minutos menos 60
      totalMinutos = totalMinutos - 60;

    }//while

  //o valor restante dos minutos, menor que 60, é salvo
  *minutos = totalMinutos;

}//função conversor

int main(){

  //declarando as variáveis
  int totalMinutos, horas = 0, minutos = 0;

  //pedindo os minutos para serem convertidos
  printf("Digite uma quantidade de minutos para ser convertida:\n");

  //adiquirindo os minutos
  scanf("%i",&totalMinutos);

  //chamando a função usando as variáveis declaradas
  conversor (totalMinutos, &horas, &minutos);

  //printando o resultado da conversão
  printf("%i : %i",horas, minutos);

return 0;
}//main
