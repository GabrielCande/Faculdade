package exercicio3;
/*
By: 
Gabriel Candelária Wiltgen Barbosa
Camila Costa Durante
*/
import java.util.Scanner;
import java.lang.Math;

public class Exercicio3 {
    String custo;
    public Exercicio3(){
        Scanner entrada = new Scanner(System.in);
        System.out.println("Digite o tipo do veiculo utilizado: ");
        String veiculo = entrada.nextLine();
        System.out.println("Digite a placa do veiculo: ");
        String placa = entrada.nextLine();
        System.out.println("""
                           Exemplo: 1530 = 15 horas e 30 minutos        
                           Digite o horario de entrada:""");
        int hrEntrada = entrada.nextInt();
        System.out.println("Digite o horario de saida:");
        int hrSaida = entrada.nextInt();
        int horasEnt = hrEntrada/100;
        int horasSai = hrSaida/100;
        int minutosEnt = hrEntrada - (horasEnt * 100);
        int minutosSai = hrSaida - (horasSai * 100);
        hrEntrada = (horasEnt * 60) + minutosEnt;
        hrSaida = (horasSai * 60) + minutosSai;
        int valor = Math.abs(hrEntrada - hrSaida);
        if(valor <= 30){
            custo = "Gratuito";
        }
        else if(valor > 30 && valor <= 60){
            custo = "RS 10,00";
        }else{
            custo = "RS 20,00";
        }
        System.out.println("O valor do estacionamento: " + custo);
    } 
    public static void main(String[] args) {
        new Exercicio3();
    }   
}
