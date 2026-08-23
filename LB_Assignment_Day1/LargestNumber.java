public class LargestNumber {
    public static void main(String[] args) {
        int a = 25;
        int b = 40;
        int c = 15;

        int largest;

        if (a > b) {
            if (a > c) {
                largest = a;
            } else {
                largest = c;
            }
        } else {
            if (b > c) {
                largest = b;
            } else {
                largest = c;
            }
        }

        System.out.println("The largest number is: " + largest);
    }
}