#include <bits/stdc++.h>

using namespace std;

#define INT_SIZE 32

int main() {
    int N; cin >> N;

    multiset<pair<int, int>> values;

    int t;
    while (N--) {
        cin >> t;

        int ones = 0;
        int p = 0;

        while (p < INT_SIZE) {
            if (t & (1 << p)) {
                ones++;
            }

            p++;
        }

        values.insert({ones, -t});
    }

    auto it = values.rbegin();

    cout << -it->second;

    it++;

    while (it != values.rend()) {
        cout << " " << -it->second;
        it++;
    }

    cout << "\n";
}