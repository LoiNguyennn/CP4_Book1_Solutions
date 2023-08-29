import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextInt();
        if (N % 2 != 0) {
            System.out.println((N / 2 + 1) * ((N + 1) / 2 + 1));
        } else {
            System.out.println((N / 2 + 1) * (N / 2 + 1));
        }
    }
}