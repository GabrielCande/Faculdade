/*
Faça um programa que receba do usuário um arquivo texto. Crie outro arquivo
texto de saída contendo o texto do arquivo de entrada original, porém substituindo todas as vogais pelo
caractere ‘*’. Além disso, mostre na tela quantas linhas esse arquivo possui. Dentro do programa faça
o controle de erros, isto é, insira comandos que mostre se os arquivos foram abertos com sucesso, e caso
contrário, imprima uma mensagem de erro encerrando o programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

  //declaração de variáveis
  char arquivo[21], caractere, *str;
  int linhas = 0;
  int x = 0;

  //pede o nome do arquivo que será utilizado para trabalhar e o abre
  printf("Digite o nome do arquivo:\n");
  fgets(arquivo, 21, stdin);
  arquivo[strcspn(arquivo, "\n")] = '\0';
  setbuf(stdin, NULL);
  FILE *arq = fopen(arquivo,"r");

  //verifica se houve um erro ao abrir o arquivo desejado
  if(arq == NULL){
    printf("Erro!\nFechando Programa\n\n");
    exit(1);
  }//if

  //aloca 1 byte para str
  str = malloc(1);

  //enquanto a variável caractere for do tamanho do arquivo e enquanto não atingiu seu fim
  while((caractere = fgetc(arq)) != EOF){

      //verifica cada caractere através da variável 'caractere' para saber a posição das vogais no arquivo de texto
      if(caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U'||
      caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u'){

        //substitui a posição das vogais caso vogal
        str[x] = '*';

      }else{

        //salva a posição como o caractere já existente
        str[x] = caractere;

      }//else

      //caso exista uma quebra de linha ('\n') ativa o contador de linhas
      if(caractere == '\n'){
        linhas++;
      }//if

    //a cada loop soma +1 na variável auxiliar x que é utilizada para definir o tamanho de str
    x++;

    //realoca o tamanho de str para continuar a realizar o loop
    str = realloc(str, x + 1);
  }//while

  //fecha o arquivo
  fclose(arq);

  //definição da string auxiliar para nomear o novo arquivo
  char censored[21] = "Censored_";

  //nomeia e abre o novo arquivo a ser gerado
  arq = fopen(strcat(censored, arquivo), "w");

  //verifica se houve um erro ao abrir o arquivo desejado
  if(arq == NULL){
    printf("Erro!\nFechando Programa\n\n");
    exit(1);
  }

  //atribuindo a str obtida no novo arquivo gerado
  fputs(str, arq);

  //liberando a str obtida para liberar memória
  free(str);

  //verifica se há erro na gravação do arquivo
  if(x == EOF){
    printf("Erro na gravação do arquivo\n\n");
  }

  //exibe a quantidade de linhas dentro do arquivo de texto digitado
  printf("Quantidade de linhas no arquivo de texto: %i\n", linhas);

  //fecha o novo arquivo gerado
  fclose(arq);

  return 0;
}//main
