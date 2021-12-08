//Declaração de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct NoAVL* PtrNoAVL;

typedef struct NoAVL{
  int chave;
  PtrNoAVL esquerda;
  PtrNoAVL direita;
  int altura;
  int desbalanceamento;
  int tamanho;
}NoAVL;

//------------------------------------------------------------------------------
//-------------------------------------AVL--------------------------------------

void iniciaArvoreAVL(PtrNoAVL *node) {
  *node = NULL;
}//iniciaArvoreAVL


void pulaLinha(FILE *entrada){
  //Declara string que vai pegar a linha
  char aux[1001];
  //Salva a linha na string declarada
  fscanf(entrada, "%s\n", aux);
}//pulaLinha


int contaLinha(FILE* arquivo) {
  //Declara variável do tipo char que percorre o arquivo de entrada
  char percorre;
  //Declara contador para contar quantas linhas possui no arquivo
  int contaLinha = 0;
  //Percorre o conteúdo do arquivo de entrada até o final
  while((percorre = fgetc(arquivo)) != EOF){
    //Condição do caractere percorre ser igual a '\n'
    if(percorre == '\n'){
      //Incrementa no contador contaLinha
      contaLinha++;
    }//if
  }//while
  //Retorna o ponteiro do arquivo de entrada para o início
  rewind(arquivo);
  //Retorna o valor de contaLinha como valor da função
  return contaLinha;
}//contaLinha


int contaVirgula(FILE* arquivo) {
  //Declara variável do tipo char que percorre o arquivo de entrada
  char percorre;
  //Declara contador para contar quantas virgulas possui no arquivo
  int contavirgula = 0;
  //Percorre o conteúdo do arquivo de entrada até encontrar o símbolo \n
  while((percorre = fgetc(arquivo)) != '\n'){
    //Condição do caractere percorre ser igual a ','
    if(percorre == ','){
      //Incrementa no contador contavirgula
      contavirgula++;
    }//if
  }//while
  //Retorna o ponteiro do arquivo de entrada para o início
  rewind(arquivo);
  //Retorna o valor de contavirgula como valor da função
  return contavirgula;
}//contaVirgula


int alturaArvoreAVL(PtrNoAVL node) {
  //Verifica se o nó é nulo
  if(node == NULL) {
    //Retorna o valor 0
    return (0);
  } else {
    //Retorna a altura da raiz
    return ((node)->altura);
  }//else
}//alturaArvoreAVL


int fatorBalanceamento(PtrNoAVL *node) {
  //Declara a variavel fator e salva nela a subtração da altura do nó esquerdo pela altura do nó direito, multiplicada por -1
  int fator = (alturaArvoreAVL((*node)->esquerda) - alturaArvoreAVL((*node)->direita)) * -1 ;
  //Retorna o valor do fator
  return (fator);
}//fatorBalanceamento


void imprimeAVL(PtrNoAVL *node, FILE * saida, int tamanho){
  //Verifica se a nó é nulo
  if((*node) == NULL) return;
  //Verifica se o tamanho do nó é igual ao tamanho passado pela função
  if((*node)->tamanho == tamanho){
    //Verifica se a nó é nulo novamente
    if((*node) == NULL) return;
    //Salva no desbalanceamento do nó o fator balanceamento para o nó
    (*node)->desbalanceamento = fatorBalanceamento(&(*node));
    //Salva no arquivo de saida cada chave da AVL e o valor do desbalanceamento
    fprintf(saida, "%d (%i),",(*node)->chave, (*node)->desbalanceamento);
  }//if
  //Chama função recursiva para esquerda
  imprimeAVL(&(*node)->esquerda, saida, tamanho);
  //Chama função recursiva para direita
  imprimeAVL(&(*node)->direita, saida, tamanho);
}//imprimeAVL


int profundidadeArvoreAVL(PtrNoAVL *node) {
  //Verifica se o nó é nulo, e retorna 0 caso verdadeiro
  if ((*node) == NULL) return 0;
  else {
    //Declara variáveis de profundidade para direita e esquerda
    //Salva nas variáveis suas respectivas profundidades
    int lDepth = profundidadeArvoreAVL(&(*node)->esquerda);
    int rDepth = profundidadeArvoreAVL(&(*node)->direita);
    //Verifica se a profundidade da esquerda é maior que a da direita
    if (lDepth > rDepth)
      //Retorna o valor da profundidade esquerda + 1
      return(lDepth+1);
    //Caso contrário, retorna o valor da profundidade direita + 1
    else return(rDepth+1);
  }//else
}//profundidadeArvoreAVL


