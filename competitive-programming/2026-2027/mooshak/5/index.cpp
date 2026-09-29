#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  while (N != 0) {
    int c, v;

    map<string, int> combinations;

    int m = -1;
    
    while (N--) {
      vector<int> comb;

      for (int i = 0; i < 5; i++) {
        cin >> v;

        comb.push_back(v);
      }

      sort(comb.begin(), comb.end());

      string k;

      for (int x : comb) {
          k += to_string(x);
      }

      if (combinations.find(k) == combinations.end()) {
          combinations.insert({k, 0});
      }

      m = max({++combinations[k], m});
    }

    int count = 0;
    
    for (auto x : combinations) {
        if (x.second == m) count += x.second;
    }
    

    cout << count << "\n";

    // Cycle
    cin >> N;
  }
}
