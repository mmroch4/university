import java.util.*;

class naive {
    private static Scanner stdin = new Scanner(System.in);
    
    public static void main(String[] args) {
        int A = stdin.nextInt();
        A = Math.max(0, A - 1);
        
        int B = stdin.nextInt();
        
        int count = naive.countPrimesFromZeroToN(B) - naive.countPrimesFromZeroToN(A);

        System.out.println(count);
    }

    private static int countPrimesFromZeroToN(int n) {
        int count = 0;

        for (int i = 2; i <= n; i++) {
            if (naive.isPrime(i)) count++;
        }

        return count;
    }

    private static boolean isPrime(int n) {
        if (n <= 1) return false;
        
        for (int i = 2; i <= Math.sqrt(n); i += 1) {
            if (n % i == 0) return false;
        }

        return true;
    }
}