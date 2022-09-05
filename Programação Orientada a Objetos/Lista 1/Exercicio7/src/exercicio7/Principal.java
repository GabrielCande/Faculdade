package exercicio7;
/*
By: 
Gabriel Candelária Wiltgen Barbosa
Camila Costa Durante
*/
public class Principal {
    public Principal(){
        Pendulo pendulo = new Pendulo();
        pendulo.setPendulo(0, 0, 0);
        do{
            pendulo.Pendulo(pendulo.a, pendulo.b, pendulo.c);
            System.out.println("|A[" + pendulo.a + ",30]\t|B[" + 
                    pendulo.b + ",30]\t|C[" + 
                    pendulo.c + ",30]\t|");
        }while(pendulo.a < 30);
    }
    public static void main(String[] args) {
        new Principal();
    }
}
