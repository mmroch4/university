import java.util.*;

class main {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);

        int N = stdin.nextInt();
        stdin.nextLine();

        System.out.println(N);
        
        while (N-- > 0) {
            String word = stdin.nextLine().toLowerCase();

            int l = 0;
            int r = word.length() - 1;

            boolean isDiff = false;

            while (l < r) {
                char a = word.charAt(l);
                char b = word.charAt(r);

                if (a < 97 || 122 < a) {
                    l++;
                    continue;
                }

                
                if (b < 97 || 122 < b) {
                    r--;
                    continue;
                }

                if (a != b) {                    
                    isDiff = true;
                    break;
                }

                l++;
                r--;
            }

            if (isDiff) {
                System.out.println("nao");
            }
            else {
                System.out.println("sim");                
            }
            
        }
    }
}