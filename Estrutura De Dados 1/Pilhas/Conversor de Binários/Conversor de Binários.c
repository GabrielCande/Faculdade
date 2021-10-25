//Declaração de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAXTAM 10000

typedef struct {
  int vetor[MAXTAM];
  int topo;
}PilhaEstatica;

typedef struct NoPilha* PtrNoPilha;

typedef struct NoPilha{
  int chave;
  PtrNoPilha proximo;
}NoPilha;

typedef struct{
  PtrNoPilha topo;
  int tamanho;
}PilhaDinamica;


//-----------------------------------------------------------------------------
//------------------------Funções da Pilha Estática----------------------------


void iniciaPilhaEstatica(PilhaEstatica *pilha){
  pilha->topo = 0;
  //A primeira posição para a inserção na pilha, é a posição 0 do vetor
}//iniciaPilhaEstatica


bool estaVaziaPilhaEstatica(PilhaEstatica *pilha){
  return(pilha->topo == 0);
}//estaVaziaPilhaEstatica


bool estaCheiaPilhaEstatica(PilhaEstatica *pilha){
  return(pilha->topo == MAXTAM);
}//estaCheiaPilhaEstatica


void empilhaPilhaEstatica(PilhaEstatica *pilha, int x){
  //Se a pilha não estiver cheia:
  if(!estaCheiaPilhaEstatica(pilha)){
    //Atribui o "x" no vetor na posição do topo
    pilha->vetor[pilha->topo] = x;
    //Incrementa o topo
    pilha->topo++;
  }//if
}//empilhaPilhaEstatica


void desempilhaPilhaEstatica(PilhaEstatica *pilha){
  //Inicializa uma variável auxiliar:
  int x = 0;
  //Se a pilha não estiver vazia:
  if(!estaVaziaPilhaEstatica(pilha)){
    //Atribui a "x" o último valor válido da pilha
    x = pilha->vetor[pilha->topo-1];
    //Decrementa topo
    pilha->topo--;
  }//if
}//desempilhaPilhaEstatica


int tamanhoPilhaEstatica(PilhaEstatica *pilha){
  return(pilha->topo);
}//tamanhoPilhaEstatica


//-----------------------------------------------------------------------------
//------------------------Funções da Pilha Dinâmica----------------------------


void iniciaPilhaDinamica(PilhaDinamica *pilha){
  //Ponteiro do topo aponta para nulo
  pilha->topo = NULL;
  //Quantidade de elementos se inicia em zero
  pilha->tamanho = 0;
}//iniciaPilhaDinamica


int tamanhoPilhaDinamica(PilhaDinamica *pilha){
  return(pilha->tamanho);
}//tamanhoPilhaDinamica


bool estaVaziaPilhaDinamica(PilhaDinamica *pilha){
  return(pilha->tamanho == 0);
}//estaVaziaPilhaDinamica


void empilhaPilhaDinamica(PilhaDinamica *pilha, int x){
  //Cria um novo no
  PtrNoPilha aux;
  aux = (PtrNoPilha)malloc(sizeof(NoPilha));
  //Copia o valor inserido no novo no
  aux->chave = x;
  //O proximo do novo no aponta para onde o topo apontava antes
  aux->proximo = pilha->topo;
  //Topo aponta para o novo no
  pilha->topo = aux;
  //Incrementa tamanho
  pilha->tamanho++;
}//empilhaPilhaDinamica


void desempilhaPilhaDinamica(PilhaDinamica *pilha){
  int x = 0;
  if(!estaVaziaPilhaDinamica(pilha)){
    x = pilha->topo->chave;
    PtrNoPilha aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(aux);
    pilha->tamanho--;
  }//if
}//desempilhaPilhaDinamica


//-----------------------------------------------------------------------------
//----------------------------Função Principal---------------------------------


