import java.util.Scanner;
public class Test {

    public static void main(String[] args) {
    Scanner input =new Scanner(System.in);
    int n1,n2,n3;
    System.out.println("enter three numbers: ");
    n1=input.nextInt();
    n2=input.nextInt();
    n3=input.nextInt();
    
   
    int total =sum(n1,n2,n3);
    double averge = avg(n1,n2,n3);

    display(total, averge);
    }
    public static int sum(int n1,int n2,int n3){
        return n1+n2+n3;

    }    
    public static int  avg(int n1,int n2,int n3) {
        return sum(n1, n2, n3)/3;
        
    }
    public static void display(int s,double a){
        System.out.println("the sum of three number is: "+s);
        System.out.println("the averge of three number is: "+a);
    }
    }