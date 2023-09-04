import java.util.Scanner;
public class OOP_T2_7{
    public static void main(String[] args){
        arrayBox boxObj=new arrayBox();
        Scanner input=new Scanner(System.in);
        int sizeIn;
        sizeIn=input.nextInt();
        boxObj.setSize(sizeIn);
        
    }
}
class arrayBox{
    private int size;
    private int i;
    public int[] array;
    public int num;
    Scanner input=new Scanner(System.in);
    public void setSize(int sizeIn){
        System.out.println("Enter size of array. ");
        size=sizeIn;
        array=new int[size];
    }
    public void setElement(){
        for(i=0;i<size;i++){
            System.out.printf("Enter index%d: ", i);
            array[i]=input.nextInt();
        }
    }
    public void showArray(){
        for(i=0;i<size;i++){
            System.out.printf("%d ", array[i]);
        }
    }
}