package exercicio8;
/*
By: 
Gabriel Candelária Wiltgen Barbosa
Camila Costa Durante
*/
import java.util.Scanner;

public class Principal {
    public Principal(){
        Scanner entrada = new Scanner(System.in);
        Pendulo pendulo = new Pendulo();
        Periodo periodo = new Periodo();
        int oscilacoes = 0;
        float L = 0;
        pendulo.setPendulo(0, 0, 0);
        System.out.println("Defina o tamanho da corda utilizado no pendulo em metros:");
        L = entrada.nextFloat();
        do{
            pendulo.Pendulo(pendulo.a, pendulo.b, pendulo.c);
            System.out.println("|A:[" + pendulo.a + ",30]\t|B:[" + 
                    pendulo.b + ",30]\t|C:[" + 
                    pendulo.c + ",30]\t|");
            oscilacoes++;
        }while(pendulo.a < 30);
        periodo.DefTemp(periodo.Tempo(oscilacoes, L));
        System.out.println("O tempo total de execucao do pendulo foi de" + " " + periodo.horas + " horas " +
                periodo.minutos + " minutos e " + periodo.restoSegundos + " segundos ");
    }
    public static void main(String[] args) {
        new Principal();
    }
}
