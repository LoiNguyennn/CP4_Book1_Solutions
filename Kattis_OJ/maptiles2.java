import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String quadkey = sc.nextLine();
        int level = quadkey.length();
        System.out.print(level + " ");

        int n = 1 << level;
        int x = 0, y = 0;
        for (int i = 0; i < quadkey.length(); ++i) {
            n = n >> 1;
            if (quadkey.charAt(i) == '1')
                y += n;
            else if (quadkey.charAt(i) == '2')
                x += n;
            else if (quadkey.charAt(i) == '3') {
                x += n;
                y += n;
            }
        }
        System.out.print(y + " " + x);
    }
}