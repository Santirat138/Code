import java.util.Scanner;
class OOP_5{
    public static int power(int base, int pow){
        int i;
        int ans=1;
        for(i=1;i<=pow;i++){
            ans=ans*base;
        }
        return ans;
    }
    public static void main(String args[]){
        Scanner input=new Scanner(System.in);
        int num;
        System.out.print("Enter number: ");
        num=input.nextInt();
        int i;
        
    }
}