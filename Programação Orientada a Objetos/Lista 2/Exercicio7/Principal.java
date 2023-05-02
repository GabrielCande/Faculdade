/*
Exercício 7
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 16/10/2021
*/
package exercicio7;

import java.io.IOException;

public class Principal {

    public class ExceptionA extends Exception{
        public ExceptionA(String mensagem){
            super(mensagem);
        }
    }
    
    public class ExceptionB extends ExceptionA{        
        public ExceptionB(String mensagem){
            super(mensagem);
        }
    }
    
    public Principal(){
        int [] operador1 = {50,2,6,23,54,100};
        int [] operador2 = {1,6,3,24,1,10};
        
        for(int i = 0; i < operador1.length; i++){
            try{
                System.out.println(operador1[i] + " - " + operador2[i] + " = " + (operador1[i]-operador2[i]));
                if((operador1[i] - operador2[i]) < 0){
                    throw new ExceptionA("ExceptionA capturada! A subtracao resultou em um numero negativo!\n");
                }
            }catch(ExceptionA e){
                System.out.println(e);
            }
            try{
                System.out.println(operador1[i] + " / " + operador2[i] + " = " + (operador1[i]/operador2[i]));
                if((operador1[i] / operador2[i]) == operador1[i]){
                    throw new ExceptionB("ExceptionB capturada! O resultado da divisao e igual ao numerador!\n");
                }
            }catch(ExceptionB e){
                System.out.println(e);
            }
        }
        
        System.out.println("\n");
        
        try{
            throw new IOException();
        }catch(IOException e){
            System.out.println("IOException capturada!");
        }
        System.out.println("\n");
        try{
            throw new NullPointerException();
        }catch(NullPointerException e){
            System.out.println("NullPointerException capturada!");
        }
    }
    public static void main(String[] args) {
        new Principal();
    } 
}
