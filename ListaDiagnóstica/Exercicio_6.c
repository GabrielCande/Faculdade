/*
Como vimos na aula passada, um baralho normal frequentemente usado em vários jogos
para entretenimento pode ser codificado definindo dois tipos abstrato de dados:
• Carta: que representa uma carta física do baralho. Possui três atributos: símbolo/valor,
o naipe, e uma variável booleana indicando se a carta já foi jogada ou não;
• Baralho: uma estrutura que representa um conjunto de Cartas.
O código-fonte abaixo mostra possíveis definições para estas estruturas em linguagem C:
typedef struct {
char valor;
char naipe;
bool foiJogada;
} Carta;
typedef struct {
Carta array[54];
} Baralho;
Entretanto, apenas a definição dos tipos não garante a modelagem completa do objeto Baralho.
Para que um baralho seja manipulado adequadamente ele precisa de funções/métodos que mudem
seu estado/configuração. Por exemplo, temos que: criar o baralho, adicionando as cartas;
consultar a carta do topo ou fundo; embaralhar novamente as cartas; retirar cartas e entregar
para os jogadores, etc. A tabela abaixo mostra algumas funções que podem manipular esse tipo
de objeto:
Função Descrição
void criaBaralho(Baralho *baralho); inicia um novo baralho criando todas as cartas nele contido.
int cartasNaoJogadas(Baralho *baralho); Consulta o número de cartas disponíveis para jogo.
Carta topo(Baralho *baralho); Consulta a carta do topo de um baralho.
Carta fundo(Baralho *baralho); Consulta a carta do fundo de um baralho.
Carta* carteado(Baralho *baralho); Retorna um array com 3 cartas aleatórias para um jogador;
Tabela 1: Operações básicas com uma baralho
Assim sendo, escreva funções em C para simular os comportamentos listados na Tabela 1. Adicione comandos
na função principal que testem e validem todas as funções implementadas.
*/

//Declaração de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Estrutura da Carta
typedef struct{

  char valor;
  char naipe;
  bool foiJogada;

}Carta;

//Vetor de Variáveis Globais com os valores e naipes possíveis para uma carta
char valores[13] = {'A','2','3','4','5','6','7','8','9','D','J','Q','K'};
char naipes[4] = {'P','E','C','O'};

//Função criaBaralho
void criaBaralho(Carta baralho[4][13]){
  //Looping que preenche uma matriz com todas as cartas contidas em um baralho
  for(int i = 0;i < 4; i++){
    for(int j = 0;j < 13;j++){
      //Armazena um naipe de carta em cada linha da matriz
      baralho[i][j].naipe = naipes[i];
      //Armazena um valor de carta em cada coluna da matriz
      baralho[i][j].valor = valores[j];
      //Armazena que as cartas não foram jogadas ainda
      baralho[i][j].foiJogada = false;
    }//for interno
  }//for externo
  //Retorna a função
  return;
}//criaBaralho

//Função cartasNaoJogadas
int cartasNaoJogadas(Carta baralho[4][13]){
  //Declaração de contador para verificar quantas cartas ainda não foram jogadas
  int qtdcartas = 0;
  //Looping para percorrer cada posição da matriz desde o começo do baralho
  for(int i = 0;i < 4; i++){
    for(int j = 0;j < 13;j++){
      //Condição que mostra que a carta ainda não foi jogada
      if (baralho[i][j].foiJogada == false) {
        //Incrementa no contador qtdcartas
        qtdcartas++;
      }//if
    }//for interno
  }//for externo
  //Retorna qtdcartas como valor da função
  return qtdcartas;
}//cartasNaoJogadas

//Função topo
void topo(Carta baralho[4][13]){
  //Looping para percorrer cada posição da matriz desde o começo do baralho
  for(int i = 0;i < 4; i++){
    for(int j = 0;j < 13;j++){
      //Condição que encontra a primeira carta do baralho que ainda não foi jogada
      if (baralho[i][j].foiJogada == false) {
        //Exibe a carta do topo do baralho
        printf("A carta do topo e [%c %c]\n", baralho[i][j].valor, baralho[i][j].naipe);
        //Retorna a função depois de encontrar a carta do topo
        return;
      }//if
    }//for interno
  }//for externo
}//topo

//Função fundo
void fundo(Carta baralho[4][13]){
  //Looping para percorrer cada posição da matriz desde o fim do baralho
  for(int i = 3;i >= 0; i--){
    for(int j = 12;j >= 0; j--){
      //Condição que encontra a última carta do baralho que ainda não foi jogada
      if (baralho[i][j].foiJogada == false) {
        //Exibe a carta do fundo do baralho
        printf("A carta do fundo e [%c %c]\n", baralho[i][j].valor, baralho[i][j].naipe);
        //Retorna a função depois de encontrar a carta do fundo
        return;
      }//if
    }//for interno
  }//for externo
}//fundo

