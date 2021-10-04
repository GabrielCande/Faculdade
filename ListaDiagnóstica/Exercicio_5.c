/*
Defina um tipo abstrato de dados que irá representar bandas de música.
Essa estrutura deve ter o nome da banda, que tipo de música ela toca, o número de integrantes, e em que
posição do ranking essa banda está dentre as suas 5 bandas favoritas.
a) Crie uma função para preencher as 5 estruturas de bandas criadas no exemplo passado;
b) Após criar e preencher, exiba todas as informações das bandas/estruturas. Não se esqueça de usar o
operador → para preencher os membros das structs;
página 1 de 2
c) Crie uma função que peça ao usuário um nímero de 1 até 5. Em seguida, seu programa deve exibir
informações da banda cuja posição no seu ranking é a que foi solicitada pelo usuário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//struct de Bandas
typedef struct{
  char nome[21];
  char genero[21];
  int integrantes;
  int ranking;
}Bandas;

//função que preenche banda
void PreencheStruct(Bandas *banda){
  for(int i = 0; i < 5; i++){

    printf("--A respeito da Banda %i--\n\n", i+1);

    printf("Digite o nome da Banda: ");
    fgets(banda[i].nome, 21, stdin);
    banda[i].nome[strcspn(banda[i].nome, "\n")] = '\0';
    fflush(stdin);

    printf("Digite o genero da Banda: ");
    fgets(banda[i].genero, 21, stdin);
    banda[i].genero[strcspn(banda[i].genero, "\n")] = '\0';
    fflush(stdin);

    printf("Digite o numero de integrantes da Banda: ", i+1);
    scanf("%i", &banda[i].integrantes);
    fflush(stdin);

    printf("Digite o ranking da Banda dentre as favoritas: ", i+1);
    scanf("%i", &banda[i].ranking);
    fflush(stdin);

    printf("-------------------------\n");

  }//for
}//PreencheStruct

//função que imprime todas as Bandas
void ExibeStruct(Bandas *banda){
  for(int i = 0; i < 5; i++){
    printf("x------------------------------Banda %i------------------------------x\n\n", i+1);
    printf("%s\n", banda[i].nome);
    printf("Genero -> %s\n", banda[i].genero);
    printf("Possui %i integrantes\n", banda[i].integrantes);
    printf("Classificacao no ranking de favoritas -> %i\n", banda[i].ranking);
    printf("x--------------------------------------------------------------------x\n\n\n");
  }//for
}//ExibeStruct

//função que exibe a Banda conforme seu ranking de favoritas
void ExibePorRanking(Bandas *banda){
  int opcao;

  do{
    printf("Digite a classificacao da Banda no ranking de favoritas que deseja visualizar: ");
    scanf("%i", &opcao);
    printf("\n");
    for(int i = 0; i < 5; i++){
      if(opcao == banda[i].ranking){
        printf("%s\n", banda[i].nome);
        printf("Genero -> %s\n", banda[i].genero);
        printf("Possui %i integrantes\n", banda[i].integrantes);
        printf("\n");
      }//if
    }//for
    printf("Digite 0 caso nao queira visualizar mais Bandas.\n\n")
  }while(opcao >= 1 && opcao <= 5);
}//ExibePorRanking


int main(){

  //declaração de variáveis
  Bandas banda[5];
  int x;

  //chamada de funções
  PreencheStruct(&banda[0]);
  ExibeStruct(&banda[0]);

  //enquanto digitar 1 será possível pesquisar por bandas em função de seu ranking
  do{

    //chamada de função
    ExibePorRanking(&banda[0]);
    printf("\n\n");
    printf("Pressione 1 para continuar com o programa e qualquer outro numero para finalizar: ");
    scanf("%i", &x);

  }while(x == 1);
  return 0;
}//main
