/*
Exercício 3
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 15/10/2021
*/
package exercicio3;

import java.util.ArrayList;

public class Principal {

    public interface IConversorMoeda{
        public abstract int getConversaoDolar();
    }
    public class BitCoin implements IConversorMoeda{
        private int valor_bit;
        
        public BitCoin(int valor){
            this.valor_bit = valor;
        }
        public void setValorBitCoin(int valor){
            this.valor_bit = valor;
        }
        public int getValorBitCoin(){
            return this.valor_bit;
        }
        public int getConversaoDolar(){
            return (int)(valor_bit/0.000052);
        }
        public String toString(){
            return "O valor de " + getValorBitCoin() + " bitcoins convertido para dolar: ";
        }
    }
    public class Euro implements IConversorMoeda{
        private int valor_euro;
        
        public Euro(int valor){
            this.valor_euro = valor;
        }
        public void setValorEuro(int valor){
            this.valor_euro = valor;
        }
        public int getValorEuro(){
            return this.valor_euro;
        }
        public int getConversaoDolar(){
            return (int)(valor_euro/1.03);
        }
        public String toString(){
            return "O valor de " + getValorEuro() + " euros convertido para dolar: ";
        }
    }
    public class Real implements IConversorMoeda{
        private int valor_real;
        
        public Real(int valor){
            this.valor_real = valor;
        }
        public void setValorReal(int valor){
            this.valor_real = valor;
        }
        public int getValorReal(){
            return this.valor_real;
        }
        public int getConversaoDolar(){
            return (int)(valor_real/5.33);
        }
        public String toString(){
            return "O valor de " + getValorReal() + " reais convertido para dolar: ";
        }
    }
    
    public Principal(){
        ArrayList <IConversorMoeda> lista = new ArrayList <>();
        IConversorMoeda conversao = new BitCoin(2);
        lista.add(conversao);
        conversao = new Euro(100);
        lista.add(conversao);
        conversao = new Real(250);
        lista.add(conversao);
        
        for (IConversorMoeda converte: lista){
            System.out.print(converte);
            System.out.print(converte.getConversaoDolar());
            System.out.println(" USD");
            System.out.print("\n");
        }
    }
    
    public static void main(String[] args) {
        new Principal();
    } 
}
