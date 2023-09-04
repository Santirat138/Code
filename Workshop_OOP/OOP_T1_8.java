// Array 2D
import java.util.Scanner;
public class OOP_T1_8 {
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        arrayBox box=new arrayBox();

    }
}
class arrayBox{
    public int midIndex;
    public int size;
    public int[] array;

    public void setSize(int sizeIn){
        size=sizeIn;
        array=new int[size];
    }
    
}