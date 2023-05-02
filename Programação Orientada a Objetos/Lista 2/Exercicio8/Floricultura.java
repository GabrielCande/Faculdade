/*
Exercício 8
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 16/10/2021
*/
package exercicio8;

public class Floricultura extends Empresa{
    private float caixa;
    
    public void setCaixa(float valor){
        this.caixa += valor;
    }
    public String imprimir(){
        return "Floricultura: " + getNome() + "\nValor de Caixa: " + this.caixa;
    }
}
