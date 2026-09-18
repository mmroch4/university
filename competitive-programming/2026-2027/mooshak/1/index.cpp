/*
 * IF N == 1 THEN MIN_MOVES = 0
 * LOOP THROUGH THE VALUES
 * FOR EACH VALUE V AT POSITION I COMPARE THE I-1th VALUE AND IF IT IS LOWER THEN EQUALIZE IT
 * MIN_MOVES EQUALS TO THE SUM OF THE DIFFERENCE OF THE ADJACENT VALUES THAT ARE LOWER THAN EACH OTHER
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;

  cin >> N;

  vector<int> values(N, 0);

  for (int i = 0; i < N; i++) {
    cin >> values[i];
  }

  if (N == 1) {
    cout << 0 << "\n";
    return 0;
  }

  long long moves = 0;

  for (int u = 1; u < N; u++) {
    if (values[u - 1] > values[u]) {
      moves += values[u - 1] - values[u];

      values[u] = values[u - 1];
    }
  }

  cout << moves << "\n";
}
