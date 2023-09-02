import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] agrs) {
        BigInteger[] a = new BigInteger[50001];
        a[0] = BigInteger.valueOf(0);
        for (int i = 1; i <= 50000; ++i) {
            a[i] = a[i - 1].add(BigInteger.valueOf(i).pow(3));
            
        }
        int x;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            x = sc.nextInt();
            System.out.println(a[x]);
        }
    }
}