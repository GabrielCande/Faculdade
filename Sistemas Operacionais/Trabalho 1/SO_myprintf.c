#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
/*
By:
Gabriel Candelária Wiltgen Barbosa, 2271958
Camila Costa Durante, 2270196
*/
void imprima(char* str, ...){
  va_list arg;
  va_start(arg, str);
  unsigned int aux;
  char *str_r;
  double aux_float;
  char temp[100];
  char temp1[100];
  for(int i = 0; i < strlen(str); i++){
    if(str[i] == '%'){
      if(str[i+1] == 'i'){
        aux = va_arg(arg,int);
        sprintf(temp, "%i", aux);
        write(1, temp, strlen(temp));
        i++;
      }//if
      if(str[i+1] == 'd'){
        aux = va_arg(arg,int);
        sprintf(temp, "%d", aux);
        write(1, temp, strlen(temp));
        i++;
      }//if
      if(str[i+1] == '.'){
        char a = str[i];
        char b = str[i+1];
        char c = str[i+2];
        sprintf(temp1 , "%c%c%clf", a,b,c);
        aux_float = va_arg(arg,double);
        sprintf(temp, temp1, aux_float);
        write(1, temp, strlen(temp));
        i = i+3;
      }//if
      if(str[i+1] == 'f'){
        aux_float = va_arg(arg,double);
        sprintf(temp, "%lf", aux_float);
        write(1, temp, strlen(temp));
        i++;
      }//if
      if(str[i+1] == 'c'){
        str_r = va_arg(arg,char *);
        write(1, str_r , sizeof(char));
        i++;
      }//if
      if(str[i+1] == 's'){
        str_r = va_arg(arg,char *);
        write(1, str_r , (char) strlen(str_r));
        i++;
      }//if
    }else{
        write(1, &str[i], sizeof(char));
    }//else
  }//for
}//imprima

int main() {
  imprima("//--------------------------------------------------------------------------------------\n");
  imprima("//------------------------------------String--------------------------------------------\n");
  char* str = "Sistemas Operacionais";
  char* str1 = "Bom dia!";
  imprima("\n");
  imprima("%s\nAula de: %s\n", str1, str);
  imprima("\n");

  imprima("//--------------------------------------------------------------------------------------\n");
  imprima("//-------------------------------------Char---------------------------------------------\n");
  char* chara = "A";
  char* charb = "B";
  char* charc = "C";
  char* chard = "d";
  char* chare = "e";
  imprima("\n");
  imprima("Teste %c\n", chara);
  imprima("(%c,%c),(%c,%c)\n", charb, charc, chard, chare);
  imprima("\n");

  imprima("//--------------------------------------------------------------------------------------\n");
  imprima("//------------------------------------Float---------------------------------------------\n");
  float float1 = 8.5;
  float float2 = 52.4356;
  float float3 = 1.62;
  imprima("\n");
  imprima("Nota: %.1f\n", float1);
  imprima("Velocidade de %f m/s\n", float2);
  imprima("Altura de %.2f m\n", float3, float2);
  imprima("Exemplo: %.2f + %.2f = %.2f\n", float1, float2, (float1 + float2));
  imprima("\n");

  imprima("//--------------------------------------------------------------------------------------\n");
  imprima("//-------------------------------------Int----------------------------------------------\n");
  int num = 01750;//1000
  int num2 = 0x3e8;//1000
  imprima("\n");
  imprima("Na base octal 01750 é igual a %i\n", num);
  imprima("Na base hexadecimal 0x3e8 é igual a %i\n", num2);
  imprima("\n");

  imprima("//--------------------------------------------------------------------------------------\n");
  imprima("//-----------------------------------Decimal--------------------------------------------\n");
  int n = -10;
  int m = 100;
  imprima("\n");
  imprima("%d + %d = %d\n", n , m, (n+m));
  imprima("%d x %d = %d\n", n , m, (n*m));
  imprima("\n");

  imprima("//--------------------------------------------------------------------------------------\n");
  imprima("//----------------------------------Aninhados-------------------------------------------\n");
  char * frase1 = "Uma letra por";
  char * frase = "Valendo...";
  char * letra = "A";
  char * ponto = "!";
  float flutuante = 100.0;
  int dia = 8;
  int mes = 9;
  imprima("\n");
  imprima("Dia: %i/%i\n-%s %.2f reais\n-%s\n-%c de Abelha\n-Certa resposta%c\n", dia, mes, frase1, flutuante, frase, letra, ponto);
  imprima("\n");
  return 0;
}//main
