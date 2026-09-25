import java.util.*;

class main {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);

        int N = stdin.nextInt();

        Set<Integer> bannedIngredients = new HashSet<Integer>();

        while (N-- > 0) {
            int a = stdin.nextInt();

            bannedIngredients.add(a);
        }

        int P = stdin.nextInt();

        int canOrder = 0;

        while (P-- > 0) {
            int K = stdin.nextInt();

            Boolean c = true;
            
            while (K-- > 0) {
                int ingredient = stdin.nextInt();

                if (bannedIngredients.contains(ingredient)) {
                    c = false;
                }
            }

            if (c) {
                canOrder++;
            }
        }

        System.out.println(canOrder);
    }
}