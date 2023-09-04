import java.util.Scanner;
public class OOP_T2_8{
    public static void main(String[] args){
        arrayBox box=new arrayBox();
        int sizeIn;
        Scanner input=new Scanner(System.in);
        sizeIn=input.nextInt();
        box.setSize(sizeIn);
        box.setArray();
        box.setNewArray();
        box.show();
    }
}
class arrayBox{
    private int size;
    private int newSize;
    private int[] array;
    private int lastNum;
    public int i;
    Scanner input=new Scanner(System.in);
    public void setSize(int sizeIn){
        size=sizeIn;
        array=new int[size];
    }
    public void setArray(){
        i=0;
        for(i=0;i<size;i++){
            array[i]=input.nextInt();
        }
        lastNum=array[size-1];
    }
    public void setNewArray(){
        newSize=size*2;
        array=new int[newSize];
        for(i=0;i<newSize;i++){
            if(i==newSize-1){
                array[i]=lastNum;
                break;
            }
            else{
                array[i]=0;
            }
        }
    }
    public void show(){
        for(i=0;i<newSize;i++){
            System.out.printf("%d ", array[i]);
        }
    }
}