package exercicio4;
/*
By: 
Gabriel Candelária Wiltgen Barbosa
Camila Costa Durante
*/
import java.util.Scanner;

public class Principal {
    String custo;
    public Principal(){
        Scanner entrada = new Scanner(System.in);
        System.out.println("Digite o tipo do veiculo utilizado: ");
        String tipoVeiculo = entrada.nextLine();
        System.out.println("Digite a placa do veiculo: ");
        String placa = entrada.nextLine();
        System.out.println("""
                           Exemplo: 1530 = 15 horas e 30 minutos        
                           Digite o horario de entrada:""");
        int hrEntrada = entrada.nextInt();
        System.out.println("Digite o horario de saida:");
        int hrSaida = entrada.nextInt();
        Veiculo veiculo = new Veiculo(tipoVeiculo, placa, hrEntrada, hrSaida);
        int auxE = veiculo.getHrEntrada();
        int auxS = veiculo.getHrSaida();
        int horasEnt = veiculo.getHrEntrada()/100;
        int horasSai = veiculo.getHrSaida()/100;
        int minutosEnt = veiculo.getHrEntrada() - (horasEnt * 100);
        int minutosSai = veiculo.getHrSaida() - (horasSai * 100);
        veiculo.setHrEntrada((horasEnt * 60) + minutosEnt);
        veiculo.setHrSaida((horasSai * 60) + minutosSai); 
        int valor = Math.abs(veiculo.getHrEntrada() - veiculo.getHrSaida());
        veiculo.setHrEntrada(auxE);
        veiculo.setHrSaida(auxS);
        if(valor <= 30){
            custo = "Gratuito";
        }
        else if(valor > 30 && valor <= 60){
            custo = "RS 10,00";
        }else{
            custo = "RS 20,00";
        }
        System.out.println(veiculo);
        System.out.println("O valor do estacionamento: " + custo);
    }
    public static void main(String[] args) {
        new Principal();
    }
    
}
