package exercicio6;
/*
By: 
Gabriel Candelária Wiltgen Barbosa
Camila Costa Durante
*/
import java.util.Scanner;

public class Principal {
    public Principal(){
        Scanner entrada = new Scanner(System.in);
        Altera altera = new Altera();
        int valor = 0, aleatorio = 0;
        System.out.println("Digite o valor maximo do numero aleatorio: ");
        altera.setAltera(entrada.nextInt());
        System.out.println("""
                           Tente acertar o numero aleatorio!
                           Digite um numero de 0 a""" + " " + altera.getAltera() + ": ");
        valor = entrada.nextInt();
        aleatorio = Descobrir.Aleatorio(altera);
        Descobrir.Verifica(valor, aleatorio);
    }
    public static void main(String[] args) {
        new Principal();
    }
    
}
