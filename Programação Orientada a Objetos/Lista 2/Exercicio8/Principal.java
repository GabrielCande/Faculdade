/*
Exercício 8
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 16/10/2021
*/
package exercicio8;

public class Principal {
    public Principal(){
        IComercio loja = new Loja();
        Empresa floricultura = new Floricultura();
        
        loja.funcionarios(10);
        System.out.println(loja.getInfo());
        System.out.print("\n");
        floricultura.setCaixa(230.0f);
        System.out.println(floricultura.imprimir());
    }
    public static void main(String[] args) {
        new Principal();
    }
}
