import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            System.out.print(n + " is ");
            BigInteger big_n = BigInteger.valueOf(n);
            String r = new StringBuffer(big_n.toString()).reverse().toString();
            int rn = Integer.parseInt(r);
            BigInteger big_reverse_n = new BigInteger(r);
            if (!big_n.isProbablePrime(10))
                System.out.println("not prime.");
            else if (n != rn && big_reverse_n.isProbablePrime(10)) {
                System.out.println("emirp.");
            } else {
                System.out.println("prime.");
            }
        }
    }
}