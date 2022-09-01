//Declaração de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Estrutura Heroi
typedef struct{
  char chave[3];
  char resto[136];
}Heroi;


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


int *Aloca(int tamanho){
  //Declaração de um ponteiro vetor
  int *vetor;
  //Alocação de memória para o vetor de tamanho tamanho
  vetor = (int*) malloc (tamanho * sizeof(int));
  //Retorna o ponteiro para o vetor como valor da função
  return vetor;
}//Aloca


void troca (int *v, int *z){
  //Declaração de variável temporária
  int temp;
  //temp recebe o valor de *v passado por parâmetro
  temp = *v;
  //*v recebe o valor de *z passado por parâmetro
  *v = *z;
  //*z recebe o valor armazenado na variável temporária
  *z = temp;
}//troca


void arqSaida(FILE* saida, int *v, int quant, Heroi* h, int size, int top, char sort, char order){
  //Salva o header no arquivo de saída
  fprintf(saida, "SIZE=%d TOP=%d QTDE=%d SORT=%c ORDER=%c\n", size, top, quant, sort, order);
  //Looping para percorrer o vetor v
  for (int i = 0; i < quant; i++) {
    //Looping para percorrer o vetor h com estrutura Heroi
    for (int j = 0; j < quant; j++) {
      //Se o valor armazenado na posição i do vetor for igual o valor (int) da chave na posição j do vetor de herois
      if (v[i] == atoi(h[j].chave)) {
        //Salva no arquivo todas as informações presentes na posição j do vetor de herois
        fprintf(saida, "%s|%s\n", h[j].chave, h[j].resto);
      }//if
    }//for
  }//for
}//arqSaida


//--------------------------------Quick Sort------------------------------------


int ParticionaCre(int *v, int inicio, int fim){
  //Declaração de variáveis
  int dir, esq, pivo;
  //A variável esq recebe o valor armazenado na variável inicio
  esq = inicio;
  //A variável dir recebe o valor armazenado na variável fim
  dir = fim;
  //A variável pivo recebe o valor armazenado na posição inicio do vetor
  pivo = v[inicio];
  //Enquanto o valor de esq menor que o valor de dir
  while(esq < dir){
    //Enquanto o valor de v[esq] <= ao valor de pivo e o valor de esq <= ao valor de fim
    while(v[esq] <= pivo && esq <= fim){
      //Incrementação no valor da variável esq
      esq++;
    }//while
    //Enquanto o valor de v[dir] > que o valor de pivo e o valor de dir >= ao valor de inicio
    while(v[dir] > pivo && dir >= inicio){
      //Decrementação no valor da variável dir
      dir--;
    }//while
    //Se o valor armazenado na variável esq for menor que o valor armazenado em dir
    if(esq < dir){
      //Chama a função troca para inverter os valores de posição
      troca(&v[esq], &v[dir]);
    }//if
  }//while
  //Chama a função troca para inverter os valores de posição
  troca(&v[dir], &v[inicio]);
  //Retorna dir como valor da função
  return dir;
}//ParticionaCre


void QuickSortCre(int *v, int inicio, int fim){
  //Declaração de variável
  int pivo;
  //Se o valor armazenado na variável inicio for menor que o valor armazenado em fim
  if(inicio < fim){
    //Variável pivo recebe o valor da função ParticionaCre
    pivo = ParticionaCre(v, inicio, fim);
    //Chamadas recursivas da função QuickSortCre
    QuickSortCre(v, inicio, pivo - 1);
    QuickSortCre(v, pivo + 1, fim);
  }//if
}//QuickSortCre


