package exercicio9;
/*
By: 
Gabriel Candelária Wiltgen Barbosa
Camila Costa Durante
*/
public class Principal {
    
    public Principal(){
        
        Computador c = new Computador();
        c.setNome("comp1").setMarca("Intel").setData(1,1,2001);
        
       System.out.println(c);
    }
    
    public static void main(String[] args) {
       new Principal();
    }
    
}
