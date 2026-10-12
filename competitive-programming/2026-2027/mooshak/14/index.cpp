#include <bits/stdc++.h>

using namespace std;

long long getCost(int k, vector<int>& heights, vector<int>& costs, int n) {
    long long cost = 0;

    int i = 0;

    while (i < n) {
        cost += abs(heights[i] - k) * costs[i];
        i++;
    }

    return cost;
}

int main() {
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        vector<int> heights(N);
        vector<int> costs(N);

        int mn = INT_MAX;
        int mx = INT_MIN;

        for (int i = 0; i < N; i++) {
            cin >> heights[i];

            mn = min(mn, heights[i]);
            mx = max(mx, heights[i]);
        }

        for (int i = 0; i < N; i++) {
            cin >> costs[i];
        }

        int DEBUG = 100;
        while (mx - mn > 1 && DEBUG--) {
            int m1 = mn + (mx - mn) / 3;
            int m2 = mn + (mx - mn) * 2 / 3;
            int diff = m2 - m1;

            if (diff == 0) {
                mn = m1;
                break;
            }

            if (getCost(m1, heights, costs, N) <= getCost(m2, heights, costs, N)) {
                if (mx == m2) {
                    m2--;
                }
                mx = m2;
            }
            else {                
                if (mn == m1) {
                    m1++;
                }
                mn = m1;

            }
        }

        cout << min(getCost(mn, heights, costs, N), getCost(mx, heights, costs, N)) << "\n";
    }

    return 0;
}