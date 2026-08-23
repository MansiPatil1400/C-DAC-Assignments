import java.util.Scanner;

public class LargestElement {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            numbers[i] = sc.nextInt();
        }

        int largest = numbers[0];

        for (int number : numbers) {

            if (number > largest) {
                largest = number;
            }
        }

        System.out.println("The largest element is: " + largest);
    }
}