void destroiArvoreAVL(PtrNoAVL *node) {
  //Verifica se o nó não é nulo
  if((*node) != NULL ) {
    //Chama função recursiva para esquerda
    destroiArvoreAVL(&(*node)->esquerda);
    //Chama função recursiva para direita
    destroiArvoreAVL(&(*node)->direita);
    //Libera a memória utilizada para armazenar o nó
    free(*node);
    //O nó recebe nulo
    *node = NULL;
  }//if
}//destroiArvoreAVL


int atualizaAlturaArvoreAVL(PtrNoAVL esq, PtrNoAVL dir) {
  //Declara variáveis de altura para subarvores direita e esquerda
  //Salva nas variáveis suas respectivas alturas
  int ae = alturaArvoreAVL(esq);
  int ad = alturaArvoreAVL(dir);
  //Verifica se a altura da subarvore esquerda é maior que a da subarvore direita
  if(ae > ad) {
    //Retorna o valor da altura da subarvore esquerda + 1
    return(ae + 1);
  } else {
    //Caso contrário, retorna altura da subarvore direita + 1
    return(ad + 1);
  }//else
}//atualizaAlturaArvoreAVL


void rotacaoSimplesDireita(PtrNoAVL *node) {
  //Declara uma variável tipo PtrNoAVL e salva nela o nó da esquerda
  PtrNoAVL u = (*node)->esquerda;
  //Nó da esquerda recebe o nó direita do nó esquerda salvo na variável u
  (*node)->esquerda = u->direita;
  //O nó da direita salvo na variável u recebe o nó
  u->direita = (*node);
  //Atualiza a altura do nó
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  //Atualiza a altura do u
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  //Nó recebe u
  (*node) = u;
}//rotacaoSimplesDireita


void rotacaoSimplesEsquerda (PtrNoAVL *node) {
  //Declara uma variável tipo PtrNoAVL e salva nela o nó da direita
  PtrNoAVL u = (*node)->direita;
  //Nó da direita recebe o nó da esquerda do nó direita salvo na variável u
  (*node)->direita = u->esquerda;
  //O nó da esquerda salvo na variável u recebe o nó
  u->esquerda = (*node);
  //Atualiza a altura do nó
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  //Atualiza a altura do u
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  //Nó recebe u
  (*node) = u;
}//rotacaoSimplesEsquerda


void rotacaoDuplaDireita (PtrNoAVL *node) {
  //Declara variáveis do tipo PtrNoAVL
  PtrNoAVL u, v;
  //Variável u recebe o nó esquerda
  u = (*node)->esquerda;
  //Variável v recebe o nó direita do nó esquerda salvo em u
  v = u->direita;
  //O nó esquerda recebe o nó direita do nó direita salvo em v
  (*node)->esquerda = v->direita;
  //O nó direita de u recebe nó esquerda de v
  u->direita = v->esquerda;
  //O nó direita de v recebe nó
  v->direita = (*node);
  //O nó esquerda de v recebe u
  v->esquerda = u;
  //Atualiza a altura do nó
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  //Atualiza a altura do u
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  //Atualiza a altura do v
  v->altura = atualizaAlturaArvoreAVL(v->esquerda, v->direita);
  //Nó recebe v
  (*node) = v;
}//rotacaoDuplaDireita


void rotacaoDuplaEsquerda (PtrNoAVL *node) {
  //Declara variáveis do tipo PtrNoAVL
  PtrNoAVL u, v;
  //Variável u recebe o nó direita
  u = (*node)->direita;
  //Variável v recebe o nó esquerda do nó direita salvo em u
  v = u->esquerda;
  //O nó direita recebe o nó esquerda do nó esquerda salvo em v
  (*node)->direita = v->esquerda;
  //O nó esquerda de u recebe nó direita de v
  u->esquerda = v->direita;
  //O nó esquerda de v recebe nó
  v->esquerda = (*node);
  //O nó direita de v recebe u
  v->direita = u;
  //Atualiza a altura do nó
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  //Atualiza a altura do u
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  //Atualiza a altura do v
  v->altura = atualizaAlturaArvoreAVL(v->esquerda, v->direita);
  //Nó recebe v
  (*node) = v;
}//rotacaoDuplaEsquerda


