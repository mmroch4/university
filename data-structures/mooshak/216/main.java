import java.util.*;

class main {

    private static Scanner stdin = new Scanner(System.in);

    public static void main(String[] args) {
        int L = main.stdin.nextInt();
        int C = main.stdin.nextInt();

        int[][] grid = new int[L][C];

        int m = -1;
        int c = -1;

        for (int i = 0; i < L; i++) {
            String line = main.stdin.next();

            int count = 0;

            for (int u = 0; u < C; u++) {
                if (line.charAt(u) == '.') {
                    if (m < count) {
                        m = count;
                        c = 1;
                    } else if (m == count) {
                        c++;
                    }

                    count = 0;
                    grid[i][u] = 0;
                } else {
                    count++;
                    grid[i][u] = 1;
                }
            }

            if (m < count) {
                m = count;
                c = 1;
            } else if (m == count) {
                c++;
            }
        }

        for (int u = 0; u < C; u++) {
            int count = 0;
            
            for (int i = 0; i < L; i++) {
                if (grid[i][u] == 0) {
                    if (m < count) {
                        m = count;
                        c = 1;
                    } else if (m == count) {
                        c++;
                    }

                    count = 0;
                } else {
                    count++;
                }
            }

            if (m < count) {
                m = count;
                c = 1;
            } else if (m == count) {
                c++;
            }
        }

        System.out.println(m + " " + c);
    }
}
