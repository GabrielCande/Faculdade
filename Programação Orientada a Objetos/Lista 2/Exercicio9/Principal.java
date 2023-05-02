/*
Exercício 9
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 16/10/2021
*/
package exercicio9;

public class Principal {

    public interface ILoja{
        public abstract String getInfo();
        public abstract void funcionarios(int qtdFuncionarios);
    }
    public abstract class Floricultura{
        private String nome;
        public abstract void setCaixa(float valor);
        public abstract String imprimir();
    
        public Floricultura(){
            this.nome = "Bela Flor";
        }
    
        public String getNome(){
            return this.nome;
        }
    }
    
    public Principal(){
        ILoja loja = new ILoja(){
            private int qtdFuncionarios;
    
            public String getInfo(){
                return "CNPF da Loja: 12.345.678/0001-93" + "\nQuantidade de Funcionarios: " + this.qtdFuncionarios;
            }
    
            public void funcionarios(int qtdFuncionarios){
                this.qtdFuncionarios += qtdFuncionarios;
            }
        };
        
        Floricultura floricultura = new Floricultura(){
            private float caixa;
    
            public void setCaixa(float valor){
                this.caixa += valor;
            }
            public String imprimir(){
                return "Floricultura: " + getNome() + "\nValor de Caixa: " + this.caixa;
            }
        };
        
        loja.funcionarios(20);
        System.out.println(loja.getInfo());
        System.out.print("\n");
        floricultura.setCaixa(569.8f);
        System.out.println(floricultura.imprimir());
    }
    
    public static void main(String[] args) {
        new Principal();
    } 
}
