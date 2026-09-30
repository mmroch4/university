import java.util.Scanner;

class Matrix {
   int data[][]; // os elementos da matriz em si
   int rows;     // numero de linhas
   int cols;     // numero de colunas

   // construtor padrao de matriz
   Matrix(int r, int c) {
      data = new int[r][c];
      rows = r;
      cols = c;
   }

   // Ler os rows x cols elementos da matriz
   public void read(Scanner in) {
      for (int i=0; i<rows; i++)
         for (int j=0; j<cols; j++)
            data[i][j] = in.nextInt();
   }

   // Representacao em String da matriz
   public String toString() {
      String ans = "";
      for (int i=0; i<rows; i++) {
         for (int j=0; j<cols; j++)
            ans += data[i][j] + " ";
         ans += "\n";
      }
      return ans;
   }   

   public static Matrix identity(int n) {
       Matrix newMatrix = new Matrix(n, n);

       for (int i = 0; i < n; i++) {
           newMatrix.data[i][i] = 1;
       }

       return newMatrix;
   }
   
   public Matrix transpose() {
       Matrix newMatrix = new Matrix(this.cols, this.rows);

       for (int i = 0; i < this.rows; i++) {
           for (int u = 0; u < this.cols; u++) {
               newMatrix.data[u][i] = this.data[i][u];
           }
       }

       return newMatrix;
   }
   
   public Matrix sum(Matrix m) {
       Matrix newMatrix = new Matrix(this.rows, this.cols);

       for (int i = 0; i < this.rows; i++) {
           for (int u = 0; u < this.cols; u++) {
               newMatrix.data[i][u] = this.data[i][u] + m.data[i][u];
           }
       }

       return newMatrix;
   }
   
   public Matrix multiply(Matrix m) {
       Matrix newMatrix = new Matrix(this.rows, m.cols);

       for (int i = 0; i < this.rows; i++) {
           for (int j = 0; j < m.cols; j++) {
               newMatrix.data[i][j] = 0;
               for (int u = 0; u < this.cols; u++) {
                   newMatrix.data[i][j] += this.data[i][u] * m.data[u][j];
               }
           }
       }

       return newMatrix;
   }
}
