import java.util.Scanner;
public class OOP_T1_7 {
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        arrayBox box1=new arrayBox();
        int i;
        int sizeIn;
        System.out.print("Enter size: ");
        sizeIn=input.nextInt();
        box1.setValue(sizeIn);
        for(i=0;i<sizeIn;i++){
            box1.array[i]=input.nextInt();
        }
        box1.show();
        box1.plus2();
    }
}
class arrayBox{
    public int size;
    public int[] array;
    public int i;
    public int sum=0;

    public void setValue(int sizeIn){
        size=sizeIn;
        array=new int[size];
    }
    public void plus2(){
        i=0;
        while(i<2){
            sum=sum+array[i];
            i++;
        }
        System.out.printf("Sum of 0 and 1 is %d\n", sum);
    }
    public void show(){
        for(i=0;i<size;i++){
            System.out.printf("%d ", array[i]);
        }
    }
}