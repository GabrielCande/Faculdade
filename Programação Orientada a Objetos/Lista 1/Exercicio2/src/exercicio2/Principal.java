package exercicio2;
/*
By: 
Gabriel Candelária Wiltgen Barbosa
Camila Costa Durante
*/
import java.util.Scanner;
import java.lang.Math;

public class Principal {
    public Principal(){
        Scanner entrada = new Scanner(System.in);
        
        System.out.println("""
                           -------------------------
                               Menu de escolha:
                                1  --->  Abs
                                2  --->  Ceil
                                3  --->  Cos
                                4  --->  Exp
                                5  --->  Floor
                                6  --->  Log
                                7  --->  Max
                                8  --->  Min
                                9  --->  Pow
                                10 --->  Sqrt
                           -------------------------
                           """);
        System.out.println("Digite o Valor da Funcao desejada: ");
        float opcao = entrada.nextFloat();
        if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 ||
            opcao == 5 || opcao == 6 || opcao == 7 || opcao == 8 || opcao == 10){
            System.out.println("Digite um Valor: ");
            Valor valor = new Valor(entrada.nextFloat());
            if(opcao == 1){
                System.out.println("Abs = " + Math.abs(valor.getValor()));
            }
            if(opcao == 2){
                System.out.println("Ceil = " + Math.ceil(valor.getValor()));
            }
            if(opcao == 3){
                System.out.println("Cos = " + Math.cos(valor.getValor()));
            }
            if(opcao == 4){
                System.out.println("Exp = " + Math.abs(valor.getValor()));
            }
            if(opcao == 5){
               System.out.println("Floor = " + Math.floor(valor.getValor()));
            }
            if(opcao == 6){
                System.out.println("Log = " + Math.log(valor.getValor()));
            }
            if(opcao == 7){
                System.out.println("Digite um Segundo Valor: ");
                Valor valor2 = new Valor(entrada.nextFloat());
                System.out.println("Max = " + Math.max(valor.getValor(), valor2.getValor()));
            }
            if(opcao == 8){
                System.out.println("Digite um Segundo Valor: ");
                Valor valor2 = new Valor(entrada.nextFloat());
                System.out.println("Max = " + Math.max(valor.getValor(), valor2.getValor()));
            }
            if(opcao == 10){
                System.out.println("Sqrt = " + Math.sqrt(valor.getValor()));
            }
        }
        if(opcao == 9){
            System.out.println("Digite o Valor da base: ");
            Valor base = new Valor(entrada.nextDouble());
            System.out.println("Digite o Valor do expoente: ");
            Valor expoente = new Valor(entrada.nextDouble());
            System.out.println("Pow = " + Math.pow(base.getValor1(), expoente.getValor1()));
        }
        
    }
    public static void main(String[] args) {
        new Principal();
    }  
}

