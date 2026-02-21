#include <bits/stdc++.h>

using namespace std;

const int N = 35'000 + 5;
const int K = 50;
const int INF = 1e9;

int dp[N][K];

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> arr(n + 1);

  for (int i = 0; i <= n; i++) cin >> arr[i];

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < K; j++)
    {
      dp[i][j] = -INF;
    }
  }

  dp[0][0] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= k; j++)
    {
      unordered_set<int> numbers;

      for (int x = i; x >= 1; x--)
      {
        numbers.insert(arr[x]);
        
        int distinct = (int) numbers.size();

        dp[i][j] = max(dp[i][j], distinct + dp[x - 1][j - 1]);
      }
      
    }
    
  }
  
  // cout << dp[] << "\n";
  
  return 0;
}