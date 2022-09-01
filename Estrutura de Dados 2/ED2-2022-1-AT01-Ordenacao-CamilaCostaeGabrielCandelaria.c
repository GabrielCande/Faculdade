//Declaração de Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


//------------------------------------------------------------------------------
//-------------------------------Utilitárias------------------------------------


void printa(int *v, int n, int cmp, clock_t ms, FILE *saida){
  //Looping para percorrer todas as posições do vetor
  for(int i = 0; i < n; i++){
    //Printa o valor na posição i do vetor no arquivo de saída
    fprintf(saida, " %i", v[i]);
  }//for
  //Printa o número de comparações e o tempo gasto no arquivo de saída
  fprintf(saida, ", %d comp, %i ms\n", (int)cmp, (int)ms);
}//printa


void printaVet(int *v, int n, int *cmpx, clock_t ms, FILE *saida){
  //Looping para percorrer todas as posições do vetor
  for(int i = 0; i < n; i++){
    //Printa o valor na posição i do vetor no arquivo de saída
    fprintf(saida, " %i", v[i]);
  }//for
  //Printa o número de comparações e o tempo gasto no arquivo de saída
  fprintf(saida, ", %d comp, %i ms\n", cmpx[0], (int)ms);
}//printaVet


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


int *Aloca(int tam){
  //Declaração de um ponteiro vetor
  int *vetor;
  //Alocação de memória para o vetor de tamanho tam
  vetor = (int*) malloc (tam * sizeof(int));
  //Retorna o ponteiro para o vetor como valor da função
  return vetor;
}//Aloca


int *VetReset(int *v, int n){
  //Declaração de um ponteiro vetor auxiliador e alocação de memória de tamanho n para o mesmo
  int *auxv = (int*) malloc (n * sizeof(int));
  //Looping para percorrer todas as posições dos vetores v e auxv
  for(int i = 0; i < n; i++){
    //A posição i do vetor auxv recebe o valor da posição i do vetor v
    auxv[i] = v[i];
  }//for
  //Retorna o ponteiro para o vetor auxiliador como valor da função
  return auxv;
}//VetReset


//------------------------------------------------------------------------------
//------------------------------InsertionSort-----------------------------------


int InsertionSort(int *v, int n){
  //Declaração de variáveis e contador
  int cmp = 0;
  int aux = 0;
  int j = 0;
  //Looping para percorrer as posições do vetor
  for(int i = 1; i < n; i++) {
    //Variável auxiliar recebe o valor armazenado na posição i do vetor v
    aux = v[i];
    //Variável j recebe o valor de i - 1
    j = i - 1;
    //Incrementação no valor do contador
    cmp ++;
    //Enquanto j >= 0 e o valor armazenado na posição j do vetor for maior que o valor armazenado na variável aux
    while(j >= 0 && v[j] > aux){
      //A posição j + 1 do vetor recebe o valor armazenado na posição j do vetor
      v[j + 1] = v[j];
      //Decrementação no valor de j
      j--;
      //Incrementação no valor do contador
      cmp ++;
    }//while
    //Se j < 0
    if (j < 0) {
      //Decrementação no valor do contador
      cmp--;
    }//if
    //A posição j + 1 do vetor recebe o valor armazenado na variável aux
    v[j + 1] = aux;
  }//for
  //Retorna o valor do contador como valor da função
  return cmp;
}//InsertionSort


//------------------------------------------------------------------------------
//------------------------------SelectionSort-----------------------------------


int SelectionSort (int*v, int n){
  //Declaração de contador
  int cmp = 0;
  //Looping para percorrer as posições do vetor
  for(int i = 0; i < n - 1; i++){
    //Variável menor recebe i
    int menor = i;
    //Variável temporária recebe o valor armazenado na posição i do vetor
    int temp = v[i];
    //Looping para percorrer as próximas posições do vetor a partir de i + 1
    for(int j = i + 1; j < n; j++){
      //Incrementação no valor do contador
      cmp++;
      //Se o valor armazenado na variável temp for maior que o valor armazenado na posição j do vetor
      if(temp > v[j]){
        //temp recebe o valor armazenado na posição j do vetor
        temp = v[j];
        //Variável menor recebe j
        menor = j;
      }//if
    }//for
    //Se i menor que o valor armazenado na variável menor
    if (i < menor) {
      //Chama a função troca para inverter os valores de posição
      troca(&v[i], &v[menor]);
    }//if
  }//for
  //Retorna o valor do contador como valor da função
  return cmp;
}//SelectionSort


//------------------------------------------------------------------------------
//-------------------------------BubbleSort-------------------------------------


