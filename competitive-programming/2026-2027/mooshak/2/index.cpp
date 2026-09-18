#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;

  cin >> T;

  while (T--) {
    string A, B;

    cin >> A >> B;

    int A_size = A.length();
    int B_size = B.length();

    int i = 0;
    int u = 0;

    while (i < A_size && u < B_size) {
        if (A[i] == B[u]) {
            i++;
        }
        u++;
    }

    if (i == A_size) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
  }
}