int ParticionaDec(int *v, int inicio, int fim){
  //Declaração de variáveis
  int dir, esq, pivo;
  //A variável esq recebe o valor armazenado na variável inicio
  esq = inicio;
  //A variável dir recebe o valor armazenado na variável fim
  dir = fim;
  //A variável pivo recebe o valor armazenado na posição inicio do vetor
  pivo = v[inicio];
  //Enquanto o valor de esq menor que o valor de dir
  while(esq < dir){
    //Enquanto o valor de v[esq] >= ao valor de pivo e o valor de esq <= ao valor de fim
    while(v[esq] >= pivo && esq <= fim){
      //Incrementação no valor da variável esq
      esq++;
    }//while
    //Enquanto o valor de v[dir] < que o valor de pivo e o valor de dir >= ao valor de inicio
    while(v[dir] < pivo && dir >= inicio){
      //Decrementação no valor da variável dir
      dir--;
    }//while
    //Se o valor armazenado na variável esq for menor que o valor armazenado em dir
    if(esq < dir){
      //Chama a função troca para inverter os valores de posição
      troca(&v[esq], &v[dir]);
    }//if
  }//while
  //Chama a função troca para inverter os valores de posição
  troca(&v[dir], &v[inicio]);
  //Retorna dir como valor da função
  return dir;
}//ParticionaDec


void QuickSortDec(int *v, int inicio, int fim){
  //Declaração de variável
  int pivo;
  //Se o valor armazenado na variável inicio for menor que o valor armazenado em fim
  if(inicio < fim){
    //Variável pivo recebe o valor da função ParticionaDec
    pivo = ParticionaDec(v, inicio, fim);
    //Chamadas recursivas da função QuickSortDec
    QuickSortDec(v, inicio, pivo - 1);
    QuickSortDec(v, pivo + 1, fim);
  }//if
}//QuickSortDec


//--------------------------------Merge Sort------------------------------------


int AuxMerge(int *v, int inicio, int meio, int fim){
  //Declaração de variáveis
  int *aux, p1, p2, auy, temp, auxSize, j, i = 0;
  //A variável auxSize recebe o valor de (fim - inicio) + 1
  auxSize = (fim - inicio) + 1;
  //Ponteiro aux recebe o valor da função Aloca com a passagem do valor de auxSize por parâmetro
  aux = Aloca(auxSize);
  //Variável p1 recebe o valor armazenado na variável inicio, passada por parâmetro
  p1 = inicio;
  //Variável p2 recebe o valor armazenado na variável meio, passada por parâmetro, + 1
  p2 = meio + 1;
  //Enquanto o valor de p1 for <= ao valor de meio e o valor de p2 for <= ao valor de fim
  while(p1 <= meio && p2 <= fim){
    //Se o valor armazenado na posição p1 do vetor v for menor que o armazenado na posição p2
    if(v[p1] < v[p2]){
      //Vetor aux na posição i++ recebe o valor armazenado na posição p1++ do vetor v
      aux[i++] = v[p1++];
    //Se não
    }else{
      //Vetor aux na posição i++ recebe o valor armazenado na posição p2++ do vetor v
      aux[i++] = v[p2++];
    }//else
  }//while
  //Se o valor armazenado em p1 for maior que o valor armazenado na variável meio
  if(p1 > meio){
    //Variável auy recebe o valor de (fim - p2 + 1)
    auy = (fim - p2 + 1);
    //Looping para percorrer os vetores da posição 0 até auy - 1
    for (j = 0; j < auy; j++) {
      //Vetor aux na posição i++ recebe o valor armazenado na posição p2++ do vetor v
      aux[i++] = v[p2++];
    }//for
  //Se não
  }else{
    //Variável auy recebe o valor de (meio - p1 + 1)
    auy = (meio - p1 + 1);
    //Looping para percorrer os vetores da posição 0 até auy - 1
    for (j = 0; j < auy; j++) {
      //Vetor aux na posição i++ recebe o valor armazenado na posição p1++ do vetor v
      aux[i++] = v[p1++];
    }//for
  }//else
  //Variável temp recebe o valor armazenado na variável inicio
  temp = inicio;
  //Looping para percorrer os vetores da posição 0 até auxSize - 1
  for(j = 0; j < auxSize; j++){
    //Vetor v na posição temp++ recebe o valor armazenado na posição j do vetor aux
    v[temp++] = aux[j];
  }//for
  //Libera a memória alocada de aux
  free(aux);
}//AuxMerge