void aplicarRotacoes(PtrNoAVL *node) {
  //Declara variáveis de altura para subarvores direita e esquerda
  //Salva nas variáveis suas respectivas alturas
  int ad = alturaArvoreAVL((*node)->direita);
  int ae = alturaArvoreAVL((*node)->esquerda);
  //Verificar se é rotacao para direita
  if(ae > ad) {
    //Declara variável temp que recebe o nó esquerda
    PtrNoAVL temp = (*node)->esquerda;
    //Declara variáveis de altura temporária para subarvores direita e esquerda
    //Salva nas variáveis suas respectivas alturas
    int temp_ad = alturaArvoreAVL(temp->direita);
    int temp_ae = alturaArvoreAVL(temp->esquerda);
    //Verifica se altura temporária da subarvore esquerda é maior que a da direita
    if(temp_ae >= temp_ad) {
      //Chama função de rotação simples para a direita do nó
      rotacaoSimplesDireita(&(*node));
    }else{
      //Caso contrário, chama a função de rotação dupla para a direita do nó
      rotacaoDuplaDireita(&(*node));
    }//else
  //Senao é rotação para esquerda
  }else{
    //Declara variável do tipo PtrNoAVL que recebe nó direita
    PtrNoAVL tmp2 = (*node)->direita;
    ////Declara variáveis de altura temporária para subarvores direita e esquerda
    //Salva nas variáveis suas respectivas alturas
    int tmp2_ad = alturaArvoreAVL(tmp2->direita);
    int tmp2_ae = alturaArvoreAVL(tmp2->esquerda);
    //Verifica se altura temporária da subarvore direita é maior que a da esquerda
    if(tmp2_ad >= tmp2_ae){
      //Chama função de rotação simples para a esquerda do nó
      rotacaoSimplesEsquerda(&(*node));
    }else{
      //Caso contrário, chama a função de rotação dupla para a esquerda do nó
      rotacaoDuplaEsquerda(&(*node));
    }//else
  }//else
}//aplicarRotacoes


bool insereArvoreAVL(PtrNoAVL *node, int x) {
  //Verifica se o nó é nulo
  if((*node) == NULL) {
    //Aloca memória para nó
    (*node) = (PtrNoAVL)malloc(sizeof(NoAVL));
    //O nó direita e o nó esquerda recebem valor nulo
    (*node)->direita = (*node)->esquerda = NULL;
    //A chave recebe o valor passado pela função
    (*node)->chave = x;
    //A altura do nó recebe valor 1
    (*node)->altura = 1;
    //Retorna verdadeiro
    return true;
  }//if
  //Verifica se o elemento a ser inserido já existe na arvore
  if((*node)->chave == x) return false;
  //Declara variável do tipo bool
  bool auxiliar;
  //Verifica se o elemento a ser inserido é menor do que o elemento salvo na chave do nó corrente
  if(x < (*node)->chave) {
    //Auxiliar recebe o valor da recursão da função insereArvoreAVL para a esquerda
    auxiliar = insereArvoreAVL(&(*node)->esquerda, x);
  }else{
    //Caso contrário, auxiliar recebe o valor da recursão da função insereArvoreAVL para a direita
    auxiliar = insereArvoreAVL(&(*node)->direita, x);
  }
  //Verifica se auxiliar é falso, se sim, retorna falso
  if(!auxiliar) return (false);
  //Declara variáveis de altura para subarvores direita e esquerda
  //Salva nas variáveis suas respectivas alturas
  int ae = alturaArvoreAVL((*node)->esquerda);
  int ad = alturaArvoreAVL((*node)->direita);
  //Verifica se a altura da subarvore esquerda menos a da subarvore direita é 2
  //Verifica se a altura da subarvore direita menos a da subarvore esquerda é -2
  if((ad - ae) == +2 || (ad - ae) == -2) {
    //Chama a função que verifica quais rotaçòes serão aplicadas
    aplicarRotacoes(&(*node));
  }//if
  //Atualiza a altura do nó
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  //Retorna verdadeiro
  return(true);
}//insereArvoreAVL


