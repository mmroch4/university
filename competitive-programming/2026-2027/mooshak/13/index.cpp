#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

double PI = acos(-1);
double DIFF = 1e-6;

int main() {
    int T; cin >> T;

    while (T--) {
        int N, F; cin >> N >> F;
        F++;
        
        vector<double> areas(N);

        int t;
        double total = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> t;
            areas[i] = t * t;
            total += areas[i];
        };

        double mn = 0;
        double mx = total;

        while (mx - mn > DIFF) {
            double m = mn + (mx - mn) / 2;

            int canMake = 0;

            int i = 0;
            while (i < N && canMake < F) {
                canMake += floor(areas[i] / m);
                i++;
            }

            if (canMake >= F) {
                mn = m;
            }
            else {
                mx = m;
            }
        }

        cout << setprecision(20) << mx * PI << "\n";
    }

}