void MergeSort(int *v, int inicio, int fim){
  //Declaração de variável
  int meio;
  //Se o valor armazenado na variável inicio for menor que o valor armazenado em fim
  if(inicio < fim){
    //A variável meio recebe o valor de (inicio + fim)/2 arrendondado para baixo
    meio = (int)floor((inicio + fim) / 2);
    //Chama a função de MergeSort para o inicio até o meio
    MergeSort(v, inicio, meio);
    //Chama a função de MergeSort para o meio+1 até o fim
    MergeSort(v, (meio + 1), fim);
    //Chama a função AuxMerge
    AuxMerge(v, inicio, meio, fim);
  }//if
}//MergeSort


int AuxMergeRev(int *v, int inicio, int meio, int fim){
  //Declaração de variáveis
  int *aux, p1, p2, auy, temp, auxSize, j, i = 0;
  //A variável auxSize recebe o valor de (fim - inicio) + 1
  auxSize = (fim - inicio) + 1;
  //Ponteiro aux recebe o valor da função Aloca com a passagem do valor de auxSize por parâmetro
  aux = Aloca(auxSize);
  //Variável p1 recebe o valor armazenado na variável inicio, passada por parâmetro
  p1 = inicio;
  //Variável p2 recebe o valor armazenado na variável meio, passada por parâmetro, + 1
  p2 = meio + 1;
  //Enquanto o valor de p1 for <= ao valor de meio e o valor de p2 for <= ao valor de fim
  while(p1 <= meio && p2 <= fim){
    //Se o valor armazenado na posição p1 do vetor v for menor que o armazenado na posição p2
    if(v[p1] > v[p2]){
      //Vetor aux na posição i++ recebe o valor armazenado na posição p1++ do vetor v
      aux[i++] = v[p1++];
    //Se não
    }else{
      //Vetor aux na posição i++ recebe o valor armazenado na posição p2++ do vetor v
      aux[i++] = v[p2++];
    }//else
  }//while
  //Se o valor armazenado em p1 for maior que o valor armazenado na variável meio
  if(p1 > meio){
    //Variável auy recebe o valor de (fim - p2 + 1)
    auy = (fim - p2 + 1);
    //Looping para percorrer os vetores da posição 0 até auy - 1
    for (j = 0; j < auy; j++) {
      //Vetor aux na posição i++ recebe o valor armazenado na posição p2++ do vetor v
      aux[i++] = v[p2++];
    }//for
  //Se não
  }else{
    //Variável auy recebe o valor de (meio - p1 + 1)
    auy = (meio - p1 + 1);
    //Looping para percorrer os vetores da posição 0 até auy - 1
    for (j = 0; j < auy; j++) {
      //Vetor aux na posição i++ recebe o valor armazenado na posição p1++ do vetor v
      aux[i++] = v[p1++];
    }//for
  }//else
  //Variável temp recebe o valor armazenado na variável inicio
  temp = inicio;
  //Looping para percorrer os vetores da posição 0 até auxSize - 1
  for(j = 0; j < auxSize; j++){
    //Vetor v na posição temp++ recebe o valor armazenado na posição j do vetor aux
    v[temp++] = aux[j];
  }//for
  //Libera a memória alocada de aux
  free(aux);
}//AuxMergeRev


void MergeSortRev(int *v, int inicio, int fim){
  //Declaração de variável
  int meio;
  //Se o valor armazenado na variável inicio for menor que o valor armazenado em fim
  if(inicio < fim){
    //A variável meio recebe o valor de (inicio + fim)/2 arrendondado para baixo
    meio = (int)floor((inicio + fim) / 2);
    //Chama a função de MergeSortRev para o inicio até o meio
    MergeSortRev(v, inicio, meio);
    //Chama a função de MergeSortRev para o meio+1 até o fim
    MergeSortRev(v, (meio + 1), fim);
    //Chama a função AuxMergeRev
    AuxMergeRev(v, inicio, meio, fim);
  }//if
}//MergeSortRev


//---------------------------------Heap Sort------------------------------------


