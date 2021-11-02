//Declaração de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct NoLista* PtrNoLista;

typedef struct NoLista {
  int codigo;
  char nome[100];
  char sexo;
  float peso;
  int altura;
  PtrNoLista proximo;
  PtrNoLista anterior;
} NoLista;

// ListaOrdenada
typedef struct{
  PtrNoLista inicio;
  int qtdeElementos;
} Lista;


//-----------------------------------------------------------------------------
//--------------------------Funções da Lista Dupla-----------------------------

void iniciaLista(Lista *fichas) {
  //inicio da lista aponta para nulo
  fichas->inicio = NULL;
  //Inicia o contador de elementos da lista
  fichas->qtdeElementos = 0;
}//iniciaLista


bool estaVaziaLista(Lista *fichas){
  return(fichas->qtdeElementos == 0);
}//estaVaziaLista


int contaFichas(FILE* arquivo) {
  //Declara variável do tipo char que percorre o arquivo de entrada
  char percorre;
  //Declara contador para contar quantas fichas possui no arquivo
  int contaficha = 0;
  //Percorre o conteúdo do arquivo de entrada
  while((percorre = fgetc(arquivo)) != EOF){
    //Condição do caractere percorre ser igual a 'fecha chave'
    if(percorre == '}'){
      //Incrementa no contador contaficha
      contaficha++;
    }//if
  }//while
  //Retorna o ponteiro do arquivo de entrada para o início
  rewind(arquivo);
  //Retorna o valor de contaficha como valor da função
  return contaficha;
}//contaFichas


void insereLista(Lista *fichas, FILE* entrada, int contaficha){
  //Looping enquanto a quantidade de elemntos contida em fichas->qtdeElementos for menor que o número de fichas obtido com "contaFichas"
  do{
    //Declara uma variável do tipo PtrNoLista alocada dinâmicamente
    PtrNoLista novo = (PtrNoLista) malloc(sizeof(NoLista));
      //Obtém do arquivo as informações das fichas e as salva
      fscanf(entrada, "{%d,%[^,],%c,%f,%d}\n", &novo->codigo, &novo->nome, &novo->sexo, &novo->peso, &novo->altura);
      //Declara uma variável x que recebe o valor do código a ser inserido na lista
      int x = novo->codigo;
      //Caso não exista nenhuma ficha na lista
      if(estaVaziaLista(fichas)) {
        //Declara valor próximo como Nulo
        novo->proximo  = NULL;
        //Declara valor anterior como Nulo
        novo->anterior = NULL;
        //Declara valor inicio da lista
        fichas->inicio = novo;
      //Caso o novo código seja menor que o que se encontra no início da lista
      }else if (x < fichas->inicio->codigo) {
        //Declara o valor do anterior como Nulo
        novo->anterior = NULL;
        //Declara o valor do anterior do inicio como novo
        fichas->inicio->anterior = novo;
        //Declara valor de próximo como o valor do inicio
        novo->proximo = fichas->inicio;
        //Declara valor inicio da lista
        fichas->inicio = novo;
      //Se não, procuramos o lugar em que o código deve ficar na lista
      }else {
        //Declara uma variável auxiliar do tipo PtrNoLista
        PtrNoLista aux;
        //Variável assume o valor inicio da lista
        aux = fichas->inicio;
        //Looping para enquanto o valor próximo existir e o codigo da ficha
        //que será inserido na lista for maior que o valor do código do próximo valor contido em aux
        while(aux->proximo != NULL && x > aux->proximo->codigo) {
          //Variável auxiliar assume o valor próximo
          aux = aux->proximo;
        }//while
        //O valor seguinte de novo->proximo assume o valor contido no próximo de aux
        novo->proximo = aux->proximo;
        //Caso não exista valor próximo em aux
        if(aux->proximo != NULL) {
          //Valor próximo de aux assume valor anterior (mesmo valor que ja possuia), assim como novo
          aux->proximo->anterior = novo;
        }//if
        //Valor anterior de novo assume o valor de aux
        novo->anterior = aux;
        //Valor próximo de aux assume o valor de novo
        aux->proximo = novo;
      }//else
      //Aumenta a quantidade de elemntos contidos na lista
      fichas->qtdeElementos++;
    }while ((fichas->qtdeElementos) < contaficha);
}//insereLista


