/*
Exercício 8
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 16/10/2021
*/
package exercicio8;

public class Loja implements IComercio{
    private int qtdFuncionarios;
    
    public String getInfo(){
        return "CNPF da Loja: 12.345.678/0001-93" + "\nQuantidade de Funcionarios: " + this.qtdFuncionarios;
    }
    
    public void funcionarios(int qtdFuncionarios){
        this.qtdFuncionarios += qtdFuncionarios;
    }
}
