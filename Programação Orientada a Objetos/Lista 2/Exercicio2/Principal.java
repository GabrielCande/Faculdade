/*
Exercício 2
Autores: Camila Costa Durante e Gabriel Candelária Wiltgen Barbosa
Data: 15/10/2021
*/
package exercicio2;

import java.util.ArrayList;

public class Principal {

    public abstract class MembroUniversidade{
        public float pagamento(){
            return 200.0f;
        }
        public abstract void universidade();
        public abstract void setor();
        public abstract void nome();
        public abstract void CPF();
        public abstract void cargaHoraria();
    }
    
    public final class Administrativo extends MembroUniversidade{
        public void universidade(){
            System.out.println("UTFPR");
        }
        public void setor(){
            System.out.println(this.getClass().getSimpleName());
        }
        public void nome(){
            System.out.println("Márcia do Carmo");
        }
        public void CPF(){
            System.out.println("123.456.789-10");
        }
        public void cargaHoraria(){
            System.out.println("16 horas");
        }
    }
    
    public final class Professor extends MembroUniversidade{
        public void universidade(){
            System.out.println("UTFPR");
        }
        public void setor(){
            System.out.println(this.getClass().getSimpleName());
        }
        public void nome(){
            System.out.println("Sérgio Luis Pereira");
        }
        public void CPF(){
            System.out.println("134.876.259-80");
        }
        public void cargaHoraria(){
            System.out.println("8 horas");
        }
    }
    
    public final class Tecnico extends MembroUniversidade{
        public void universidade(){
            System.out.println("UTFPR");
        }
        public void setor(){
            System.out.println(this.getClass().getSimpleName());
        }
        public void nome(){
            System.out.println("Felipe Santos");
        }
        public void CPF(){
            System.out.println("987.654.321-97");
        }
        public void cargaHoraria(){
            System.out.println("12 horas");
        }
    }
    
    public final class Bolsista extends MembroUniversidade{
        public void universidade(){
            System.out.println("UTFPR");
        }
        public void setor(){
            System.out.println(this.getClass().getSimpleName());
        }
        public void nome(){
            System.out.println("Maria Antônia Lopes");
        }
        public void CPF(){
            System.out.println("456.297.138-21");
        }
        public void cargaHoraria(){
            System.out.println("6 horas");
        }
    }
    
    public Principal(){
        ArrayList <MembroUniversidade> lista = new ArrayList <> ();
        MembroUniversidade membroUni;
        membroUni = new Administrativo();
        lista.add(membroUni);
        membroUni = new Professor();
        lista.add(membroUni);
        membroUni = new Tecnico();
        lista.add(membroUni);
        membroUni = new Bolsista();
        lista.add(membroUni);
        
        for( MembroUniversidade membro: lista){
            System.out.print("Universidade: ");
            membro.universidade();
            System.out.print("Setor: ");
            membro.setor();
            System.out.print("Nome: ");
            membro.nome();
            System.out.print("CPF: ");
            membro.CPF();
            System.out.print("Carga Horária: ");
            membro.cargaHoraria();
            System.out.println("Salário: " + membro.pagamento());
            System.out.print("\n");
        }
    }
    
    public static void main(String[] args) {
       new Principal();
    }
    
}