PtrNoAVL getMaxAux(PtrNoAVL *node) {
  //Declara variável do tipo PtrNoAVL
  PtrNoAVL maior;
  //Verifica se o nó direita não é nulo
  if((*node)->direita != NULL) {
    //A variável recebe a chamada recursiva da função para nó direita
    maior = getMaxAux(&(*node)->direita);
  }else{
    //Caso contrário, a variável recebe nó
    maior = (*node);
    //O nó recebe o nó esquerda
    (*node) = (*node)->esquerda;
  }//else
  //Retorna o valor de maior
  return maior;
}//getMaxAux


PtrNoAVL getMinAux(PtrNoAVL *node) {
  //Declara variável do tipo PtrNoAVL
  PtrNoAVL menor;
  //Verifica se o nó esquerda não é nulo
  if((*node)->esquerda != NULL) {
    //A variável recebe a chamada recursiva da função para nó esquerda
    menor = getMinAux(&(*node)->esquerda);
  }else{
    //Caso contrário, a variável recebe nó
    menor = (*node);
    //O nó recebe o nó direita
    (*node) = (*node)->direita;
  }//else
  //Retorna o valor de menor
  return menor;
}//getMinAux


bool removeArvoreAVL(PtrNoAVL *node, int x, char letra[101], FILE* entrada){
  //Declara variáveis do tipo bool e int
  bool test;
  int h_left, h_right;
  //Verifica se o nó é nulo
  if((*node) == NULL) return (false);
  //Verifica se nó chave é igual ao valor recebido da função
  if((*node)->chave == x) {
    //Verifica se os nós da esquerda e direita são nulos
    if((*node)->esquerda == NULL && (*node)->direita == NULL){
      //Declara variável do tipo PtrNoAVL
      PtrNoAVL tmp = (*node);
      //O nó recebe valor nulo
      (*node) = NULL;
      //Libera a memória utilizada para armazenar o tmp
      free(tmp);
      //Retorna verdadeiro
      return true;
    }//if
    //Verifica se o nó da esquerda é nulo e o da direita não é nulo
    if((*node)->esquerda == NULL && (*node)->direita != NULL){
      //Declara variável do tipo PtrNoAVL
      PtrNoAVL tmp = (*node);
      //O nó recebe a subarvore direita
      (*node) = (*node)->direita;
      //Libera a memória utilizada para armazenar o tmp
      free(tmp);
      //Retorna verdadeiro
      return true;
    }//if
    //Verifica se o nó da esquerda nao é nulo e o da direita é nulo
    if((*node)->esquerda != NULL && (*node)->direita == NULL){
      //Declara variável do tipo PtrNoAVL
      PtrNoAVL tmp = (*node);
      //O nó recebe a subarvore esquerda
      (*node) = (*node)->esquerda;
      //Libera a memória utilizada para armazenar o tmp
      free(tmp);
      //Retorna verdadeiro
      return true;
    }//if
    //Verifica se os nós da esquerda e da direita não são nulos
    if((*node)->direita != NULL && (*node)->esquerda != NULL){
      //Declara variável do tipo PtrNoAVL
      PtrNoAVL tmp = (*node);
      //Verifica se a letra obtida da função é "d"
      if(strcmp("d", letra) == 0){
        //Variável tmp recebe o valor mínimo da subarvore direita
        tmp = getMinAux(&(*node)->direita);
      //Verifica se a letra obtida da função é "e"
      }else if(strcmp("e", letra) == 0){
        //Variável tmp recebe o valor máximo da subarvore esquerda
        tmp = getMaxAux(&(*node)->esquerda);
      }else{
        //Encerra o programa
        exit(1);
      }//else
      //A chave do nó recebe o valor da chave de tmp
      (*node)->chave = tmp->chave;
      //Libera a memória utilizada para armazenar o tmp
      free(tmp);
      //Retorna verdadeiro
      return true;
    }//if
  }//if
  //Verifica se nó chave é maior que o valor recebido na função
  if((*node)->chave > x){
    //Salva na variável test a recursiva para nó esquerda
    test = removeArvoreAVL(&(*node)->esquerda, x, letra, entrada);
  }else{
    //Caso contrário, salva na variável test a recursiva para nó direita
    test = removeArvoreAVL(&(*node)->direita, x, letra, entrada);
  }//else
  //Verifica se test é falso
  if(test == false) return (false);
  //Declara variáveis de profundidade para direita e esquerda
  //Salva nas variáveis suas respectivas profundidades
  h_left  = profundidadeArvoreAVL(&(*node)->esquerda);
  h_right = profundidadeArvoreAVL(&(*node)->direita);
  //Verifica se a profundidade da subarvore direita menos a da subarvore esquerda é 2
  //Verifica se a profundidade da subarvore direita menos a da subarvore esquerda é -2
  if((h_right - h_left) == +2 || (h_right - h_left) == -2){
    //Chama a função para aplicar rotações
    aplicarRotacoes(&(*node));
  }//if
  //O nó altura recebe a altura atualizada da arvore para as subarvores esquerda e direita
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  //Retorna verdadeiro
  return(true);
}//removeArvoreAVL