int BubbleSort (int *v, int n){
  //Declaração de contador
  int cmp = 0;
  //Declaração de variável booleana que recebe true
  bool trocou = true;
  //Enquanto trocou for true
  while(trocou){
    //trocou recebe false
    trocou = false;
    //Looping para percorrer o vetor até a penúltima posição
    for(int i = 0; i < (n - 1); i++){
      //Incrementação no valor do contador
      cmp++;
      //Se o valor armazenado na posição i do vetor for maior que o valor armazenado na posição i+1
      if(v[i] > v[i+1]){
        //Chama a função troca para inverter os valores de posição
        troca(&v[i], &v[i+1]);
        //trocou recebe true
        trocou = true;
      }//if
    }//for
    //Decrementação do valor de n já que o valor na última posição do vetor está no lugar correto
    n--;
  }//while
  //Retorna o valor do contador como valor da função
  return cmp;
}//BubbleSort


//------------------------------------------------------------------------------
//--------------------------------MergeSort-------------------------------------


int AuxMerge(int *v, int inicio, int meio, int fim, int cmp){
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
    //Incrementação no valor do contador
    cmp ++;
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
  //Retorna o valor do contador como valor da função
  return cmp;
}//AuxMerge


int MergeSort(int *v, int inicio, int fim, int cmp){
  //Declaração de variável
  int meio;
  //Se o valor armazenado na variável inicio for menor que o valor armazenado em fim
  if(inicio < fim){
    //A variável meio recebe o valor de (inicio + fim)/2 arrendondado para baixo
    meio = (int)floor((inicio + fim) / 2);
    //A variável cmp recebe o valor da função MergeSort
    cmp = MergeSort(v, inicio, meio, cmp);
    //A variável cmp recebe o valor da função MergeSort
    cmp = MergeSort(v, (meio + 1), fim, cmp);
    //A variável cmp recebe o valor da função AuxMerge
    cmp = AuxMerge(v, inicio, meio, fim, cmp);
  }//if
  //Retorna o valor do contador como valor da função
  return cmp;
}//MergeSort


//------------------------------------------------------------------------------
//--------------------------------QuickSort-------------------------------------


int Particiona(int *v, int inicio, int fim, int *cmpx){
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
      //Incrementação no valor do contador
      cmpx[0]++;
      //Incrementação no valor da variável esq
      esq++;
    }//while
    //Enquanto o valor de v[dir] > que o valor de pivo e o valor de dir >= ao valor de inicio
    while(v[dir] > pivo && dir >= inicio){
      //Incrementação no valor do contador
      cmpx[0]++;
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
}//Particiona


void QuickSort(int *v, int inicio, int fim, int *cmpx){
  //Declaração de variável
  int pivo;
  //Se o valor armazenado na variável inicio for menor que o valor armazenado em fim
  if(inicio < fim){
    //Variável pivo recebe o valor da função Particiona
    pivo = Particiona(v, inicio, fim, cmpx);
    //Chamadas recursivas da função QuickSort
    QuickSort(v, inicio, pivo - 1, cmpx);
    QuickSort(v, pivo + 1, fim, cmpx);
  }//if
}//QuickSort


//------------------------------------------------------------------------------
//--------------------------------HeapSort--------------------------------------


void MaxHeapify(int *v, int i, int tamheap, int *cmpx){
  //Variável e recebe o valor de (2*i) + 1
  int esq = (2*i)+1;
  //Variável d recebe o valor de (2*i) + 2
  int dir = (2*i)+2;
  //Variável menor recebe i
  int maior = i;
  //Incrementação no valor do contador
  cmpx[0]++;
  //Se o valor de esq <= ao valor de tamheap e o valor armazenado na posição esq do vetor for maior que o valor na posição i do vetor
  if (esq <= tamheap && v[esq] > v[i]) {
    //Variável maior recebe o valor armazenado em esq
    maior = esq;
  }//if
  //Incrementação no valor do contador
  cmpx[0]++;
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
    MaxHeapify(v, maior, tamheap, cmpx);
  }//if
}//MaxHeapify


void BuildMaxHeapify(int *v, int tamheap, int tam, int *cmpx){
  //Declaração de variável i inicializada com valor 0
  int i = 0;
  //Looping para percorrer o vetor da posição tam/2, arredondada para baixo, até a posição 0
  for (i = (floor(tam/2)); i >= 0 ; i--) {
    //Chama a função MaxHeapify
    MaxHeapify(v, i, tamheap, cmpx);
  }//for
}//BuildMaxHeapify


