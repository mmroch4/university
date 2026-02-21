// https://atcoder.jp/contests/dp/tasks/dp_p

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int N = 1e5 + 5;

int add(int a, int b) {
  int res = a + b;

  if (res >= MOD) res -= MOD;

  return res;
}

int mult(int a, int b) {
  long long res = 1LL * a * b;

  if (res >= MOD) res %= MOD;

  return res;
}

vector<int> g[N];
int dp[N][2];

void dfs(int node, int p) {
  dp[node][0] = 1;
  dp[node][1] = 1;

  for (auto& to : g[node]) {
    if (to == p) continue;

    dfs(to, node);

    dp[node][1] = mult(dp[node][1], dp[to][0]);
    dp[node][0] = mult(dp[node][0], add(dp[to][0], dp[to][1]));
  }
}

int main() {
  int n;

  cin >> n;

  for (int i = 0; i < n - 1; i++)
  {
    int st, et;

    cin >> st >> et;
    
    --st;
    --et;

    g[st].emplace_back(et);
    g[et].emplace_back(st);

  }

  dfs(0, -1);

  cout << add(dp[0][0], dp[0][1]);

  return 0;
}