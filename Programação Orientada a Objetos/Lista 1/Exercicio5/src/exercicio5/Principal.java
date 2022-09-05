package exercicio5;
/*
By: 
Gabriel Candelária Wiltgen Barbosa
Camila Costa Durante
*/
import java.util.Scanner;

public class Principal {
    public Principal(){
        Scanner entrada = new Scanner(System.in);
        int valor = 0, aleatorio = 0;
        System.out.println("""
                           Tente acertar o numero aleatorio!
                           Digite um numero de 0 a 10:""");
        valor = entrada.nextInt();
        aleatorio = Descobrir.Aleatorio();
        Descobrir.Verifica(valor, aleatorio);
    }
    public static void main(String[] args) {
        new Principal();
    }
    
}