void HeapSort(int *v, int tam, int *cmpx){
  //Declaração de variável inicializada com o valor de tam
  int tamheap = tam;
  //Chama a função BuildMaxHeapify
  BuildMaxHeapify(v, tamheap, tam, cmpx);
  //Looping para trocar os valores de todas as posições do vetor com o valor da posição 0
  for (int i = tam; i >= 1; i--) {
    //Chama a função troca para inverter os valores de posição
    troca(&v[0], &v[i]);
    //Decrementa no valor da variável tamheap
    tamheap--;
    //Chama a função MaxHeapify
    MaxHeapify(v, 0, tamheap, cmpx);
  }//for
}//HeapSort


//------------------------------------------------------------------------------
//-----------------------------Função Principal---------------------------------


int main(int argc, char const *argv[]){
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
  //Declaração de variáveis inteiras e variáveis de tempo
  clock_t tInicial, tFinal, ms;
  int temp, *v, aux, *auxv, cmp;
  //Lê a primeira linha do arquivo de entrada e armazena o tamanho do vetor na variável temp
  fscanf(entrada, "%d\n", &temp);
  //Declaração de variável n inicializada com o valor armazenado na variável temp
  int n = (int)temp;
  //Declaração de uma variável do tipo char
  char opcao;
  //Variável opcao recebe a letra que diz de que forma o vetor deve ser criado
  opcao = fgetc(entrada);
  //Alocação de memória para o vator v de tamanho n
  v = Aloca(n);
  //Laço de condição que verifica o valor armazenado na variável opcao
  switch(opcao){
    //Caso o valor de opcao seja c
    case 'c':
      //Looping para percorrer o vetor v e armazenar valores de forma crescente
      for(int i = 0; i < n; i++){
        //O vetor na posição i recebe o valor de i + 1
        v[i] = i + 1;
      }//for
    //Quebra do laço de repetição
    break;
    //Caso o valor de opcao seja d
    case 'd':
      //Variável aux recebe o valor armazenado em n
      aux = n;
      //Looping para percorrer o vetor v e armazenar valores de forma decrescente
      for(int i = 0; i < n; i++){
        //O vetor na posição i recebe o valor de aux--
        v[i] = aux--;
      }//for
    //Quebra do laço de repetição
    break;
    //Caso o valor de opcao seja r
    case 'r':
      //Looping para percorrer o vetor v e armazenar valores de forma randômica
      for(int i = 0; i < n; i++){
        //O vetor na posição i recebe um valor entre 0 e 32000
        v[i] = rand() % 32001;
      }//for
    //Quebra do laço de repetição
    break;
    //Caso o valor de opcao não seja nenhuma das listadas acima
    default:
      //Printa no arquivo de saída que o arquivo é inválido
      fprintf(saida, "Arquivo inválido!\n");
      //Libera a memória alocada de auxv e v
      free(auxv);
      free(v);
      //Fecha os arquivos de entrada e saída
      fclose(entrada);
      fclose(saida);
      //Retorna 0 como valor da função
      return 0;
    //Quebra do laço de repetição
    break;
  }//switch

  //------------------------------InsertionSort-----------------------------------

  //Variável auxv recebe o valor da função VetReset
  auxv = VetReset(v, n);
  //Printa no arquivo de saída o respectivo modo de ordenação
  fprintf(saida, "insertionSort:");
  //Armazena na variável tInicial o tempo assim que o vetor começou a ser ordenado
  tInicial = clock();
  //Chama a função InsertionSort para ordenar o vetor auxv e a variável cmp recebe o valor da função
  cmp = InsertionSort(auxv, n);
  //Armazena na variável tFinal o após o vetor estar ordenado
  tFinal = clock();
  //A variável ms armazena o tempo em que o vetor levou para ser ordenado em milissegundos
  ms = (tFinal - tInicial)/(CLOCKS_PER_SEC/1000);
  //Chama a função printa para salvar no arquivo de saída os resultados obtidos
  printa(auxv, n, cmp, ms, saida);
  //Libera a memória alocada de auxv
  free(auxv);

  //------------------------------SelectionSort-----------------------------------

  //Variável auxv recebe o valor da função VetReset
  auxv = VetReset(v, n);
  //Printa no arquivo de saída o respectivo modo de ordenação
  fprintf(saida, "selectionSort:");
  //Armazena na variável tInicial o tempo assim que o vetor começou a ser ordenado
  tInicial = clock();
  //Chama a função SelectionSort para ordenar o vetor auxv e a variável cmp recebe o valor da função
  cmp = SelectionSort(auxv, n);
  //Armazena na variável tFinal o após o vetor estar ordenado
  tFinal = clock();
  //A variável ms armazena o tempo em que o vetor levou para ser ordenado em milissegundos
  ms = (tFinal - tInicial)/(CLOCKS_PER_SEC/1000);
  //Chama a função printa para salvar no arquivo de saída os resultados obtidos
  printa(auxv, n, cmp, ms, saida);
  //Libera a memória alocada de auxv
  free(auxv);

  //-------------------------------BubbleSort-------------------------------------

  //Variável auxv recebe o valor da função VetReset
  auxv = VetReset(v, n);
  //Printa no arquivo de saída o respectivo modo de ordenação
  fprintf(saida, "bubbleSort:");
  //Armazena na variável tInicial o tempo assim que o vetor começou a ser ordenado
  tInicial = clock();
  //Chama a função BubbleSort para ordenar o vetor auxv e a variável cmp recebe o valor da função
  cmp = BubbleSort(auxv, n);
  //Armazena na variável tFinal o após o vetor estar ordenado
  tFinal = clock();
  //A variável ms armazena o tempo em que o vetor levou para ser ordenado em milissegundos
  ms = (tFinal - tInicial)/(CLOCKS_PER_SEC/1000);
  //Chama a função printa para salvar no arquivo de saída os resultados obtidos
  printa(auxv, n, cmp, ms, saida);
  //Libera a memória alocada de auxv
  free(auxv);

//--------------------------------MergeSort-------------------------------------

  //A variável cmp recebe o valor 0
  cmp = 0;
  //Variável auxv recebe o valor da função VetReset
  auxv = VetReset(v, n);
  //Printa no arquivo de saída o respectivo modo de ordenação
  fprintf(saida, "mergeSort:");
  //Armazena na variável tInicial o tempo assim que o vetor começou a ser ordenado
  tInicial = clock();
  //Chama a função MergeSort para ordenar o vetor auxv e a variável cmp recebe o valor da função
  cmp = MergeSort(auxv, 0, n-1, cmp);
  //Armazena na variável tFinal o após o vetor estar ordenado
  tFinal = clock();
  //A variável ms armazena o tempo em que o vetor levou para ser ordenado em milissegundos
  ms = (tFinal - tInicial)/(CLOCKS_PER_SEC/1000);
  //Chama a função printa para salvar no arquivo de saída os resultados obtidos
  printa(auxv, n, cmp, ms, saida);
  //Libera a memória alocada de auxv
  free(auxv);

//--------------------------------QuickSort-------------------------------------

  //Declaração de ponteiro inicializado com o valor da função Aloca com a passagem do valor 1 por parâmetro
  int *cmpx = Aloca(1);
  //A posição 0 no vetor cmpx recebe valor 0
  cmpx[0] = 0;
  //Variável auxv recebe o valor da função VetReset
  auxv = VetReset(v, n);
  //Printa no arquivo de saída o respectivo modo de ordenação
  fprintf(saida, "quickSort:");
  //Armazena na variável tInicial o tempo assim que o vetor começou a ser ordenado
  tInicial = clock();
  //Chama a função QuickSort para ordenar o vetor auxv
  QuickSort(auxv, 0, n-1, cmpx);
  //Armazena na variável tFinal o após o vetor estar ordenado
  tFinal = clock();
  //A variável ms armazena o tempo em que o vetor levou para ser ordenado em milissegundos
  ms = (tFinal - tInicial)/(CLOCKS_PER_SEC/1000);
  //Chama a função printaVet para salvar no arquivo de saída os resultados obtidos
  printaVet(auxv, n, cmpx, ms, saida);
  //Libera a memória alocada de auxv e cmpx
  free(auxv);
  free(cmpx);

//--------------------------------HeapSort--------------------------------------

  //Ponteiro cmpx recebe o valor da função Aloca com a passagem do valor 1 por parâmetro
  cmpx = Aloca(1);
  //A posição 0 no vetor cmpx recebe valor 0
  cmpx[0] = 0;
  //Variável auxv recebe o valor da função VetReset
  auxv = VetReset(v, n);
  //Printa no arquivo de saída o respectivo modo de ordenação
  fprintf(saida, "heapSort:");
  //Armazena na variável tInicial o tempo assim que o vetor começou a ser ordenado
  tInicial = clock();
  //Chama a função HeapSort para ordenar o vetor auxv
  HeapSort(auxv, n-1, cmpx);
  //Armazena na variável tFinal o após o vetor estar ordenado
  tFinal = clock();
  //A variável ms armazena o tempo em que o vetor levou para ser ordenado em milissegundos
  ms = (tFinal - tInicial)/(CLOCKS_PER_SEC/1000);
  //Chama a função printaVet para salvar no arquivo de saída os resultados obtidos
  printaVet(auxv, n, cmpx, ms, saida);
  //Libera a memória alocada de auxv, cmpx e v
  free(auxv);
  free(cmpx);
  free(v);
  //Fecha os arquivos de entrada e saída
  fclose(entrada);
  fclose(saida);
  //Retorna 0 como valor da função
  return 0;
}//main
