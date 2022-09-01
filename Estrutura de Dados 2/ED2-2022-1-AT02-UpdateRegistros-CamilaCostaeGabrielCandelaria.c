//Declaração de Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Estrutura Professor
typedef struct{
  char ident[4];
  char nome[30];
  char sexo;
  int idade;
  char area[30];
  char telefone[15];
}Professor;


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


void DelReg(FILE* arq, char id[4]){
  //Move o ponteiro do arquivo para o início do mesmo
  rewind(arq);
  //Declaração de variável com estrutura Professor
  Professor p;
  //Variável contador recebe o valor da função contaLinha
  int contador = contaLinha(arq);
  //Declaração de variáveis
  int tam = 0, top = 0;
  char lixo[300];
  //Lê a primeira linha do arquivo e salva o valor de tam e top
  fscanf(arq, "size=%d top=%d", &tam, &top);
  //Move o ponteiro do arquivo para o início do mesmo
  rewind(arq);
  //Move o ponteiro do arquivo 15 posições após o início
  fseek(arq, 15, SEEK_SET);
  //Looping para percorrer todas as linhas do arquivo
  for(int i = 0; i < contador; i++){
    //Lê a linha i do arquivo e salva o código de identificação em p.ident e o resto na string lixo
    fscanf(arq, " %[^|]|%[^\n]\n", p.ident, lixo);
    //Caso o valor armazenado em id seja igual ao valor de p.ident
    if (strcmp(id, p.ident) == 0){
      //Move o ponteiro do arquivo 88 posições anteriores a posição atual
      fseek(arq, -88, SEEK_CUR);
      //Salva no começo do registro deletado o antigo valor do top
      fprintf(arq, "*%d|", top);
      //Move o ponteiro do arquivo para o início do mesmo
      rewind(arq);
      //Salva na primeira linha do arquivo o tam e o novo top(rrn do registro deletado)
      fprintf(arq, "size=%d top=%d ", tam, i);
      //Quebra a execução do looping
      break;
    }//if
  }//for
}//DelReg


void IncReg(FILE* arq, Professor p){
  //Move o ponteiro do arquivo para o início do mesmo
  rewind(arq);
  //Declaração de variáveis
  int tam = 0, top = 0, at_top = 0;
  char aux[90];
  //Lê a primeira linha do arquivo e salva o valor de tam e top
  fscanf(arq, "size=%d top=%d", &tam, &top);
  //Se o valor de top for igual a -1
  if (top == -1){
    //Move o ponteiro do arquivo para o final do mesmo
    fseek(arq, 0, SEEK_END);
    //Salva o novo registro no arquivo
    fprintf(arq, "%s|%-30s|%c|%d|%-30s|%s|\n", p.ident, p.nome, p.sexo, p.idade, p.area, p.telefone);
  }else{//Se não
    //Move o ponteiro do arquivo para (tam*top)+18 posições após o início
    fseek(arq, (tam*top)+18, SEEK_SET);
    //Lê o valor que está no início do registro para atualizar o top
    fscanf(arq, "*%d|%s\n", &at_top, aux);
    //Move o ponteiro do arquivo para (tam*top)+18 posições após o início
    fseek(arq, (tam*top)+18, SEEK_SET);
    //Salva o novo registro no arquivo
    fprintf(arq, "%s|%-30s|%c|%d|%-30s|%s|", p.ident, p.nome, p.sexo, p.idade, p.area, p.telefone);
    //Move o ponteiro do arquivo para o início do mesmo
    rewind(arq);
    //Salva na primeira linha do arquivo o tam e o top atualizado
    fprintf(arq, "size=%d top=%d ", tam, at_top);
  }//else
}//IncReg


