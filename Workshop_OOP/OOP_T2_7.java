import java.util.Scanner;
public class OOP_T2_7{
    public static void main(String[] args){
        arrayBox boxObj=new arrayBox();
        Scanner input=new Scanner(System.in);
        boxObj.setSize();
        boxObj.setElement();
        boxObj.showArray();
    }
}
class arrayBox{
    private int size;
    private int i;
    public int[] array;
    public int num;
    Scanner input=new Scanner(System.in);
    public void setSize(){
        System.out.println("Enter size of array. ");
        size=input.nextInt();
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