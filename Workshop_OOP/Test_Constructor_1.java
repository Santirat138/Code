public class Test_Constructor_1 {
    public static void main(String[] args){
        cnstor con1=new cnstor();
        int number1, number2;
        number1=con1.num1;
        number2=con1.num2;
        System.out.printf("Number1 is %d\nNumber2 is %d\n", number1, number2);
    }
}
class cnstor{
    public int num1;
    public int num2;
    public cnstor(){
        num1=5;
        num2=10;
    }
}