/*
Exercício 6
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 17/10/2021
*/
package exercicio6;

public class Principal {
    public class ExceptionA extends Exception{
        public ExceptionA(){
           System.out.println("ExceptionA");
           ExceptionB.opa();
        }
    }
    public class ExceptionB extends ExceptionA{
        public static void opa(){
            System.out.println("ExceptionB");
            ExceptionC.opa2();
        }
    }
    public class ExceptionC extends ExceptionB{
        public static void opa2(){
            System.out.println("ExceptionC"); 
        }
    }
    public Principal(){
        try{
            throw new ExceptionA();
        }catch(ExceptionA e){
            System.exit(0);
        }
    }
    public static void main(String[] args) {
        Principal principal = new Principal();
    }
}
