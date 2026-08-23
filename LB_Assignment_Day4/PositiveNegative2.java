import java.util.Scanner;

public class PositiveNegative2 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            numbers[i] = sc.nextInt();
        }

        int positive = 0;
        int negative = 0;

        for (int number : numbers) {

            if (number > 0) {
                positive++;
            }
            else if (number < 0) {
                negative++;
            }
        }

        System.out.println("Positive numbers: " + positive);
        System.out.println("Negative numbers: " + negative);
    }
}