void ComReg(FILE *arq, FILE *arqs){
  //Move o ponteiro do arquivo para o início do mesmo
  rewind(arq);
  //Declaração de variável com estrutura Professor
  Professor p;
  //Declaração de variáveis
  int tam, top, contador;
  char aux, teste, resto[200];
  //Variável contador recebe o valor da função contaLinha
  contador = contaLinha(arq);
  //Lê a primeira linha do arquivo temporário e salva o valor de tam e top
  fscanf(arq,"size=%d top=%d", &tam, &top);
  //Variável top recebe valor -1
  top = -1;
  //Salva no arquivo de saída o valor de tam e top
  fprintf(arqs,"size=%d top=%d\n", tam, top);
  //Move o ponteiro do arquivo temporário 15 posições após o início
  fseek(arq,15,SEEK_SET);
  //Looping para percorrer o arquivo temporário e salvar no arquivo de saída
  for(int i = 0; i < contador - 1; i++){
    //Lê a linha i do arquivo temporário e salva em p.ident e resto
    fscanf(arq, " %[^|]|%[^\n]\n", p.ident, resto);
    //Se o valor da posição 0 de p.ident for diferente de *
    if (p.ident[0] != '*'){
      //Salva no arquivo de saída p.ident e resto
      fprintf(arqs,"%s|%s\n", p.ident, resto);
    }//if
  }//for
}//ComReg


int main(int argc, char const *argv[]){
  //Abre e retorna um ponteiro para o arquivo de entrada
  FILE* entrada = fopen(argv[1], "r");
  //Abre e retorna um ponteiro para o arquivo de operações
  FILE* operacoes = fopen(argv[2], "r");
  //Abre e retorna um ponteiro para o arquivo temporário
  FILE* temp = fopen(argv[3], "w+");
  //Abre e retorna um ponteiro para o arquivo de saída
  FILE* saida = fopen(argv[4], "w");
  //Se a quantidade de parâmetros for diferente de 5
  if(argc!= 5) {
    //Exibe mensagem de erro
    printf("Quantidade de parametros invalida\n");
    //Encerra o programa retornando 0 como valor da função
    return 0;
  }//if
  //Verifica se existe erro na abertura dos arquivos
  if(entrada == NULL || saida == NULL || operacoes == NULL || temp == NULL) {
    //Exibe a mensagem de erro
    perror("Error ");
    //Encerra o programa retornando 0 como valor da função
    return 0;
  }//if
  //Declaração de variáveis
  char ler[100];
  char op, num[4];
  //Declaração de variável com estrutura Professor
  Professor p;
  //Lê os registros do arquivo de entrada enquanto não chegar ao final
  while (fgets(ler,100,entrada) != NULL) {
    //Salva os registros no arquivo temporário
    fputs(ler, temp);
  }//while
  //Variável op lê um char do arquivo de operações
  op = fgetc(operacoes);
  //Enquanto op não chegar ao fim do arquivo de operações
  while(op != EOF){
    //Move o ponteiro do arquivo para o início do mesmo
    rewind(temp);
    //Se o valor de op for d
    if(op == 'd'){
      //Lê do arquivo de operações o código do registro a ser deletado
      fscanf(operacoes, "%s\n", &num);
      //Chama a função de deletar registros
      DelReg(temp, num);
    }//if
    //Se o valor de op for i
    if(op == 'i'){
      //Lê do arquivo de operações as informações do registro a ser incluído
      fscanf(operacoes, " %[^,],%[^,],%c,%d,%[^,],%[^,\n]\n", p.ident, p.nome, &p.sexo, &p.idade, p.area, p.telefone);
      //Chama a função de incluir registros
      IncReg(temp, p);
    }//if
    //Se o valor de op não for d e nem i
    if(op != 'i' && op != 'd'){
      //Limpa a tela
      system("cls");
      //Exibe a mensagem de que ouve um erro na leitura do arquivo
      printf("\nErro de leitura no arquivo...\n\n");
      //Fecha todos os arquivos
      fclose(entrada);
      fclose(operacoes);
      fclose(temp);
      fclose(saida);
    }//if
    //Variável op lê um char do arquivo de operações
    op = fgetc(operacoes);
  }//while
  //Chama a função de compactar o arquivo
  ComReg(temp, saida);
  //Fecha todos os arquivos
  fclose(entrada);
  fclose(operacoes);
  fclose(temp);
  fclose(saida);
  //Encerra o programa retornando 0 como valor da função
  return 0;
}//main
