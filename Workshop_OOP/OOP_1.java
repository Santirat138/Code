import java.util.Scanner;

class OOP_1 {
    public static int power(int base, int pow) {
        int i;
        int ans = 1;
        for (i = 1; i <= pow; i++) {
            ans = ans * base;
        }
        return ans;
    }

    public static void main(String args[]) {
        int x;
        int result;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter x: ");
        x = input.nextInt();
        int pow4, pow3;
        pow4 = power(x, 4);
        pow3 = power(x, 3);
        result = (3 * pow4) + (2 * pow3) - x + 10;
        System.out.printf("Answer is %d", result);
    }
}