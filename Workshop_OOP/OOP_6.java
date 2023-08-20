import java.util.Scanner;
class OOP_6{
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int num;
        num=input.nextInt();
        int digits;
        int result;
        digits=countDigits(num);
        result=calNum(num, digits);
        System.out.printf("Sum : %d\n", result);
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
    public static int calNum(int numIn, int size){
        int[] array;
        int i;
        int pow;
        int sumNum=0;
        array=new int[size];
        for(i=0;i<size;i++){
           pow=power(i);
           array[i]=(numIn/pow)%10;
        }
        for(i=0;i<size;i++){
            sumNum=sumNum+array[i];
        }
        return sumNum;
    }
    public static int power(int numPow){
        int ans=1;
        int i;
        for(i=0;i<numPow;i++){
            ans=ans*10;
        }
        return ans;
    }
}
