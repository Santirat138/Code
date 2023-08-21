import java.util.Scanner;
class OOP_4{
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int num;
        System.out.print("Enter number: ");
        num=input.nextInt();

    }
    public static int countDigits(int numIn){
        int digi=0;
        int numRem=numIn;
        while(numRem!=0){
            numRem=numRem/10;
            digi++;
        }
        return digi;
    }
}
class splitBox{
    int digiSize;
    int num;
    void setVal(int digi, int numIn){
        digiSize=digi;
        num=numIn;
    }

}