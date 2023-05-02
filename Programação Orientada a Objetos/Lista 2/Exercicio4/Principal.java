/*
Exercício 4
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 15/10/2021
*/
package exercicio4;

import java.util.ArrayList;

public class Principal {
    public float ganhos;
    
    public abstract class Empregado{
        private String nome;
        private String sobrenome;
        private float salarioBase;
        
        public abstract void ganhos();
        public abstract String imprimir();
        
        public Empregado(String nome, String sobrenome, float salarioBase){
            this.nome = nome;
            this.sobrenome = sobrenome;
            this.salarioBase = salarioBase;
        }
        public String getNome(){
            return this.nome;
        }
        public String getSobrenome(){
            return this.sobrenome;
        }
        public float getSalarioBase(){
            return this.salarioBase;
        }
    }
    public abstract class Assalariado extends Empregado{
        private float salarioSemanal;
        
        public Assalariado(String nome, String sobrenome, float salarioBase, float salarioSemanal){
            super(nome, sobrenome, salarioBase);
            this.salarioSemanal = salarioSemanal;
        }
        public float getSalarioSemanal(){
            return this.salarioSemanal;
        }
    }
    public final class Comissionado extends Empregado{
        private float taxaComissao;
        
        public Comissionado(String nome, String sobrenome, float salarioBase, float taxaComissao){
            super(nome, sobrenome, salarioBase);
            this.taxaComissao = taxaComissao;
        }
        public void ganhos(){
            ganhos = getSalarioBase() + this.taxaComissao;
            System.out.println(ganhos);
        }
        public String imprimir(){
            return "Nome: " + getNome() + " " + getSobrenome() + "\nSalario Base: " + getSalarioBase() + "\nTaxa de Comissao: " + this.taxaComissao;
        }
    }
    public final class Horista extends Empregado{
        private int horas;
        
        public Horista(String nome, String sobrenome, float salarioBase, int horas){
            super(nome, sobrenome, salarioBase);
            this.horas = horas;
        }
        public void ganhos(){
            ganhos = getSalarioBase()*this.horas;
            System.out.println(ganhos);
        }
        public String imprimir(){
            return "Nome: " + getNome() + " " + getSobrenome() + "\nSalario Base: " + getSalarioBase() + "\nCarga Horaria: " + this.horas;
        }
    }
    public final class Bonificado extends Assalariado{
        private float bonificacao;
        
        public Bonificado(String nome, String sobrenome, float salarioBase, float bonificacao, float salarioSemanal){
            super(nome, sobrenome, salarioBase, salarioSemanal);
            this.bonificacao = bonificacao;
        }
        public void ganhos(){
            ganhos = getSalarioBase() + (4*getSalarioSemanal()) + this.bonificacao;
            System.out.println(ganhos);
        }
        public String imprimir(){
            return "Nome: " + getNome() + " " + getSobrenome() + "\nSalario Base: " + getSalarioBase() + "\nSalario Semanal: " + getSalarioSemanal() + "\nBonificacao: " + this.bonificacao;
        }
    }
    
    public Principal(){
        Bonificado b1 = new Bonificado("Joao", "Silva", 450.0f, 100.0f, 110.0f);
        Comissionado c1 = new Comissionado("Maria", "Soares", 380.0f, 120.0f);
        Horista h1 = new Horista("Jomar", "Silva Soares", 15.0f, 10);
        
        ArrayList <Empregado> lista = new ArrayList <> ();
        Empregado empregado = b1;
        lista.add(empregado);
        empregado = c1;
        lista.add(empregado);
        empregado = h1;
        lista.add(empregado);
        
        for (Empregado emp : lista){
            System.out.println(emp.imprimir());
            System.out.print("Ganhos: ");
            emp.ganhos();
            System.out.print("\n");
        }
    }
    
    public static void main(String[] args) {
       new Principal(); 
    }  
}
