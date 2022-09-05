package exercicio2;

public class Valor {
    /*
    Classe utilizada para armazenar os valores que serao obtidos atraves 
    do scanner na classe principal.
    */
    public float valor;
    public double valor1;
    public Valor(float valor){
        this.valor = valor;
    }
    public Valor(double valor1){
        this.valor1 = valor1;
    }
    public float getValor(){
        return this.valor;
    }
    public void setValor(float valor){
        this.valor = valor;
    }
    public double getValor1(){
        return this.valor1;
    }
    public void setValor1(double valor1){
        this.valor1 = valor1;
    }
}

