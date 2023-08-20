import java.util.Scanner;

class OOP_2 {
    public static void main(String[] args) {
        int workHr;
        int ot = 0;
        int otHr = 0;
        int sal;
        Scanner inputHr = new Scanner(System.in);
        System.out.print("Enter work hour: ");
        workHr = inputHr.nextInt();
        if (workHr > 40) {
            ot = 20;
            otHr = workHr - 40;
        } else if (workHr == 40) {
            ot = 0;
        }
        sal = (ot * otHr) + (workHr * 120);
        System.out.printf("Salary: %d", sal);
    }
}