void MaxHeapify(int *v, int i, int tamheap){
  //Variável e recebe o valor de (2*i)
  int esq = (2*i);
  //Variável d recebe o valor de (2*i) + 1
  int dir = (2*i)+1;
  //Variável menor recebe i
  int maior = i;
  //Se o valor de esq <= ao valor de tamheap e o valor armazenado na posição esq do vetor for maior que o valor na posição i do vetor
  if (esq <= tamheap && v[esq] > v[i]) {
    //Variável maior recebe o valor armazenado em esq
    maior = esq;
  }//if
  //Se o valor de dir <= ao valor de tamheap e o valor armazenado na posição dir do vetor for maior que o valor na posição maior do vetor
  if (dir <= tamheap && v[dir] > v[maior]) {
    //Variável maior recebe o valor armazenado em dir
    maior = dir;
  }//if
  //Se o valor armazenado na variável maior for diferente do valor de i
  if (maior != i) {
    //Chama a função troca para inverter os valores de posição
    troca(&v[i], &v[maior]);
    //Chamada recursiva da função MaxHeapify
    MaxHeapify(v, maior, tamheap);
  }//if
}//MaxHeapify


void BuildMaxHeapify(int *v, int tamheap, int tam){
  //Declaração de variável i inicializada com valor 0
  int i = 0;
  //Looping para percorrer o vetor da posição tam/2, arredondada para baixo, até a posição 0
  for (i = (floor(tam/2)); i >= 0 ; i--) {
    //Chama a função MaxHeapify
    MaxHeapify(v, i, tamheap);
  }//for
}//BuildMaxHeapify


void HeapSort(int *v, int tam){
  //Declaração de variável inicializada com o valor de tam
  int tamheap = tam;
  //Chama a função BuildMaxHeapify
  BuildMaxHeapify(v,tamheap, tam);
  //Looping para trocar os valores de todas as posições do vetor com o valor da posição 0
  for (int i = tam; i >= 1; i--) {
    //Chama a função troca para inverter os valores de posição
    troca(&v[0], &v[i]);
    //Decrementa no valor da variável tamheap
    tamheap--;
    //Chama a função MaxHeapify
    MaxHeapify(v, 0, tamheap);
  }//for
}//HeapSort


void MaxHeapifyRev(int *v, int i, int tamheap){
  //Variável e recebe o valor de (2*i)
  int esq = (2*i);
  //Variável d recebe o valor de (2*i) + 1
  int dir = (2*i)+1;
  //Variável menor recebe i
  int maior = i;
  //Se o valor de esq <= ao valor de tamheap e o valor armazenado na posição esq do vetor for menor que o valor na posição i do vetor
  if (esq <= tamheap && v[esq] < v[i]) {
    //Variável maior recebe o valor armazenado em esq
    maior = esq;
  }//if
  //Se o valor de dir <= ao valor de tamheap e o valor armazenado na posição dir do vetor for menor que o valor na posição maior do vetor
  if (dir <= tamheap && v[dir] < v[maior]) {
    //Variável maior recebe o valor armazenado em dir
    maior = dir;
  }//if
  //Se o valor armazenado na variável maior for diferente do valor de i
  if (maior != i) {
    //Chama a função troca para inverter os valores de posição
    troca(&v[i], &v[maior]);
    //Chamada recursiva da função MaxHeapifyRev
    MaxHeapifyRev(v, maior, tamheap);
  }//if
}//MaxHeapifyRev


void BuildMaxHeapifyRev(int *v, int tamheap, int tam){
  //Declaração de variável i inicializada com valor 0
  int i = 0;
  //Looping para percorrer o vetor da posição tam/2, arredondada para baixo, até a posição 0
  for (i = (floor(tam/2)); i >= 0 ; i--) {
    //Chama a função MaxHeapifyRev
    MaxHeapifyRev(v, i, tamheap);
  }//for
}//BuildMaxHeapifyRev


