#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359

int main() {
    int T; cin >> T;

    while (T--) {
        int N, F; cin >> N >> F;
        vector<int> radii(N);
        vector<double> volumes(N);
        double v;
        int t;
        for (int i = 0; i < N; i++) {
            cin >> t;

            radii[i] = t;
            volumes[i] = t * t * PI;

            v += volumes[i];
            cout << t << " : " << volumes[i] << "\n";
        };

        cout << "\n\n";

        cout << v << "  -->  " << v / (F + 1) << "\n";
    }

}