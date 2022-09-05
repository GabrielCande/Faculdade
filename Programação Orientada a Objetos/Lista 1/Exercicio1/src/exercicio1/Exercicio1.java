package exercicio1;
/*
By: 
Gabriel Candelária Wiltgen Barbosa
Camila Costa Durante
*/
import java.util.Scanner;
import java.lang.Math;

public class Exercicio1 {
    public Exercicio1(){
        
        Scanner entrada = new Scanner(System.in);
        
        System.out.println("Menu de escolha:" + 
                "\n" + "1  --->  Abs" + 
                "\n" + "2  --->  Ceil" +
                "\n" + "3  --->  Cos" +
                "\n" + "4  --->  Exp" +
                "\n" + "5  --->  Floor" +
                "\n" + "6  --->  Log" +
                "\n" + "7  --->  Max" +
                "\n" + "8  --->  Min" +
                "\n" + "9  --->  Pow" +
                "\n" + "10 --->  Sqrt");
        System.out.println("Digite o Valor da Funcao desejada: ");
        float opcao = entrada.nextFloat();
        float valor = 0;
        if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 ||
                opcao == 5 || opcao == 6 || opcao == 7 || opcao == 8 || opcao == 10){
            System.out.println("Digite um Valor: ");
            valor = entrada.nextFloat();
        }
        if(opcao == 1){
            System.out.println("Abs = " + Math.abs(valor));
        }
        if(opcao == 2){
            System.out.println("Ceil = " + Math.ceil(valor));
        }
        if(opcao == 3){
            System.out.println("Cos = " + Math.cos(valor));
        }
        if(opcao == 4){
            System.out.println("Exp = " + Math.abs(valor));
        }
        if(opcao == 5){
           System.out.println("Floor = " + Math.floor(valor));
        }
        if(opcao == 6){
            System.out.println("Log = " + Math.log(valor));
        }
        if(opcao == 7){
            System.out.println("Digite um Segundo Valor: ");
            float valor2 = entrada.nextFloat();
            System.out.println("Max = " + Math.max(valor, valor2));
        }
        if(opcao == 8){
            System.out.println("Digite um Segundo Valor: ");
            float valor2 = entrada.nextFloat();
            System.out.println("Min = " + Math.min(valor, valor2));
        }
        if(opcao == 9){
            System.out.println("Digite o Valor da base: ");
            double base = entrada.nextDouble();
            System.out.println("Digite o Valor do expoente: ");
            double expoente = entrada.nextDouble();
            System.out.println("Pow = " + Math.pow(base, expoente));
        }
        if(opcao == 10){
            System.out.println("Sqrt = " + Math.sqrt(valor));
        }
    }
    public static void main(String[] args) {
        new Exercicio1();
    }  
}