void atualizaTamanhoAvl(PtrNoAVL *node){
  //Verifica se o nó é nulo
  if((*node) == NULL) return;
  //Verifica se o nó esquerda é nulo
  if((*node)->esquerda != NULL){
    //Tamanho do nó esquerda recebe nó tamanho + 1
    (*node)->esquerda->tamanho = (*node)->tamanho+1;
  }//if
  //Verifica se nó direita não é nulo
  if((*node)->direita != NULL){
    //Tamanho do nó direita recebe nó tamanho + 1
    (*node)->direita->tamanho = (*node)->tamanho+1;
  }//if
  //Chamadas recursivas para as subarvores esquerda e direita
  atualizaTamanhoAvl(&(*node)->esquerda);
  atualizaTamanhoAvl(&(*node)->direita);
  //Retorna a função
  return;
}//atualizaTamanhoAvl


int tamanhoMaxAvl(PtrNoAVL *node){
  //Declara variáveis
  int x,y;
  //Verifica se as subarvores esquerda e direita são nulas
  if ((*node)->direita == NULL && (*node)->esquerda == NULL){
    //Retorna nó tamanho
    return ((*node)->tamanho);
  }else{
    //Caso contrário, verifica se nó esquerda não é nulo
    if((*node)->esquerda != NULL){
      //Variável x recebe o tamanho da subarvore esquerda
      x = tamanhoMaxAvl(&(*node)->esquerda);
    }else{
      //Caso contrário, x recebe o valor 0
      x = 0;
    }//else
    //Verifica se nó direita não é nulo
    if((*node)->direita != NULL){
      //Variável y recebe o tamanho da subarvore direita
      y = tamanhoMaxAvl(&(*node)->direita);
    }else{
      //Caso contrário, y recebe o valor 0
      y = 0;
    }//else
    //Verifica se a variável x é maior que y
    if(x > y){
      //Retorna x
      return x;
    }else{
      //Caso contrário, retorna y
      return y;
    }//else
  }//else
}//tamanhoMaxAvl


//-----------------------------------------------------------------------------
//----------------------------Função Principal---------------------------------

