package exercicio8;
/*
Classe voltada a calcular o tempo total de execucao do pendulo, utilizando um tamanho hipotetico de corda
para calcular o tempo de uma oscilacao e em seguida multiplicando esse tempo pelo numero de oscilacoes.
*/
import java.lang.Math;

public class Periodo {
    public int horas, minutos, restoSegundos;
    public float Tempo(int oscilacoes, float L){
        float tempo = (float) ((2*3.14)*(Math.sqrt(L/9.8)));
        return (tempo * oscilacoes);
    }
    public void DefTemp(float segundos){
        this.horas = (int) Math.floor(segundos) / 3600;
        int aux = (int) Math.floor(segundos) % 3600;
        this.minutos = aux / 60;
        this.restoSegundos = aux % 60;
    }
}