int main(int argc, char const *argv[]) {

  //Declara duas strings e um caractere que percorrá o conteúdo de um arquivo
  char arquivo1[20], arquivo2[20];
  //Declaração de variável que percorre o arquivo de entrada
  char percorre;
  //Declaração de contador para contar quantas linhas o arquivo de entrada possui
  int contalinha = 0;
  //Solicita que o usuário digite o nome de um arquivo de texto
  printf("Digite o nome de um arquivo de texto: ");
  //Armazena o nome do arquivo na string arquivo1
  fgets(arquivo1, 20, stdin);
  //Subscreve o \n por \0
  arquivo1[strcspn(arquivo1,"\n")] = '\0';
  //Limpa o buffer do teclado
  setbuf(stdin, NULL);
  //Solicita o nome do arquivo a ser salvo
  printf("Digite o nome do arquivo a ser salvo: ");
  //Armazena o nome do arquivo na string arquivo2
  fgets(arquivo2, 20, stdin);
  //Subscreve o \n por \0
  arquivo2[strcspn(arquivo2,"\n")] = '\0';
  //Limpa o buffer do teclado
  setbuf(stdin, NULL);
  //Abre e retorna um ponteiro para o arquivo de entrada
  FILE* entrada = fopen(arquivo1, "r");
  //Abre e retorna um ponteiro para o arquivo de saída
  FILE* saida   = fopen(arquivo2, "w");
  //Verifica se existe erro na abertura dos arquivos
  if(entrada == NULL || saida == NULL) {
    //Exibe a mensagem de erro
    perror("Error ");
    //Encerra o programa retornando 0 como valor da função
    return 0;
  }//if
  //Percorre o conteúdo do arquivo de entrada
  while((percorre = fgetc(entrada)) != EOF){
    //Condição do caractere percorre ser igual a quebra de linha
    if(percorre == '\n'){
      //Incrementa no contador contalinha
      contalinha++;
    }//if
    fflush(stdin);
  }//while
  //Retorna o porteiro entrada para o início do arquivo
  rewind(entrada);
  //Declara uma variável do tipo char
  char ch;
  //A variável ch recebe o primeiro caractere do arquivo de entrada
  ch = fgetc(entrada);
  //Define o número de linhas menos a última
  contalinha = contalinha - 1;
  //Verifica se o arquivo não está vazio
  if (contalinha == 0) {
    //Escreve "Arquivo Invalido!" no arquivo de saida
    fprintf(saida, "Arquivo Invalido!");
    //Retorna 0 como valor da função e encerra o programa
    return 0;
  }//if


//-----------------------------------------------------------------------------
//----------------------Condição para a Pilha Estática-------------------------


  //Verifica se o primeiro caractere do arquivo de entrada é o 'e'
  if (ch == 'e') {
    //Declara duas variáveis com a estrutura de PilhaEstatica
    PilhaEstatica pe_bin, pe_arq;
    //Inicia a pilha estática que armazena cada algarismo de um número binário
    iniciaPilhaEstatica(&pe_bin);
    //Inicia a pilha estática que armazena os números binários de forma a salvar no arquivo de saída
    iniciaPilhaEstatica(&pe_arq);
    do {
    //Declaração de um vetor para auxiliar na formação e no salvamento dos números na pe_bin
    int vetorBinarios[MAXTAM];
    //Declaração da variável que armazena o número que está no arquivo de entrada para ser transformado em binário
    int num = 0;
    //Declaração de variável que auxilixará a verificar se os números dentro do arquivo serão inteiros
    float aux = 0;
    //Declaração de variáveis auxiliares
    int j = 0, y;
    //Armazena, na variável aux, o número que está no arquivo de entrada para ser transformado em binário
    fscanf(entrada, "%f", &aux);
    //Armazena o número do arquivo no formato de inteiro
    num = aux;
    //Verifica se o número que está no arquivo e seu formato em inteiro são diferentes
    if (num != aux) {
      //Escreve "Arquivo Invalido!" no arquivo de saida
      fprintf(saida, "Arquivo Invalido!");
      //Retorna 0 como valor da função e encerra o programa
      return 0;
    //Se num e aux forem iguais
    }else{
      //Looping para transformar num em binário
      while(num > 0){
        //vetorBinarios recebe o resto da divisão de num por 2, que formará o número binário
        vetorBinarios[j] = num % 2;
        //Incrementamos j para avançarmos uma posição no vetorBinarios
        j++;
        //num recebe num dividido por 2 para continuar o processo de transformação para binário
        num = num / 2;
      }//while
    }//else
    //Looping para empilhar cada elemento do vetorBinarios na pe_bin
    for(y = j - 1; y >= 0; y--){
      //Empilha cada algarismo do número binário
      empilhaPilhaEstatica(&pe_bin, vetorBinarios[y]);
    }//for
    //Definição de uma variável para obter o tamanho da pilha estática
    int tam;
    //tam recebe o tamanho que a função tamanhoPilhaEstatica retorna
    tam = tamanhoPilhaEstatica(&pe_bin);
    //Declaração de uma variável que auxilia na transformação da pilha de número em um número inteiro
    int bin = 0;
    //Looping para percorrer pe_bin
    for (int h = 0; h <= tam; h++) {
      //bin recebe cada algarismo salvo em pe_bin multiplicado pela sua determinada casa decimal, afim de transforma-lo em um número inteiro
      bin += (pe_bin.vetor[h] * (pow(10, (tam - h - 1))));
    }//for
    //Looping para desempilhar os elementos contidos na pilha pe_bin
    for(int i = 0; i <= j; i++){
      //Desempilha pe_bin
      desempilhaPilhaEstatica(&pe_bin);
    }//for
    //Empilhando os binários contidos em bin na pilha pe_arq
    empilhaPilhaEstatica(&pe_arq, bin);
    //Decrementa uma linha a cada número lido do arquivo e transformado em binário
    contalinha--;
  //Repete todo o bloco de comando enquanto contalinha for maior que zero
  } while(contalinha > 0);
  //Looping para inserir no arquivo os binários empilhados em pe_arq de maneira decrescente
  for (int i = (tamanhoPilhaEstatica(&pe_arq) - 1); i >= 0 ; i--) {
    //Insere no arquivo de saida os binários contidos na pilha pe_arq de maneira decrescente
    fprintf(saida, "%i\n", pe_arq.vetor[i]);
  }//for


//-----------------------------------------------------------------------------
//----------------------Condição para a Pilha Dinâmica-------------------------


  //Verifica se o primeiro caractere do arquivo de entrada é o 'd'
  }else if (ch == 'd') {
    //Declara duas variáveis com a estrutura de PilhaDinamica
    PilhaDinamica pd_bin, pd_arq;
    //Inicia a pilha dinâmica que armazena cada algarismo de um número binário
    iniciaPilhaDinamica(&pd_bin);
    //Inicia a pilha dinâmica que armazena os números binários de forma a salvar no arquivo de saída
    iniciaPilhaDinamica(&pd_arq);
    do {
    //Declaração da variável que armazena o número que está no arquivo de entrada para ser transformado em binário
    int num = 0;
    //Declaração de variável que auxilixará a verificar se os números dentro do arquivo serão inteiros
    float aux = 0;
    //Armazena, na variável aux, o número que está no arquivo de entrada para ser transformado em binário
    fscanf(entrada, "%f", &aux);
    //Armazena o número do arquivo no formato de inteiro
    num = aux;
    //Verifica se o número que está no arquivo e seu formato em inteiro são diferentes
    if (num != aux) {
      //Escreve "Arquivo Invalido!" no arquivo de saida
      fprintf(saida, "Arquivo Invalido!");
      //Retorna 0 como valor da função e encerra o programa
      return 0;
    //Se num e aux forem iguais
    }else{
      //Looping para transformar num em binário
      while(num > 0){
        //Empilha cada algarismo do número binário
        empilhaPilhaDinamica(&pd_bin, (num % 2));
        //num recebe num dividido por 2 para continuar o processo de transformação para binário
        num = num / 2;
      }//while
    }//else
    //Definição de uma variável para obter o tamanho da pilha dinâmica pd_bin
    int tam;
    //tam recebe o tamanho que a função tamanhoPilhaDinamica pd_bin
    tam = tamanhoPilhaDinamica(&pd_bin);
    //Declaração de uma variável que auxilia na transformação da pilha de número em um número inteiro
    int bin = 0;
    //Looping para percorrer pd_bin
    for (int h = 0; h < tamanhoPilhaDinamica(&pd_bin) + h; h++){
      //Armazena em bin o valor dos números em binários obtidos na conversão
      bin += (pd_bin.topo->chave * (pow(10, (tam - h - 1))));
      //Desempilha pd_bin para alterar o tamanho da pilha, reduzindo o topo e passando topo->chave para o item anterior
      desempilhaPilhaDinamica(&pd_bin);
    }//for
    //Empilhando os binários contidos em bin na pilha pd_arq
    empilhaPilhaDinamica(&pd_arq, bin);
    //Decrementa uma linha a cada número lido do arquivo e transformado em binário
    contalinha--;
  //Repete todo o bloco de comando enquanto contalinha for maior que zero
  } while(contalinha > 0);
  //Looping para inserir no arquivo os binários empilhados em pd_arq de maneira decrescente
  for (int h = 0; h < tamanhoPilhaDinamica(&pd_arq) + h; h++){
    //Escreve no arquivo de texto o último binário da pilha
    fprintf(saida, "%i\n", pd_arq.topo->chave);
    //Desempilha pd_arq para alterar o tamanho da pilha, reduzindo o topo e passando topo->chave para o item anterior
    desempilhaPilhaDinamica(&pd_arq);
  }//for


//-----------------------------------------------------------------------------
//---------------------------Condição de Erro----------------------------------


  //Caso o primeiro caractere do arquivo de entrada não seja nem 'e' nem 'd'
  }else{
    //Escreve "Arquivo Invalido!" no arquivo de saida
    fprintf(saida, "Arquivo Invalido!");
  }//else
  //Fecha o arquivo de entrada
  fclose(entrada);
  //Fecha o arquivo de saída
  fclose(saida);
  //Retorna 0 como valor da função
  return 0;
}//main


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
