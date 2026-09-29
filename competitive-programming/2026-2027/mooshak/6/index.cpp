#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  map<int, int> occurences;

  int init = 0;
  int m = 0;

  int v;

  for (int i = 0; i < N; i++) {
    cin >> v;

    if (occurences.find(v) == occurences.end()) {
      occurences.insert({v, i});

      m = max({m, i - init + 1});

      continue;
    }

    if (occurences[v] < init) {
        occurences[v] = i;
  
        m = max({m, i - init + 1});
  
        continue;
    }

    if (init <= occurences[v]) {
        m = max({m, i - occurences[v]});

        init = occurences[v] + 1;
        
        occurences[v] = i;

        continue;
    }

  }

  cout << m << "\n";
}
