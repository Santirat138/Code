import java.util.Scanner;
class splitBox{
    int digiSize;
    int num;
    int[] arrayNum;
    int extNum;
    int newNum;
    int i;
    void setSize(int digitIn){
        digiSize=digitIn;
        arrayNum=new int[digiSize];
    }
    void splitNum(){
        for(i=0;i<digiSize;i++){
            extNum=newNum%10;
            arrayNum[i]=extNum;
            newNum=newNum/10;
            System.out.printf("Number : %d\n", arrayNum[i]);
        }
    }
}
class OOP_4{
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int num, digit;
        System.out.print("Enter number: ");
        num=input.nextInt();
        digit=countDigits(num);
        splitBox box1=new splitBox();
        box1.setSize(digit);
        box1.newNum=num;
        box1.splitNum();
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