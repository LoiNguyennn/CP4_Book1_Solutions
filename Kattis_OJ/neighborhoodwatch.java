import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long[] a = new long[k + 1];
        a[0] = 0;
        long ans = 0;
        for (int i = 1; i <= k; ++i) {
            a[i] = sc.nextLong();
            ans += (a[i] - a[i - 1]) * (n - a[i] + 1);
        }        
        System.out.println(ans);
    }
}