void HeapSortRev(int *v, int tam){
  //Declaração de variável inicializada com o valor de tam
  int tamheap = tam;
  //Chama a função BuildMaxHeapifyRev
  BuildMaxHeapifyRev(v,tamheap, tam);
  //Looping para trocar os valores de todas as posições do vetor com o valor da posição 0
  for (int i = tam; i >= 1; i--) {
    //Chama a função troca para inverter os valores de posição
    troca(&v[0], &v[i]);
    //Decrementa no valor da variável tamheap
    tamheap--;
    //Chama a função MaxHeapifyRev
    MaxHeapifyRev(v, 0, tamheap);
  }//for
}//HeapSortRev


//------------------------------Insertion Sort----------------------------------


void InsertionSort(int *v, int n){
  //Declaração de variáveis
  int aux = 0;
  int j = 0;
  //Looping para percorrer as posições do vetor
  for(int i = 1; i < n; i++) {
    //Variável auxiliar recebe o valor armazenado na posição i do vetor v
    aux = v[i];
    //Variável j recebe o valor de i - 1
    j = i - 1;
    //Enquanto j >= 0 e o valor armazenado na posição j do vetor for maior que o valor armazenado na variável aux
    while(j >= 0 && v[j] > aux){
      //A posição j + 1 do vetor recebe o valor armazenado na posição j do vetor
      v[j + 1] = v[j];
      //Decrementação no valor de j
      j--;
    }//while
    //A posição j + 1 do vetor recebe o valor armazenado na variável aux
    v[j + 1] = aux;
  }//for
}//InsertionSort


void InsertionSortRev(int *v, int n){
  //Declaração de variáveis
  int aux = 0;
  int j = 0;
  //Looping para percorrer as posições do vetor
  for(int i = 1; i < n; i++) {
    //Variável auxiliar recebe o valor armazenado na posição i do vetor v
    aux = v[i];
    //Variável j recebe o valor de i - 1
    j = i - 1;
    //Enquanto j >= 0 e o valor armazenado na variável aux for maior que o valor armazenado na posição j do vetor
    while(j >= 0 && aux > v[j]){
      //A posição j + 1 do vetor recebe o valor armazenado na posição j do vetor
      v[j + 1] = v[j];
      //Decrementação no valor de j
      j--;
    }//while
    //A posição j + 1 do vetor recebe o valor armazenado na variável aux
    v[j + 1] = aux;
  }//for
}//InsertionSortRev


//----------------------------------Main----------------------------------------


