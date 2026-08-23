import java.util.Scanner;

public class SmallestElement {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            numbers[i] = sc.nextInt();
        }

        int smallest = numbers[0];

        for (int number : numbers) {

            if (number < smallest) {
                smallest = number;
            }
        }

        System.out.println("The smallest element is: " + smallest);
    }
}