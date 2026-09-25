import java.util.*;

class main {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);

        int N = stdin.nextInt();

        long first = stdin.nextLong();

        long min = first;
        long max = first;
        long acc = first;
        
        int c = N - 1;

        while (c-- > 0) {
            long value = stdin.nextLong();

            acc += value;

            min = Math.min(min, value);   
            max = Math.max(max, value);
        }

        System.out.println(String.format("%.2f", (double)acc / (double)N));
        System.out.println(max - min);

        
        
    }
}