int main(int argc, char const *argv[]){
  //Abre e retorna um ponteiro para o arquivo de entrada
  FILE* entrada = fopen(argv[1], "r");
  //Abre e retorna um ponteiro para o arquivo de saída
  FILE* saida = fopen(argv[2], "w");
  //Se a quantidade de parâmetros for diferente de 3
  if(argc!= 3) {
    //Exibe mensagem de erro
    printf("Quantidade de parametros invalida\n");
    //Encerra o programa retornando 0 como valor da função
    return 0;
  }//if
  //Verifica se existe erro na abertura dos arquivos
  if(entrada == NULL || saida == NULL) {
    //Exibe a mensagem de erro
    perror("Error ");
    //Encerra o programa retornando 0 como valor da função
    return 0;
  }//if
  //Declaração de variáveis
  int size = 0, top = 0, quant = 0, linhas = 0;
  char sort, order;
  //Variavél linhas recebe o valor da função contaLinha
  linhas = contaLinha(entrada);
  //Lê o header do arquivo de entrada e armazena as informações nas variáveis
  fscanf(entrada, "SIZE=%d TOP=%d QTDE=%d SORT=%c ORDER=%c", &size, &top, &quant, &sort, &order);
  //Declaração de vetor Heroi e vetor v de tamanho quant
  Heroi h[quant];
  int v[quant];
  if (linhas != (quant + 1)) {
    //Salva no arquivo de saída que arquivo é invalido
    fprintf(saida, "Arquivo Inválido!\n");
    //Retorna 0 como valor da função
    return 0;
  }//if
  //Looping para percorrer os vetores
  for(int i = 0; i < quant; i++){
    //Lê do arquivo de entrada as informações presentes em uma linha e salva na posição i do vetor de herois
    fscanf(entrada, " %[^|]|%[^\n]\n", h[i].chave, h[i].resto);
    //A posição i do vetor v recebe o valor (int) da chave da posição i do vetor de herois
    v[i] = atoi(h[i].chave);
  }//for
  //Se o caracter armazenado em order for igual a 'C'
  if(order == 'C'){
    //Se o caracter armazenado em sort for igual a 'Q'
    if(sort == 'Q'){
      //Chama a função QuickSortCre para ordenar o vetor v
      QuickSortCre(v, 0, (quant-1));
      //Chama a função arqSaida para salvar as informações no arquivo de saída
      arqSaida(saida, v, quant, h, size, top, sort, order);
    }//if
    //Se o caracter armazenado em sort for igual a 'H'
    if(sort == 'H'){
      //Chama a função HeapSort para ordenar o vetor v
      HeapSort(v, (quant-1));
      //Chama a função arqSaida para salvar as informações no arquivo de saída
      arqSaida(saida, v, quant, h, size, top, sort, order);
    }//if
    //Se o caracter armazenado em sort for igual a 'M'
    if(sort == 'M'){
      //Chama a função MergeSort para ordenar o vetor v
      MergeSort(v, 0, (quant-1));
      //Chama a função arqSaida para salvar as informações no arquivo de saída
      arqSaida(saida, v, quant, h, size, top, sort, order);
    }//if
    //Se o caracter armazenado em sort for igual a 'I'
    if(sort == 'I'){
      //Chama a função InsertionSort para ordenar o vetor v
      InsertionSort(v, quant);
      //Chama a função arqSaida para salvar as informações no arquivo de saída
      arqSaida(saida, v, quant, h, size, top, sort, order);
    }//if
    //Se o caracter armazenado em order for 'C' e em sort não for nenhum dos citados acima
    if (sort != 'Q' && sort != 'H' && sort != 'M' && sort != 'I') {
      //Salva no arquivo de saída que arquivo é invalido
      fprintf(saida, "Arquivo Inválido!\n");
      //Retorna 0 como valor da função
      return 0;
    }//if
  }//if
  //Se o caracter armazenado em order for igual a 'D'
  if(order == 'D'){
    //Se o caracter armazenado em sort for igual a 'Q'
    if(sort == 'Q'){
      QuickSortDec(v, 0, (quant-1));
      //Chama a função arqSaida para salvar as informações no arquivo de saída
      arqSaida(saida, v, quant, h, size, top, sort, order);
    }//if
    //Se o caracter armazenado em sort for igual a 'H'
    if(sort == 'H'){
      HeapSortRev(v, (quant-1));
      //Chama a função arqSaida para salvar as informações no arquivo de saída
      arqSaida(saida, v, quant, h, size, top, sort, order);
    }//if
    //Se o caracter armazenado em sort for igual a 'M'
    if(sort == 'M'){
      MergeSortRev(v, 0, (quant-1));
      //Chama a função arqSaida para salvar as informações no arquivo de saída
      arqSaida(saida, v, quant, h, size, top, sort, order);
    }//if
    //Se o caracter armazenado em sort for igual a 'I'
    if(sort == 'I'){
      InsertionSortRev(v, quant);
      //Chama a função arqSaida para salvar as informações no arquivo de saída
      arqSaida(saida, v, quant, h, size, top, sort, order);
    }//if
    //Se o caracter armazenado em order for 'C' e em sort não for nenhum dos citados acima
    if (sort != 'Q' && sort != 'H' && sort != 'M' && sort != 'I') {
      //Salva no arquivo de saída que arquivo é invalido
      fprintf(saida, "Arquivo Inválido!\n");
      //Retorna 0 como valor da função
      return 0;
    }//if
  }//if
  //Se o caracter armazenado em order não for igual a 'D' ou 'C'
  if (order != 'D' && order != 'C') {
    //Salva no arquivo de saída que arquivo é invalido
    fprintf(saida, "Arquivo Inválido!\n");
    //Retorna 0 como valor da função
    return 0;
  }//if
  //Fecha os arquivos de entrada e saida
  fclose(entrada);
  fclose(saida);
  //Retorna 0 como valor da função
  return 0;
}//main
