/*
Exercício 1
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 15/10/2021
*/
package exercicio1;

import java.util.ArrayList;

public class Principal {

    public class Animal{
        public String nome;
        public Animal(String nome){
            this.nome = nome;
        }
        public void caminhar(){
            System.out.println("Caminha");
        }
        public void quantidadePatas(){
            System.out.println("0");
        }
        public void peso(){
            System.out.println("0 kg");
        }
        public void alimentacao(){
            System.out.println("Comida");
        }
        public void expectativaVida(){
            System.out.println("0 anos");
        }
    }//class Animal
    
    public class Anfibio extends Animal{
        protected String quantidadeEscamas;
        public Anfibio(String nome){
            super(nome);
            this.quantidadeEscamas = "pouco";
        }
        public String toString(){
            return "Animal: " + this.nome + "\nQuantidade de Escamas: " + this.quantidadeEscamas;
        }
    }//class Anfibio
    
    public class Terrestre extends Animal{
        protected String quantidadePelos;
        public Terrestre(String nome){
            super(nome);
            this.quantidadePelos = "pouco";
        }
        public String toString(){
            return "Animal: " + this.nome + "\nQuantidade de Pelos: " + this.quantidadePelos;
        }
    }//class Terrestre
    
    public final class Sapo extends Anfibio{
        public Sapo(String nome){
            super(nome);
        }
        public void caminhar(){
            System.out.println("Salta");
        }
        public void quantidadePatas(){
            System.out.println("4");
        }
        public void peso(){
            System.out.println("4 kg");
        }
        public void alimentacao(){
            System.out.println("Insetos");
        }
        public void expectativaVida(){
            System.out.println("15 anos");
        }
    }//final class Sapo
    
    public final class Ra extends Anfibio{
        public Ra(String nome){
            super(nome);
        }
        public void caminhar(){
            System.out.println("Salta");
        }
        public void quantidadePatas(){
            System.out.println("4");
        }
        public void peso(){
            System.out.println("2 kg");
        }
        public void alimentacao(){
            System.out.println("Insetos");
        }
        public void expectativaVida(){
            System.out.println("20 anos");
        }
    }//final class Ra
    
    public final class Leao extends Terrestre{
        public Leao(String nome){
            super(nome);
        }
        public void caminhar(){
            System.out.println("Anda");
        }
        public void quantidadePatas(){
            System.out.println("4");
        }
        public void peso(){
            System.out.println("190 kg");
        }
        public void alimentacao(){
            System.out.println("Ungulados");
        }
        public void expectativaVida(){
            System.out.println("16 anos");
        }
    }//final class Leao
    
    public final class Macaco extends Terrestre{
        public Macaco(String nome){
            super(nome);
        }
        public void caminhar(){
            System.out.println("Anda");
        }
        public void quantidadePatas(){
            System.out.println("4");
        }
        public void peso(){
            System.out.println("10 kg");
        }
        public void alimentacao(){
            System.out.println("Frutas");
        }
        public void expectativaVida(){
            System.out.println("45 anos");
        }
    }//final class Macaco
    
    public Principal(){
        ArrayList <Animal> lista = new ArrayList <>();
        Animal animal = new Sapo("Sapo");
        lista.add(animal);
        animal = new Ra("Rã");
        lista.add(animal);
        animal = new Leao("Leão");
        lista.add(animal);
        animal = new Macaco("Macaco");
        lista.add(animal);
        
        for (Animal a : lista){
            System.out.println(a);
            System.out.print("Modo de Caminhar: ");
            a.caminhar();
            System.out.print("Quantidade de Patas: ");
            a.quantidadePatas();
            System.out.print("Peso Médio: ");
            a.peso();
            System.out.print("Alimentação: ");
            a.alimentacao();
            System.out.print("Máxima Expectativa de Vida: ");
            a.expectativaVida();
            System.out.print("\n");
        }
    }
    public static void main(String[] args) {
        new Principal();
    } 
}
