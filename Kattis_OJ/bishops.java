import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        while (sc.hasNext()) {
            n = sc.nextInt();
            if (n == 1)
                System.out.println(1);
            else 
                System.out.println(n + n - 2);
        }
    }
}