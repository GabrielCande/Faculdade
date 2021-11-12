//  ----------------------------------
//  Integrantes do Grupo:
//  Camila Costa Durante
//  Gabriel Candelária Wiltgen Barbosa
//  ----------------------------------

//Declaração de Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

//Define 256 como o tamanho de TAM
#define TAM 256

//Declaração de vetores e variáveis globais
uint32_t R[32];
uint32_t ram[TAM];
uint32_t opcode, regFont, regTemp, regDest, shamt, funct, immediate;
uint32_t pc = 0, ic = 0;

int pegaValor() {
  //Declara uma variável que vai salvar o valor
  int x;
  //Exibe mensagem pedindo o valor
  printf("Digite o valor desejado: ");
  //Salva o valor digitado em x
  scanf("%d", &x);
  printf("\n");
  //Retorna o valor salvo em x na função
  return x;
}//pegaValor

//Função Principal
int main() {
  //Declara uma variável que irá receber as informações do arquivo binário
  int resultado;
  uint32_t bit = 0;
  //Declara uma string que conterá o nome do arquivo de entrada
  char arquivo[20];
  //Solicita que o usuário digite o nome de um arquivo binário
  printf("Digite o nome de um arquivo binário: ");
  //Armazena o nome do arquivo na string arquivo
  fgets(arquivo, 20, stdin);
  //Subscreve o \n por \0
  arquivo[strcspn(arquivo,"\n")] = '\0';
  //Limpa o buffer do teclado
  setbuf(stdin, NULL);
  //Abre e retorna um ponteiro para o arquivo de entrada
  FILE* arq = fopen(arquivo, "rb");
  //Verifica se existe erro na abertura do arquivo
  if(arq == NULL) {
    //Exibe a mensagem de erro
    perror("Error ");
    //Encerra o programa retornando 0 como valor da função
    return 0;
  }//if
  //A variável resultado recebe quantas informações foram lidas do arquivo e salvas na ram
  resultado = fread (ram, 4,100, arq);
  //Declara uma variável que receberá a instrução do arquivo
  uint32_t instruct;
  //Looping para percorrer cada informação lida do arquivo
  for(int i = 0; i < resultado; i++){
  //A variável pc recebe o valor de i
  pc = i;
  //A variável ic recebe a informação contida na posição pc do vetor ram
  ic = (uint32_t)ram[pc];
  //A variável instruct
  instruct = ((ic & 0xFF000000) >> 24 | (ic & 0x00FF0000) >> 8 | (ic & 0x0000FF00) << 8 |  (ic & 0x000000FF) << 24 );
  //A variável ic recebe instruct
  ic = instruct;
  //Cada variável recebe uma parte da informação
  opcode = (ic & 0xFC000000) >> 26;
  regFont = (ic & 0x3E00000) >> 21;
  regTemp = (ic & 0x1F0000) >> 16;
  regDest = (ic & 0xF800) >> 11;
  shamt = (ic & 0x7C0) >> 6;
  funct = (ic & 0x3F);
  immediate = (ic & 0xffff);
  //Declaração de variáveis auxiliares
  int auxTemp, auxFont;
  //Verificando casos em função de opcode
  switch(opcode){
     	//Caso opcode possua o valor 0x00
	case 0x00:
        //Exibe as informações da cada variável
        printf("\n opcode %01x | regFont %01x | regTemp %01x | regDest %01x | shamt %01x | funct %01x\n\n",
        opcode, regFont, regTemp, regDest, shamt, funct);
        //Verificando casos em função de funct
	switch(funct){
          //--------------------------------- ADD ---------------------------------------
          //Caso funct possua o valor 0x20
	  case 0x20:
            printf("--------Adição-------\n");
            printf("\n----Primeiro Valor---\n");
            //R[regFont] recebe o valor retornado da função pegaValor
            R[regFont] = pegaValor();
            printf("\n----Segundo Valor----\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //Soma o valor de R[regFont] e R[regTemp] e salva em R[regDest]
	    R[regDest] = R[regFont] + R[regTemp];
            //Exibe o valor de R[regDest]
	    printf("A soma dos registradores resultou em %d\n\n", R[regDest]);
	  break;
          //--------------------------------- SUB ---------------------------------------
          //Caso funct possua o valor 0x22
	  case 0x22:
            printf("------Subtração------\n");
            printf("\n----Primeiro Valor---\n");
            //R[regFont] recebe o valor retornado da função pegaValor
            R[regFont] = pegaValor();
            printf("\n----Segundo Valor----\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //Subtrai o valor de R[regFont] e R[regTemp] e salva em R[regDest]
	    R[regDest] = R[regFont] - R[regTemp];
            //Exibe o valor de R[regDest]
	    printf("A subtração dos registradores resultou em %d\n\n", R[regDest]);
	  break;
          //--------------------------------- MULT --------------------------------------
          //Caso funct possua o valor 0x18
          case 0x18:
            printf("----Multiplicação----\n");
            printf("\n----Primeiro Valor---\n");
            //R[regFont] recebe o valor retornado da função pegaValor
            R[regFont] = pegaValor();
            printf("\n----Segundo Valor----\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //Multiplica o valor de R[regFont] e R[regTemp] e salva em R[regDest]
            R[regDest] = R[regFont] * R[regTemp];
            //Exibe o valor de R[regDest]
            printf("A multiplicação dos registradores resultou em %d\n\n", R[regDest]);
          break;
          //--------------------------------- DIV ---------------------------------------
          //Caso funct possua o valor 0x1a
          case 0x1a:
            printf("-------Divisão-------\n");
            printf("\n----Primeiro Valor---\n");
            //R[regFont] recebe o valor retornado da função pegaValor
            R[regFont] = pegaValor();
            printf("\n----Segundo Valor----\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //Divide o valor de R[regFont] e R[regTemp] e salva em R[regDest]
            R[regDest] = R[regFont] / R[regTemp];
            //Exibe o valor de R[regDest]
            printf("A divisão dos registradores resultou em %d\n\n", R[regDest]);
          break;
          //--------------------------------- AND ---------------------------------------
          //Caso funct possua o valor 0x24
          case 0x24:
            printf("---------AND---------\n");
            printf("\n----Primeiro Valor---\n");
            //R[regFont] recebe o valor retornado da função pegaValor
            R[regFont] = pegaValor();
            printf("\n----Segundo Valor----\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //Operação lógica AND entre R[regFont] e R[regTemp], bit a bit, e salva em R[regDest]
            R[regDest] = R[regFont] & R[regTemp];
            //Exibe o valor de R[regDest]
            printf("A operação lógica AND entre os operadores resultou em %d\n\n", R[regDest]);
          break;
          //--------------------------------- OR ----------------------------------------
          //Caso funct possua o valor 0x25
          case 0x25:
            printf("---------OR----------\n");
            printf("\n----Primeiro Valor---\n");
            //R[regFont] recebe o valor retornado da função pegaValor
            R[regFont] = pegaValor();
            printf("\n----Segundo Valor----\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //Operação lógica OR entre R[regFont] e R[regTemp], bit a bit, e salva em R[regDest]
            R[regDest] = R[regFont] | R[regTemp];
            //Exibe o valor de R[regDest]
            printf("A operação lógica OR entre os operadores resultou em %d\n\n", R[regDest]);
          break;
          //--------------------------------- XOR ---------------------------------------
          //Caso funct possua o valor 0x26
          case 0x26:
            printf("---------XOR---------\n");
            printf("\n----Primeiro Valor---\n");
            //R[regFont] recebe o valor retornado da função pegaValor
            R[regFont] = pegaValor();
            printf("\n----Segundo Valor----\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //Operação lógica XOR entre R[regFont] e R[regTemp], bit a bit, e salva em R[regDest]
            R[regDest] = R[regFont] ^ R[regTemp];
            //Exibe o valor de R[regDest]
            printf("A operação lógica XOR entre os operadores resultou em %d\n\n", R[regDest]);
          break;
          //--------------------------------- NOR ---------------------------------------
          //Caso funct possua o valor 0x27
          case 0x27:
            printf("---------NOR---------\n");
            printf("\n----Primeiro Valor---\n");
            //R[regFont] recebe o valor retornado da função pegaValor
            R[regFont] = pegaValor();
            printf("\n----Segundo Valor----\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //Operação lógica NOR entre R[regFont] e R[regTemp], bit a bit, e salva em R[regDest]
            R[regDest] = ~(R[regFont] | R[regTemp]);
            //Exibe o valor de R[regDest]
            printf("A operação lógica NOR entre os operadores resultou em %d\n\n", R[regDest]);
          break;
          //--------------------------------- SLT ---------------------------------------
          //Caso funct possua o valor 0x2a
          case 0x2a:
            printf("---------SLT---------\n");
            printf("\n----Primeiro Valor---\n");
            //R[regFont] recebe o valor retornado da função pegaValor
            R[regFont] = pegaValor();
            printf("\n----Segundo Valor----\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //As variáveis auxiliares recebem os valores contidos nos registradores
            auxTemp = R[regTemp];
            auxFont = R[regFont];
            //Se auxFont for menor que auxTemp
            if (auxFont < auxTemp) {
              //R[regDest] recebe 1
              R[regDest] = 1;
            //Se não
            }else{
              //R[regDest] recebe 0
              R[regDest] = 0;
            }//if
            //Exibe o valor de R[regDest]
            printf("O desvio condicional SLT entre os operadores resultou em %d\n\n", R[regDest]);
          break;
          //--------------------------------- SLL ---------------------------------------
          //Caso funct possua o valor 0x00
          case 0x00:
            printf("\n---------SLL---------\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //R[regDest] recebe o valor de R[regTemp] deslocado tantos shamt à esquerda
            R[regDest] = R[regTemp] << shamt;
            //Exibe o valor de R[regDest]
            printf("A operação lógica SLL do registrador temporário resultou em %d\n\n", R[regDest]);
          break;
          //--------------------------------- SRL ---------------------------------------
          //Caso funct possua o valor 0x02
          case 0x02:
            printf("\n---------SRL---------\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //R[regDest] recebe o valor de R[regTemp] deslocado tantos shamt à direita
            R[regDest] = R[regTemp] >> shamt;
            //Exibe o valor de R[regDest]
            printf("A operação lógica SRL do registrador temporário resultou em %d\n\n", R[regDest]);
          break;
          //--------------------------------- SRA ---------------------------------------
          //Caso funct possua o valor 0x03
          case 0x03:
            printf("\n---------SRA---------\n");
            //R[regTemp] recebe o valor retornado da função pegaValor
            R[regTemp] = pegaValor();
            //A variável auxiliar recebe o valor de R[regTemp]
            auxTemp = R[regTemp];
            //Verifica se R[regDest] é menor que 0, caso verdadeiro recebe o valor da primeira condção
            //caso falso recebe o valor da segunda condição (após os ":")
            R[regDest] = auxTemp < 0 ? ~(~(auxTemp) >> shamt) : auxTemp >> shamt;
            //Exibe o valor de R[regDest]
            printf("A operação aritmética SRA do registrador temporário resultou em %d\n\n", R[regDest]);
          break;
	}//switch
      break;
      //--------------------------------- ADDI --------------------------------------
      //Caso opcode possua o valor 0x08
      case 0x08:
        //Exibe as informações da cada variável
        printf("\n opcode %01x | regFont %01x | regTemp %01x | immediate %01x\n",
        opcode, regFont, regTemp, immediate);
        printf("\n---------ADDI--------\n");
        //R[regFont] recebe o valor retornado da função pegaValor
        R[regFont] = pegaValor();
        //Soma o valor de R[regFont] e immediate e salva em R[regTemp]
        R[regTemp] = R[regFont] + immediate;
        //Exibe o valor de R[regTemp]
        printf("A soma do registrador com o imediato resultou em %d\n", R[regTemp]);
      break;
      //--------------------------------- ANDI --------------------------------------
      //Caso opcode possua o valor 0x0c
      case 0x0c:
        //Exibe as informações da cada variável
        printf("\n opcode %01x | regFont %01x | regTemp %01x | immediate %01x\n",
        opcode, regFont, regTemp, immediate);
        printf("\n---------ANDI--------\n");
        //R[regFont] recebe o valor retornado da função pegaValor
        R[regFont] = pegaValor();
        //Operação lógica AND entre R[regFont] e immediate, bit a bit, e salva em R[regTemp]
        R[regTemp] = R[regFont] & immediate;
        //Exibe o valor de R[regTemp]
        printf("A operação lógica ANDI entre o operador e o imediato resultou em %d\n", R[regTemp]);
      break;
      //--------------------------------- ORI ---------------------------------------
      //Caso opcode possua o valor 0x0d
      case 0x0d:
        //Exibe as informações da cada variável
        printf("\n opcode %01x | regFont %01x | regTemp %01x | immediate %01x\n",
        opcode, regFont, regTemp, immediate);
        printf("\n---------ORI---------\n");
        //R[regFont] recebe o valor retornado da função pegaValor
        R[regFont] = pegaValor();
        //Operação lógica OR entre R[regFont] e immediate, bit a bit, e salva em R[regTemp]
        R[regTemp] = R[regFont] | immediate;
        //Exibe o valor de R[regTemp]
        printf("A operação lógica ORI entre o operador e o imediato resultou em %d\n", R[regTemp]);
      break;
      //--------------------------------- XORI --------------------------------------
      //Caso opcode possua o valor 0x0e
      case 0x0e:
        //Exibe as informações da cada variável
        printf("\n opcode %01x | regFont %01x | regTemp %01x | immediate %01x\n",
        opcode, regFont, regTemp, immediate);
        printf("\n---------XORI--------\n");
        //R[regFont] recebe o valor retornado da função pegaValor
        R[regFont] = pegaValor();
        //Operação lógica XOR entre R[regFont] e immediate, bit a bit, e salva em R[regTemp]
        R[regTemp] = R[regFont] ^ immediate;
        //Exibe o valor de R[regTemp]
        printf("A operação lógica XORI entre o operador e o imediato resultou em %d\n", R[regTemp]);
      break;
    }//switch
  }//for
//Retorna 0 como valor da função
return 0;
}
