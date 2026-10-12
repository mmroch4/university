#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, T; cin >> N >> T;

    vector<long long> machines(N);

    for (int i = 0; i < N; i++) cin >> machines[i];

    sort(machines.begin(), machines.end());

    if (N == 1) {
        cout << machines[0] * T << "\n";
        return 0;
    }

    long long mn = 1;
    long long mx = T * *machines.rbegin();

    while (mn != mx) {
        long long m = mn + (mx - mn) / 2;

        long long canMake = 0;

        int i = 0;
        while (i < N && canMake < T) {
            canMake += m / machines[i];
            i++;
        }
        
        if (canMake >= T) {
            mx = m;
        }
        else {
            mn = m + 1;
        }
    }

    cout << mn << "\n";
}