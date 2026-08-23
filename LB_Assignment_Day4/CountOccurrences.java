import java.util.Scanner;

public class CountOccurrences {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            numbers[i] = sc.nextInt();
        }

        System.out.print("Enter number to search: ");
        int search = sc.nextInt();

        int count = 0;

        for (int number : numbers) {

            if (number == search) {
                count++;
            }
        }

        System.out.println(search + " occurs " + count + " times.");
    }
}