#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> grid;

int main() {
    int N; cin >> N;

    grid.resize(N, vector<long long>(N));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> grid[y][x];
        }
    }

    int Q; cin >> Q;

    while (Q--) {
        char t; cin >> t;

        if (t == 'q') {
            int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;

            
        }
        else {
            int y, x; 
            long long v;
            cin >> y >> x >> v;

            
        }
    }
}