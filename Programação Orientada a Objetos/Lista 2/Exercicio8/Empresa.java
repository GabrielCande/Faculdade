/*
Exercício 8
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 16/10/2021
*/
package exercicio8;

public abstract class Empresa {
    private String nome;
    public abstract void setCaixa(float valor);
    public abstract String imprimir();
    
    public Empresa(){
        this.nome = "Bela Flor";
    }
    
    public String getNome(){
        return this.nome;
    }
}
