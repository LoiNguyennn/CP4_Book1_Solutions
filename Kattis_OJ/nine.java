import java.util.Scanner;
import java.math.BigInteger;

public class nine {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        while (TC-- != 0) {
            String in = sc.next();
            BigInteger d = new BigInteger(in);
            BigInteger ans = BigInteger.valueOf(9);
            BigInteger MOD = BigInteger.valueOf(1000000007);
            ans = ans.modPow(d.subtract(BigInteger.valueOf(1)), MOD);
            ans = (ans.multiply(BigInteger.valueOf(8))).mod(MOD);
            System.out.println(ans);
        }
    }
}