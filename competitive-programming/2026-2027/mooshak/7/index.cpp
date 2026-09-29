#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

void safeAdd(int key, int value, map<int, int>& m) {
    if (m.find(key) == m.end()) {
        m.insert({key, value});
        return;
    }

    m[key] += value;
}

int safePop(map<int, int>& m) {
    auto it = m.rbegin();
    
    if (it->second == 0) {
        throw invalid_argument("Cannot remove empty entry");
        return -1;
    }

    int r = it->first;

    if (it->second == 1) {
        m.erase(next(it).base());
    }
    else {
        m[it->first]--;
    }

    return r;
}

int safeGet(int key, map<int, int>& m) {
    if (m.find(key) == m.end()) {
        return 0;
    }

    return m[key];
}

int main() {
    int N; cin >> N;

    while (N--) {
        int B, SG, SB; 
        cin >> B >> SG >> SB;

        map<int, int> green;
        map<int, int> blue;

        int acc = 0;

        int v;

        for (int i = 0; i < SG; i++) {
            cin >> v;

            acc += v;

            safeAdd(v, 1, green);
        }

        for (int i = 0; i < SB; i++) {
            cin >> v;

            acc -= v;

            safeAdd(v, 1, blue);
        }

        map<int, int> winner;
        int winnerCount;
        
        map<int, int> looser;
        int looserCount;
        
        if (acc == 0) {
            cout << "green and blue died\n\n";
            continue;
        }
        else if (acc > 0) {
            cout << "green wins\n";

            looser = blue;
            looserCount = SB;
            winner = green;
            winnerCount = SG;
        }
        else {
            cout << "blue wins\n";            

            winner = blue;
            winnerCount = SB;
            looser = green;
            looserCount = SG;
        }

        while (safeGet(0, looser) != looserCount) {
            int round = 0;
            int limit = min({B, SB, SG});

            vector<int> w;
            vector<int> l;

            while (round < limit) {
                int wFirst = safePop(winner);
                int lFirst = safePop(looser);

                if (wFirst == lFirst) {
                    w.push_back(0);
                    l.push_back(0);
                }
                else if (wFirst > lFirst) {
                    w.push_back(wFirst - lFirst);
                    l.push_back(0);
                }
                else {
                    w.push_back(0);
                    l.push_back(lFirst - wFirst);
                }

                round++;
            }

            for (int x : w) {
                safeAdd(x, 1, winner);
            }

            for (int y : l) {
                safeAdd(y, 1, looser);
            }
        }

        for (auto it = winner.rbegin(); it != winner.rend(); it++) {
            if (it->first == 0) continue;
            
            for (int x = 0; x < it->second; x++) {
                cout << it->first << "\n";
            }
        }

        if (N != 0) {
            cout << "\n"; 
        }
    }
    
}