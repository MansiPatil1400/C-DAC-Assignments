import java.util.Scanner;

public class ArrayElements {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            numbers[i] = sc.nextInt();
        }

        System.out.println("Array elements are:");

        for (int number : numbers) {
            System.out.print(number + " ");
        }
    }
}