void imprimeLista(Lista *fichas, FILE* saida) {
  //Declara uma variável do tipo PtrNoLista
  PtrNoLista ptr;
  //Declara uma variável inteira auxiliar para peso
  int peso;
  //Looping para imprimir todas as fichas
  for(ptr = fichas->inicio; ptr != NULL; ptr = ptr->proximo) {
    //A variável peso recebe o valor de peso contido em ptr  (obtido da lista)
    peso = ptr->peso;
    //Verifica se o número que está em ptr e seu formato em inteiro são diferentes
    if (peso != ptr->peso) {
      //Salva no arquivo de saída todas as informações (valores) contidas em ptr (obtidas da lista) com peso em float
      fprintf(saida, "{%d,%s,%c,%.1f,%i}\n", ptr->codigo, ptr->nome, ptr->sexo, ptr->peso, ptr->altura);
    }else{
      //Salva no arquivo de saída todas as informações (valores) contidas em ptr (obtidas da lista) com peso em inteiro
      fprintf(saida, "{%d,%s,%c,%d,%i}\n", ptr->codigo, ptr->nome, ptr->sexo, peso, ptr->altura);
    }//else
  }//for
}//imprimeLista


void imprimeListaReverso(Lista *fichas, FILE* saida) {
  //Declara uma variável inteira auxiliar para peso
  int peso;
  //Declara duas variáveis do tipo PtrNoLista, uma auxiliar e um ponteiro
  PtrNoLista ptr, aux;
  //Looping para enquanto o valor seguinte de ptr existir, uma vez que ptr assume a posição fichas->inicio
  for(ptr = fichas->inicio; ptr->proximo != NULL; ptr = ptr->proximo){
    //Variável auxiliar assume o valor contido em ptr, ou seja, sempre o proximo valor
    aux = ptr;
  }
  //Variável auxiliar assume o valor contido em ptr fora do looping
  aux = ptr;
    //Looping enquanto auxiliar existir
    do {
      //A variável peso recebe o valor de peso contido em aux (obtido da lista)
      peso = aux->peso;
        //Verifica se o número que está em aux e seu formato em inteiro são diferentes
        if (peso != aux->peso) {
          //Salva no arquivo de saída todas as informações (valores) contidas em aux (obtidas da lista) com peso em float
          fprintf(saida, "{%d,%s,%c,%.1f,%i}\n", aux->codigo, aux->nome, aux->sexo, aux->peso, aux->altura);
        }else{
          //Salva no arquivo de saída todas as informações (valores) contidas em aux (obtidas da lista) com peso em inteiro
          fprintf(saida, "{%d,%s,%c,%d,%i}\n", aux->codigo, aux->nome, aux->sexo, peso, aux->altura);
        }//else
      //Variável auxiliar assume o valor anterior ao seu valor
      aux = aux->anterior;
    } while(aux != NULL);
}//imprimeListaReverso


