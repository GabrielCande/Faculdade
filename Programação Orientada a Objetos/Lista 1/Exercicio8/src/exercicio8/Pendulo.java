package exercicio8;

public class Pendulo {
    public int a, b, c;
    public void Pendulo(int a, int b, int c){
        this.c++;
        if(c == 30){
            this.c = 0;
            this.b++;
        }
        if(b == 30){
            this.c = 0;
            this.b = 0;
            this.a++;      
        }
    }
    public void setPendulo(int a, int b, int c){
        this.a = a;
        this.b = b;
        this.c = c;
    }
}
