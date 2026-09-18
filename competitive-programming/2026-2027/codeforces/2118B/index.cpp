#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N, i;

    cin >> T;

    while (T--) {
        cin >> N;

        cout << 2 * N - 3 << "\n";

        for (i = 2; i <= N; i++) {
            cout << i << " 1 " << i << "\n";
        }

        for (i = 2; i < N; i++) {
            cout << i - 1 << " " << i <<  " " << N << "\n";
        }
    }
}