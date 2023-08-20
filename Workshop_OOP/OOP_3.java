import java.util.Scanner;
class OOP_3{
    public static int findMax(int arr[]){
        int max=arr[0];
        int i;
        for(i=0;i<3;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
    public static void main(String args[]){
        Scanner input=new Scanner(System.in);
        int array[];
        array=new int[3];
        int i=0;
        int maxNum;
        while(i<3){
            System.out.printf("Enter index%d : ", i);
            array[i]=input.nextInt();
            i++;
        }
        maxNum=findMax(array);
        System.out.printf("Max is %d\n", maxNum);
    }
}