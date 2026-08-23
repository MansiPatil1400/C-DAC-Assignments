import java.util.Scanner;

public class SumN {

    static int calculateSum(int n) {

        int sum = 0;

        for (int i = 1; i <= n; i++) {
            sum = sum + i;
        }

        return sum;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int answer = calculateSum(n);

        System.out.println("Sum = " + answer);
    }
}