void buscaLista(Lista *fichas, int busca, FILE* saida) {
  //Declara uma variável do tipo PtrNoLista
  PtrNoLista ptr;
  //Declara uma variável inteira auxiliar para peso
  int peso;
  //Looping para percorrer ptr (que assume posição fichas->inicio)
  //Enquanto o valor próximo de ptr existir e enquanto busca for maior que o valor código contido em ptr
  //Caso ambas as condições forem assumidas o código requisitado e contido em busca foi encontrada na lista
  for(ptr = fichas->inicio; ptr->proximo != NULL && busca > ptr->codigo; ptr = ptr->proximo);
  //Se ptr possui o valor Nulo ou se o código de ptr for diferente do valor de busca
  if(ptr == NULL || ptr->codigo != busca){
    //Salva no arquivo de saída que o código buscado não existe ou não foi encontrado
    fprintf(saida, "O código não existe ou não foi encontrado!");
  }else{
    //A variável peso recebe o valor de peso contido em ptr (obtido da lista)
    peso = ptr->peso;
    //Verifica se o número que está em ptr e seu formato em inteiro são diferentes
    if (peso != ptr->peso) {
      //Salva no arquivo de saída todas as informações (valores) contidas em ptr (obtidas da lista) com peso em float
      fprintf(saida, "{%d,%s,%c,%.1f,%i}\n", ptr->codigo, ptr->nome, ptr->sexo, ptr->peso, ptr->altura);
    }else{
      //Salva no arquivo de saída todas as informações (valores) contidas em ptr (obtidas da lista) com peso em inteiro
      fprintf(saida, "{%d,%s,%c,%d,%i}\n", ptr->codigo, ptr->nome, ptr->sexo, peso, ptr->altura);
    }//else
  }//else
}//buscaLista


void destroiLista(Lista *fichas) {
  //Declara uma variável do tipo PtrNoLista
  PtrNoLista remove;
  //Looping enquanto o inicio da lista ainda existir
  while(fichas->inicio != NULL) {
    //Passa o valor de fichas->inicio (primeiro valor da lista) para a variável que vai fazer sua remoção
    remove = fichas->inicio;
    //Primeiro valor da lista passa a ser o proximo valor
    fichas->inicio = fichas->inicio->proximo;
    //Efetua a remoção do valor inicial atual da lista, que estava armazenado na variável liberada
    free(remove);
  }//while
}//destroiLista


//-----------------------------------------------------------------------------
//----------------------------Função Principal---------------------------------


int main(int argc, char const *argv[]) {
  Lista fichas;
  //Declara duas strings e um caractere que percorrá o conteúdo de um arquivo
  char arquivo1[20], arquivo2[20];
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
  //Verifica se o número de fichas é zero
  if (contaFichas(entrada) == 0) {
    //Escreve "Arquivo Invalido!" no arquivo de saida
    fprintf(saida, "Arquivo Inválido!");
    //Retorna 0 como valor da função
    return 0;
  }//if
  //Inicia a lista
  iniciaLista(&fichas);
  //Insere na lista todas as fichas contidas no arquivo
  insereLista(&fichas, entrada, contaFichas(entrada));
  //Declara uma variável do tipo char
  char acao;
  //A variável acao recebe o próximo caractere, onde está o ponteiro, do arquivo de entrada
  acao = fgetc(entrada);
  //Se o valor da variável acao for igual a 1
  if (acao == '1') {
    //Chama a função imprimeLista
    imprimeLista(&fichas, saida);
  //Se o valor da variável acao for igual a 2
  }else if(acao == '2') {
    //Chama a função imprimeListaReverso
    imprimeListaReverso(&fichas, saida);
  //Se o valor da variável acao for igual a 3
  }else if (acao == '3') {
    //Declara variável que vai assumir o valor que se deseja buscar
    float busca;
    //Declara variável que auxilia na busca para verificar se é um valor aceito
    int aux_busca;
    //A variável busca recebe o valor do arquivo de entrada
    fscanf(entrada, "%f", &busca);
    //A variável aux_busca recebe o valor de busca em formato de inteiro
    aux_busca = busca;
    //Caso busca seja diferente do valor de aux_busca
    if(busca != aux_busca){
      //Escreve "Arquivo Invalido!" no arquivo de saida
      fprintf(saida, "Arquivo Inválido");
    }else{
      //Chama a função buscaLista para encontrar o valor de busca
      buscaLista(&fichas, busca, saida);
    }//else
  //Se o valor da variável acao não for nenhuma opção descrita acima
  }else{
    //Escreve "Arquivo Invalido!" no arquivo de saida
    fprintf(saida, "Arquivo Inválido");
  }//else
  //Chama a função destroiLista
  destroiLista(&fichas);
  //Fecha o arquivo de entrada
  fclose(entrada);
  //Fecha o arquivo de saída
  fclose(saida);
  //Retorna 0 como valor da função
  return 0;
}//main
