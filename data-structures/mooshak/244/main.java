import java.util.*;

class main {
    private static Scanner stdin = new Scanner(System.in);

    public static void main(String[] args) {
        int A = stdin.nextInt();
        int B = stdin.nextInt();

        System.out.println(main.countPrimes(A, B));
    }

    private static int countPrimes(int from, int to) {
        if (to <= 2) return 1;

        boolean[] table = new boolean[to + 1];
        
        for (int i = 2; i <= to; i++) {
            if (i % 2 == 0) {
                table[i] = false;
            } else {
                table[i] = true;
            }
        }
        
        int count = 0;

        if (from <= 2) {
            count++;
        }

        int p = 3;

        while (p <= to) {
            if (from <= p) count++;

            for (int i = 1; i * p <= to; i++) {
                table[i * p] = false;
            }

            while (p <= to && !table[p]) p += 2;
        }

        return count;

    }
}