int main(int argc, char const *argv[]) {
  //Declaração de variáveis
  PtrNoAVL raiz;
  int qtd_numeros;
  int x;
  char letra[101];
  //Condição para verificar se 2 arquivos (de entrada e de saida) foram inseridos
  if(argc != 3) {
    //Exibe a mensagem de que o usuário não digitou o nome dos dois arquivos
    printf("Acao invalida!\nDigite: arquivo de entrada \"espaco\" arquivo de saida.\n");
    //Retorna 0 como valor da função e encerra o programa
    return 0;
  }//if
  //Abre e retorna um ponteiro para o arquivo de entrada
  FILE* entrada = fopen(argv[1], "r");
  //Abre e retorna um ponteiro para o arquivo de saída
  FILE* saida   = fopen(argv[2], "w");
  //Verifica se existe erro na abertura dos arquivos
  if(entrada == NULL || saida == NULL) {
    //Exibe a mensagem de erro
    perror("Error ");
    //Encerra o programa retornando 0 como valor da função
    return 0;
  }//if
  //Variável qnt_numeros recebe o valor de vírgulas contidas na primeira linha do arquivo
  qtd_numeros = contaVirgula(entrada);
  //Inicia a AVL
  iniciaArvoreAVL(&raiz);
  //Chama a função para pular 1 linha no arquivo de entrada
  pulaLinha(entrada);
  //Chama a função para pular 1 linha no arquivo de entrada
  pulaLinha(entrada);
  //Letra recebe a string contida na 3 linha do arquivo de entrada
  fscanf(entrada, "%s", letra);
  //Verifica se letra é diferente de "e" e "d"
  if (strcmp("e", letra) != 0 && strcmp("d", letra) != 0) {
    //Escreve no arquivo de saida "Arquivo Inválido!"
    fprintf(saida, "Arquivo Inválido!");
    //Retorna 0 como valor da função
    return 0;
  }//if
  //Reinicia o arquivo de entrada
  rewind(entrada);
  //Declara uma variável auxiliar que recebe o valor de linhas do arquivo de entrada
  int aux = contaLinha(entrada);
  //Verifica se aux é maior que 3
  if (aux != 3) {
    //Escreve no arquivo de saida "Arquivo Inválido!"
    fprintf(saida, "Arquivo Inválido!");
    //Retorna 0 como valor da função
    return 0;
  }//if
  //Retorna o ponteiro do arquivo de entrada para o início
  rewind(entrada);
  //Looping para inserir os valores do arquivo de entrada na AVL
  for(int i = 0; i <= qtd_numeros; i++) {
    //Verifica se i é igual ao valor de qtd_numeros
    if (i == qtd_numeros) {
      //Salva em x o último valor contido na primeira linha do arquivo de entrada
      fscanf(entrada, "%d\n", &x);
    }else{
      //Caso contrário, salva em x os outros valores contidos na primeira linha do arquivo de entrada
      fscanf(entrada, "%d,", &x);
    }//else
    //Chama a função que insere o valor de x na AVL
    insereArvoreAVL(&raiz, x);
  }//for
  //Tamanho da raiz recebe o valor 1
  raiz->tamanho = 1;
  //Chama a função para atualizar o tamanho
  atualizaTamanhoAvl(&raiz);
  //Escreve no arquivo "[*]antes" e pula uma linha
  fprintf(saida, "[*]antes\n");
  //Variável y recebe o valor do tamanho máximo da AVL
  int y = tamanhoMaxAvl(&raiz);
  //Looping para salvar os nós em ordem decrescente de tamanho
  for(int i = raiz->tamanho; i <= y; i++){
    //Chama função para escrever a AVL no arquivo de saida
    imprimeAVL(&raiz,saida, i);
    //Pula uma linha no arquivo de saida
    fprintf(saida, "\n");
  }//for
  //Pula uma linha no arquivo de saida
  fprintf(saida,"\n");
  //Variável qnt_numeros recebe o valor de vírgulas contidas na segunda linha do arquivo
  qtd_numeros = contaVirgula(entrada);
  //Chama a função para pular 1 linha no arquivo de entrada
  pulaLinha(entrada);
  //Looping para remover os elementos da segunda linha do arquivo de entrada na AVL
  for(int i = 0; i <= qtd_numeros; i++) {
    //Verifica se i é igual ao valor de qtd_numeros
    if (i == qtd_numeros) {
      //Salva em x o último valor contido na segunda linha do arquivo de entrada
      fscanf(entrada, "%d\n", &x);
    }else{
      //Caso contrário, salva em x os outros valores contidos na segunda linha do arquivo de entrada
      fscanf(entrada, "%d,", &x);
    }//else
    //Chama a função que remove o valor de x da AVL
    removeArvoreAVL(&raiz, x, letra, entrada);
  }//for
  //Tamanho da raiz recebe o valor 1
  raiz->tamanho = 1;
  //Chama a função para atualizar o tamanho
  atualizaTamanhoAvl(&raiz);
  //Escreve no arquivo "[*]depois" e pula uma linha
  fprintf(saida,"[*]depois\n");
  //Variável y recebe o valor do tamanho máximo da AVL
  y = tamanhoMaxAvl(&raiz);
  //Looping para salvar os nós em ordem decrescente de tamanho
  for(int i = raiz->tamanho; i <= y; i++){
    //Chama função para escrever a AVL no arquivo de saida
    imprimeAVL(&raiz,saida, i);
    //Pula uma linha no arquivo de saida
    fprintf(saida, "\n");
  }//for
  //Pula uma linha no arquivo de saida
  fprintf(saida,"\n");
  //Chama a função que destroi a AVL
  destroiArvoreAVL(&raiz);
  //Fecha o arquivo de entrada
  fclose(entrada);
  //Fecha o arquivo de saída
  fclose(saida);
  //Retorna 0 como valor da função
  return 0;
}//main
