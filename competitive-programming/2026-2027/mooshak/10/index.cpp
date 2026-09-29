#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    multiset<int> tickets;
    
    int t;
    
    for (int i = 0; i < N; i++) {
        cin >> t;

        tickets.insert(t);
    }

    for (int i = 0; i < M; i++) {
        cin >> t;

        if (!N) {
            cout << -1 << "\n";
            continue;
        };

        auto it = tickets.lower_bound(t);

        if (it == tickets.begin() && *it > t) {
            cout << -1 << "\n";
            continue;
        }
        else if (it == tickets.end() || *it > t) {
            it--;
        }

        cout << *it << "\n";

        tickets.erase(it);
        
        N--;
    }
}