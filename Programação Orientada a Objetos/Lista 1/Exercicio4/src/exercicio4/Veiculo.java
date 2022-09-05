package exercicio4;
/*
Classe voltada a salvar as informações do veiculo estacionado para reexibi-las antes
de apresentar o custo do estacionamento.
*/
public class Veiculo {
    public String tipoVeiculo;
    public String placa;
    public int hrEntrada;
    public int hrSaida;
    
    public Veiculo(String tipoVeiculo, String placa, int hrEntrada, int hrSaida){
        this.tipoVeiculo = tipoVeiculo;
        this.placa = placa;
        this.hrEntrada = hrEntrada;
        this.hrSaida = hrSaida;
    }
    public int getHrEntrada(){
        return this.hrEntrada;
    }
    public void setHrEntrada(int hrEntrada){
        this.hrEntrada = hrEntrada;
    }
    public int getHrSaida(){
        return this.hrSaida;
    }
    public void setHrSaida(int hrSaida){
        this.hrSaida = hrSaida;
    }
    public String toString(){
        return """
               
               ----------------------------------
               Informacoes do Veiculo:
               """ + "Tipo: " +
               this.tipoVeiculo + "\n" + "Placa: " +
               this.placa + "\n" + "Horario de Entrada: " +
               this.hrEntrada + "\n" + "Horario de Saida: " +
               this.hrSaida + 
               """
               
               ----------------------------------""";
    }
}
