import java.util.Scanner;
public class Warmup{
	public static void main(String[] args){
		Scanner input=new Scanner(System.in);
		System.out.println("Enter size.");
		int size=input.nextInt();
		int[] array=new int[size];
		for(int i=0;i<size;i++){
			System.out.printf("Enter index%d: ", i);
			array[i]=input.nextInt();
		}
		toolBox tBox1=new toolBox(size, array);
		int max=tBox1.findMax();
		int min=tBox1.findMin();
		System.out.printf("Max: %d\nMin: %d\n", max, min);
	}
}
class arrayBox{
	public int[] array;
	public int size;
	
	public arrayBox(int sizeIn, int[] arrayIn){
		size=sizeIn;
		array=new int[size];
		array=arrayIn;
	}
}
class toolBox extends arrayBox{
	public toolBox(int sizeIn, int[] arrayIn){
		super(sizeIn, arrayIn);
	}
	public int findMax(){
		int maxNum=array[0];
		for(int i=0;i<size;i++){
			if(maxNum<array[i]){
				maxNum=array[i];
			}
		}
		return maxNum;
	}
	public int findMin(){
		int minNum=array[0];
		for(int i=0;i<size;i++){
			if(minNum>array[i]){
				minNum=array[i];
			}
		}
		return minNum;
	}
}