//Função carteado
void carteado(Carta baralho[4][13], int nJogadores){
  //Declaração de contador, e variáveis
  int contador = 0, linha, coluna;
  int linhaV, colunaV;
  //Limpa o buffer do teclado
  fflush(stdin);
  //Espaçamento
  printf("\n");
  //Função para gerar números aleatórios
  srand(time(NULL));
  printf("\n---------------\n");
  printf("Vira da rodada:\n");
  //Gera uma linha e uma coluna aleatória para encontrar uma carta para ser a Vira
  linhaV = rand() % 4;
  colunaV = rand() % 13;
  //Exibe a Vira
  printf("[%c %c]", baralho[linhaV][colunaV].valor, baralho[linhaV][colunaV].naipe);
  //Armazena que a Vira já foi jogada
  baralho[linhaV][colunaV].foiJogada = true;
  printf("\n---------------\n");
  //Looping para distribuir as cartas para nJogadores
  for (int i = 0; i < nJogadores; i++) {
    printf("\n---------------\n");
    //Exibe qual jogador vai receber as cartas
    printf("Jogador %i: \n", i+1);
    do{
      //Gera uma linha e uma coluna aleatória para encontrar uma carta para o jogador i
      linha = rand() % 4;
      coluna = rand() % 13;
      //Condição que verifica se a carta encontrada ainda não foi jogada
      if(baralho[linha][coluna].foiJogada == false){
        //Armazena que a carta encontrada foi jogada
        baralho[linha][coluna].foiJogada = true;
        //Limpa o buffer do teclado
        fflush(stdin);
        //Exibe a carta encontrada para o jogador i
        printf("[%c %c]", baralho[linha][coluna].valor, baralho[linha][coluna].naipe);
        //Incrementa no contador que verifica que cada jogador receba 3 cartas
        contador++;
      }//if
    //Condição para que cada jogador receba 3 cartas
    }while(contador != 3);
    printf("\n---------------\n");
    //Contador reinicia
    contador = 0;
  }//for
  //Espaçamento
  printf("\n");
}//carteado

//Função Principal
int main(){
  //Declaração de variáveis
  int qtdcartas, opcao, nJogadores;
  //Declaração de uma matriz com a estrutura Carta
  Carta baralho[4][13];

  do {
    //Exibe o menu de opções
    printf("|--------- Menu Jogo de Baralho ---------|\n");
    printf("|--------- 1- Iniciar Novo Jogo ---------|\n");
    printf("|--------- 2- Distribuir Cartas ---------|\n");
    printf("|--- 3- Quantidade Cartas Disponiveis ---|\n");
    printf("|------ 4- Verificar Carta no Topo ------|\n");
    printf("|------- 5- Verificar Carta Fundo -------|\n");
    printf("|------------ 6- Sair do Jogo -----------|\n");
    //Espaçamento
    printf("\n");
    //Pergunta ao usuário qual opção ele deseja
    printf("Qual a opcao desejada? ");
    //Armazena a escolha do usuário na variável opcao
    scanf("%i", &opcao);
    //Limpa o buffer do teclado
    fflush(stdin);
    //Compara os valores da variável opcao
    switch (opcao) {
      //Caso valor de opcao seja 1
      case 1:
        //Chama a função criaBaralho
        criaBaralho(baralho);
        //Solicita que o usuário digite a quantidade de jogadores
        printf("Digite o numero de jogadores: ");
        //Armazena a quantidade de jogadores na variável nJogadores
        scanf("%i", &nJogadores);
        //Limpa a tela
        system("cls || clear");
        //Condição para que a quantidade de jogadores seja 2, 4 ou 6
        while(nJogadores != 2 && nJogadores != 4 && nJogadores != 6){
          //Limpa a tela
          system("cls || clear");
          //Exibe que a quantidade de jogadores digitada não é possível de iniciar um jogo
          printf("Numero de jogadores incapaz de iniciar o jogo...\n");
          //Solicita que o usuário digite novamente a quantidade de jogadores
          printf("Digite o numero de jogadores novamente: ");
          //Armazena a nova quantidade de jogadores na variável nJogadores
          scanf("%i", &nJogadores);
          //Espaçamento
          printf("\n");
        }//while
      //Término do case 1
      break;
      //Caso valor de opcao seja 2
      case 2:
        //Limpa a tela
        system("cls || clear");
        //Chama a função carteado
        carteado(baralho, nJogadores);
        //Looping para percorrer cada posição da matriz desde o fim do baralho
        for(int i = 3;i >= 0; i--){
          for(int j = 12;j >= 0; j--){
            //Condição que encontra as cartas já jogadas
            if(baralho[i][j].foiJogada == true){
              //Devolve as cartas já jogadas para o baralho
              baralho[i][j].foiJogada = false;
            }//if
          }//for interno
        }//for externo
      //Término do case 2
      break;
      //Caso valor de opcao seja 3
      case 3:
        //Limpa a tela
        system("cls || clear");
        //Variável qtdcartas recebe o valor da função cartasNaoJogadas
        qtdcartas = cartasNaoJogadas(baralho);
        //Exibe a quantidade de cartas disponíveis para jogo
        printf("A quantidade de cartas disponiveis para jogar e de %i\n", qtdcartas);
        //Espaçamento
        printf("\n");
      //Término do case 3
      break;
      //Caso valor de opcao seja 4
      case 4:
        //Limpa a tela
        system("cls || clear");
        //Chama a função topo
        topo(baralho);
        //Espaçamento
        printf("\n");
      //Término do case 4
      break;
      //Caso valor de opcao seja 5
      case 5:
        //Limpa a tela
        system("cls || clear");
        //Chama a função fundo
        fundo(baralho);
        //Espaçamento
        printf("\n");
      //Término do case 5
      break;
      //Caso valor de opcao seja 6
      case 6:
        //Limpa a tela
        system("cls || clear");
        //Exibe a mensagem de que está saindo do programa
        printf("Saindo...\n");
        //Espaçamento
        printf("\n");
      //Término do case 6
      break;
      //Caso valor de opcao não esteja no intervalo [1;6]
      default:
        //Exibe que o valor da opcao digitada não é válida
        printf("Opcao Invalida! Tente Novamente...\n");
        //Espaçamento
        printf("\n");
      //Término do default
      break;
    }//switch
  //Condição que repete o menu enquanto o valor de opcao for diferente de 6
  }while(opcao != 6);
  //Retorna 0 como valor da função
  return 0;
}//main
