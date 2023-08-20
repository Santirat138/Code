import java.util.Scanner;
class OOP_22{
    static class rec{
        int l, w;
        int calArea(int l, int w){
            return l*w;
        }
    }
    static class tri{
        int b, h;
        double calArea(int b, int h){
            return 0.5*b*h;
        }
    }
    static class cir{
        int rad;
        double calArea(int rad){
            return 3.14*rad*rad;
        }
    }
    public static void main(String args[]){
        int num;
        double area;
        System.out.print("Enter number: ");
        Scanner inputNum=new Scanner(System.in);
        num=inputNum.nextInt();
        switch (num) {
            case 1:
                rec b1=new rec();
                System.out.print("Enter l: ");
                b1.l=inputNum.nextInt();
                System.out.print("Enter w: ");
                b1.w=inputNum.nextInt();
                area=b1.calArea(b1.l, b1.w);
                break;
            case 2:
                tri t1=new tri();
                System.out.print("Enter base: ");
                t1.b=inputNum.nextInt();
                System.out.print("Enter high: ");
                t1.h=inputNum.nextInt();
                area=t1.calArea(t1.b, t1.h);
                break;
            case 3:
                cir c1=new cir();
                System.out.print("Enter radius: ");
                c1.rad=inputNum.nextInt();
                area=c1.calArea(c1.rad);
                break;
            default:
                area=0;
                break;
        }
        System.out.printf("Area: %f", area);
    }
}