package exercicio5;

import java.util.Random;
import java.lang.Math;
import java.util.Scanner;
        
public class Descobrir {
    public static int Aleatorio(){
        Random aleatorio = new Random();
        return aleatorio.nextInt(10);
    }
    public static void Verifica(int n, int aleatorio){
        Scanner entrada = new Scanner(System.in);
        while(n != aleatorio){
            int aux = Math.min(n, aleatorio);
            if(aux == n){
                System.out.println("O valor digitado foi menor que o aleatorio!");
            }else{
                System.out.println("O valor digitado foi maior que o aleatorio!");
            }
            System.out.println("Digite um valor novamente: ");
            n = entrada.nextInt();
        }
        System.out.println("Parebens! O valor digitado foi igual ao aleatorio.");
    }
}
