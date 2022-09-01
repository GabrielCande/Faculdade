//Declaração de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura Musica
typedef  struct{
  char ano[5];
  char duracao[6];
  char titulo[31];
  char artista[21];
  char genero[12];
  char idioma[12];
}Musica;

int contaLinha(FILE* arq) {
  //Declaração de char que percorre o arquivo e contador
  char percorre;
  int contalinha = 0;
  while((percorre = getc(arq)) != EOF ){
    if(percorre == '\n') contalinha++;
  }//while
  //Move o ponteiro do arquivo para o início do mesmo
  rewind(arq);
  //Retorna o valor de contaLinha como valor da função
  return contalinha;
}//contaLinha

void CompAno(char procura[31], Musica* s, int quant, FILE* arq){
  //Declaração de contador
  int cont = 0;
  //Looping para percorrer as posições do vetor s
  for (int i = 0; i < quant; i++) {
    //Verifica se a string procura é uma substring de s[i].ano
    if (strstr(s[i].ano,procura) != NULL) {
      //Salva as informações da música no arquivo de saída
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementação no contador
      cont--;
    }//if
    //Incrementação no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de saída que não foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompAno

void CompTitulo(char procura[31], Musica* s, int quant, FILE* arq){
  //Declaração de uma string auxiliar, duas variáveis e um contador
  char aux[31];
  int j = 0, k = 0, cont = 0;
  //Enquanto não chegar ao fim da string procura
  while (procura[j] != '\0') {
    //O char na posição j da string recebe o mesmo char em uppercase
    procura[j] = toupper(procura[j]);
    //Incrementação no valor de j
    j++;
  }//while
  //Looping para percorrer as posições do vetor s
  for (int i = 0; i < quant; i++) {
    //Copia o conteúdo da string s[i].titulo na string auxiliar
    strcpy(aux, s[i].titulo);
    //Enquanto não chegar ao fim da string auxiliar
    while (aux[k] != '\0') {
      //O char na posição k da string recebe o mesmo char em uppercase
      aux[k] = toupper(aux[k]);
      //Incrementação no valor de k
      k++;
    }//while
    //Verifica se a string procura é uma substring de aux
    if (strstr(aux,procura) != NULL) {
      //Salva as informações da música no arquivo de saída
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementação no contador
      cont--;
    }//if
    //Variável k recebe zero
    k = 0;
    //Incrementação no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de saída que não foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompTitulo

void CompArtista(char procura[31], Musica* s, int quant, FILE* arq){
  //Declaração de uma string auxiliar, duas variáveis e um contador
  char aux[21];
  int j = 0, k = 0, cont = 0;
  //Enquanto não chegar ao fim da string procura
  while (procura[j] != '\0') {
    //O char na posição j da string recebe o mesmo char em uppercase
    procura[j] = toupper(procura[j]);
    //Incrementação no valor de j
    j++;
  }//while
  //Looping para percorrer as posições do vetor s
  for (int i = 0; i < quant; i++) {
    //Copia o conteúdo da string s[i].artista na string auxiliar
    strcpy(aux, s[i].artista);
    //Enquanto não chegar ao fim da string auxiliar
    while (aux[k] != '\0') {
      //O char na posição k da string recebe o mesmo char em uppercase
      aux[k] = toupper(aux[k]);
      //Incrementação no valor de k
      k++;
    }//while
    //Verifica se a string procura é uma substring de aux
    if (strstr(aux,procura) != NULL) {
      //Salva as informações da música no arquivo de saída
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementação no contador
      cont--;
    }//if
    //Variável k recebe zero
    k = 0;
    //Incrementação no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de saída que não foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompArtista

void CompGenero(char procura[31], Musica* s, int quant, FILE* arq){
  //Declaração de uma string auxiliar, duas variáveis e um contador
  char aux[12];
  int j = 0, k = 0, cont = 0;
  //Enquanto não chegar ao fim da string procura
  while (procura[j] != '\0') {
    //O char na posição j da string recebe o mesmo char em uppercase
    procura[j] = toupper(procura[j]);
    //Incrementação no valor de j
    j++;
  }//while
  //Looping para percorrer as posições do vetor s
  for (int i = 0; i < quant; i++) {
    //Copia o conteúdo da string s[i].genero na string auxiliar
    strcpy(aux, s[i].genero);
    //Enquanto não chegar ao fim da string auxiliar
    while (aux[k] != '\0') {
      //O char na posição k da string recebe o mesmo char em uppercase
      aux[k] = toupper(aux[k]);
      //Incrementação no valor de k
      k++;
    }//while
    //Verifica se a string procura é uma substring de aux
    if (strstr(aux,procura) != NULL) {
      //Salva as informações da música no arquivo de saída
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementação no contador
      cont--;
    }//if
    //Variável k recebe zero
    k = 0;
    //Incrementação no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de saída que não foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompGenero

void CompIdioma(char procura[31], Musica* s, int quant, FILE* arq){
  //Declaração de uma string auxiliar, duas variáveis e um contador
  char aux[12];
  int j = 0, k = 0, cont = 0;
  //Enquanto não chegar ao fim da string procura
  while (procura[j] != '\0') {
    //O char na posição j da string recebe o mesmo char em uppercase
    procura[j] = toupper(procura[j]);
    //Incrementação no valor de j
    j++;
  }//while
  //Looping para percorrer as posições do vetor s
  for (int i = 0; i < quant; i++) {
    //Copia o conteúdo da string s[i].idioma na string auxiliar
    strcpy(aux, s[i].idioma);
    //Enquanto não chegar ao fim da string auxiliar
    while (aux[k] != '\0') {
      //O char na posição k da string recebe o mesmo char em uppercase
      aux[k] = toupper(aux[k]);
      //Incrementação no valor de k
      k++;
    }//while
    //Verifica se a string procura é uma substring de aux
    if (strstr(aux,procura) != NULL) {
      //Salva as informações da música no arquivo de saída
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementação no contador
      cont--;
    }//if
    //Variável k recebe zero
    k = 0;
    //Incrementação no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de saída que não foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompIdioma

int main(int argc, char const *argv[]) {
  //Condição para verificar se 3 arquivos (entrada, busca e saída) foram inseridos
  if (argc != 4) {
    //Exibe que a quantidade de paramêtros é inválida
    printf("Quantidade de paramêtros inválida!\n");
    //Retorna 0 como valor da função e encerra o programa
    return 0;
  }//if
  //Abre e retorna um ponteiro para cada arquivo
  FILE* entrada = fopen(argv[1],"r");
  FILE* busca = fopen(argv[2],"r");
  FILE* saida = fopen(argv[3],"w");
  //Verifica se existe erro na abertura dos arquivos
  if(entrada == NULL || busca == NULL || saida == NULL){
    //Exibe a mensagem de erro
    perror("Error ");
    //Retorna 0 como valor da função e encerra o programa
    return 0;
  }//if
  //Declaração de variáveis
  int size = 0, top = 0, quant = 0, linhas = 0, status = 0;
  //Variavél linhas recebe o valor da função contaLinha
  linhas = contaLinha(entrada);
  //Lê o header do arquivo de entrada e armazena as informações nas variáveis
  fscanf(entrada, "SIZE=%d TOP=%d QTDE=%d STATUS=%d", &size, &top, &quant, &status);
  //Se o número de linhas for diferente da quantidade de registros + header
  if (linhas != (quant + 1)) {
   //Salva no arquivo de saída que o arquivo é invalido
   fprintf(saida, "Arquivo Inválido!\n");
   //Fecha os arquivos
   fclose(entrada);
   fclose(busca);
   fclose(saida);
   //Retorna 0 como valor da função e encerra o programa
   return 0;
 }//if
  //Variavél linhas recebe o valor da função contaLinha
  linhas = contaLinha(busca);
  //Se o número de linhas do arquivo de busca for diferente de 2
  if (linhas != 2) {
   //Salva no arquivo de saída que o arquivo é invalido
   fprintf(saida, "Arquivo Inválido!\n");
   //Fecha os arquivos
   fclose(entrada);
   fclose(busca);
   fclose(saida);
   //Retorna 0 como valor da função e encerra o programa
   return 0;
  }//if
  //Declaração de vetor s de tamanho quant com estrutura Musica
  Musica s[quant];
  //Looping para percorrer os vetores
  for(int i = 0; i < quant; i++){
    //Lê do arquivo de entrada as informações presentes em uma linha e salva na posição i do vetor s
    fscanf(entrada, "\n%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
  }//for
  //Declaração de strings
  char campo[10];
  char procura[31];
  //Armazena na string campo o campo em que o usuário quer buscar uma informação
  fscanf(busca, "%s\n", campo);
  //Armazena na string procura a informação que o usuário quer buscar
  fscanf(busca, "%[^\n]", procura);
  //Verifica se o usuário quer o campo ano
  if (strcasecmp(campo,"ano") == 0) {
    //Chama a função CompAno
    CompAno(procura, s, quant, saida);
  }//if
  //Verifica se o usuário quer o campo titulo
  if (strcasecmp(campo,"titulo") == 0) {
    //Chama a função CompTitulo
    CompTitulo(procura, s, quant, saida);
  }//if
  //Verifica se o usuário quer o campo artista
  if (strcasecmp(campo,"artista") == 0) {
    //Chama a função CompArtista
    CompArtista(procura, s, quant, saida);
  }//if
  //Verifica se o usuário quer o campo genero
  if (strcasecmp(campo,"genero") == 0) {
    //Chama a função CompGenero
    CompGenero(procura, s, quant, saida);
  }//if
  //Verifica se o usuário quer o campo idioma
  if (strcasecmp(campo,"idioma") == 0) {
    //Chama a função CompIdioma
    CompIdioma(procura, s, quant, saida);
  }//if
  //Se o usuário não procura uma informação em nenhum dos campos descritos acima
  if (strcasecmp(campo,"ano") != 0 && strcasecmp(campo,"titulo") != 0 && strcasecmp(campo,"artista") != 0 && strcasecmp(campo,"genero") != 0 && strcasecmp(campo,"idioma") != 0) {
    //Salva no arquivo de saída que o arquivo é invalido
    fprintf(saida, "Arquivo Inválido!\n");
  }//if
  //Fecha os arquivos
  fclose(entrada);
  fclose(busca);
  fclose(saida);
  //Retorna 0 como valor da função e encerra o programa
  return 0;
}//main
