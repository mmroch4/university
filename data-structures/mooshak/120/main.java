import java.util.*;

class main {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);

        int N = stdin.nextInt();

        int l = N / 2;
        int r = l;

        for (int u = 0; u < N / 2; u++) {
            for (int i = 0; i < N; i++) {
                if (l <= i && i <= r) {
                    System.out.print("#");
                } else {
                    System.out.print(".");
                }
            }
            
            System.out.print("\n");

            r++;
            l--;
        }

        for (int i = 0; i < N; i++) {
            System.out.print("#");
        }

        System.out.print("\n");

        l = 1;
        r = N - 2;

        
        for (int u = 0; u < N / 2; u++) {
            for (int i = 0; i < N; i++) {
                if (l <= i && i <= r) {
                    System.out.print("#");
                } else {
                    System.out.print(".");
                }
            }
            
            System.out.print("\n");

            r--;
            l++;
        }
    }
}
