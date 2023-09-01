import java.util.Scanner;
import java.math.BigInteger;

public class oktalni {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger ans = new BigInteger(sc.nextLine(), 2);
        System.out.println(ans.toString(8));
    }
}