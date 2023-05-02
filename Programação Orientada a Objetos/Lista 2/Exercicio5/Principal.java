/*
Exercício 5
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 16/10/2021
*/
package exercicio5;

import java.util.ArrayList;

public class Principal {

    public interface IOperacoes{
        public abstract void setOperando1(float operando1);
        public abstract void setOperando2(float operando2);
        public abstract float getResultado();
        public abstract String getNome();
        public abstract int getQuantidade();
    }
    public class Soma implements IOperacoes{
        private float operando1;
        private float operando2;
        private static int instancias_s;
        
        public Soma(){
            instancias_s++;
        }
        
        public void setOperando1(float operando1){
            this.operando1 = operando1;
        }
        public void setOperando2(float operando2){
            this.operando2 = operando2;
        }
        public float getResultado(){
            return (operando1 + operando2);
        }
        public String getNome(){
            return this.getClass().getSimpleName();
        }
        public int getQuantidade(){
            return this.instancias_s;
        }
    }
    public class Subtracao implements IOperacoes{
        private float operando1;
        private float operando2;
        private static int instancias_sub;
        
        public Subtracao(){
            instancias_sub++;
        }
        
        public void setOperando1(float operando1){
            this.operando1 = operando1;
        }
        public void setOperando2(float operando2){
            this.operando2 = operando2;
        }
        public float getResultado(){
            return (operando1 - operando2);
        }
        public String getNome(){
            return this.getClass().getSimpleName();
        }
        public int getQuantidade(){
            return this.instancias_sub;
        }
    }
    public class Divisao implements IOperacoes{
        private float operando1;
        private float operando2;
        private static int instancias_d;
        
        public Divisao(){
            instancias_d++;
        }
        
        public void setOperando1(float operando1){
            this.operando1 = operando1;
        }
        public void setOperando2(float operando2){
            this.operando2 = operando2;
        }
        public float getResultado(){
            return (operando1 / operando2);
        }
        public String getNome(){
            return this.getClass().getSimpleName();
        }
        public int getQuantidade(){
            return this.instancias_d;
        }
    }
    public class Multiplicacao implements IOperacoes{
        private float operando1;
        private float operando2;
        private static int instancias_m;
        
        public Multiplicacao(){
            this.instancias_m++;
        }
        
        public void setOperando1(float operando1){
            this.operando1 = operando1;
        }
        public void setOperando2(float operando2){
            this.operando2 = operando2;
        }
        public float getResultado(){
            return (operando1 * operando2);
        }
        public String getNome(){
            return this.getClass().getSimpleName();
        }
        public int getQuantidade(){
            return this.instancias_m;
        }
    }
    
    public Principal(){
        ArrayList <IOperacoes> lista = new ArrayList <> ();
        IOperacoes operacoes = new Soma();
        operacoes.setOperando1(3.0f);
        operacoes.setOperando2(15.0f);
        lista.add(operacoes);
        
        operacoes = new Subtracao();
        operacoes.setOperando1(81.0f);
        operacoes.setOperando2(9.0f);
        lista.add(operacoes);
        
        operacoes = new Divisao();
        operacoes.setOperando1(45.0f);
        operacoes.setOperando2(5.0f);
        lista.add(operacoes);
        
        operacoes = new Multiplicacao();
        operacoes.setOperando1(23.0f);
        operacoes.setOperando2(12.0f);
        lista.add(operacoes);
        
        operacoes = new Subtracao();
        operacoes.setOperando1(54.5f);
        operacoes.setOperando2(2.75f);
        lista.add(operacoes);
        
        operacoes = new Divisao();
        operacoes.setOperando1(17.2f);
        operacoes.setOperando2(3.3f);
        lista.add(operacoes);
        
        for(IOperacoes op : lista){
            System.out.print("Operacao: ");
            System.out.println(op.getNome());
            System.out.print("Resultado: ");
            System.out.println(op.getResultado());
            System.out.print("Quantidade de Instancias da Classe: ");
            System.out.println(op.getQuantidade());
            System.out.print("\n");
        }
    }
    public static void main(String[] args) {
        new Principal();
    }  
}
