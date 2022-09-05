package exercicio9;

public class Computador extends Data{
    
    public String nome;
    public String marca;
    
    public Computador(){
    }    
    
    public Computador setNome(String nome){
        this.nome = nome;
        return this;
    }
    
    public Computador setMarca(String marca){
        this.marca = marca;
        return this;
    }
    
    public String toString(){
        return "Nome:\t" + this.nome + "\nMarca:\t" + this.marca + "\nData:\t" + this.dia + "/" + this.mes + "/" + this.ano;
    }
    
}
