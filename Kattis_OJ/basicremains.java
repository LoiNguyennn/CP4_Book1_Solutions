import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int b = scanner.nextInt();
            if (b == 0) break;
            BigInteger p = new BigInteger(scanner.next(), b);
            BigInteger m = new BigInteger(scanner.next(), b);
            System.out.println((p.mod(m)).toString(b));
        }
    }
}