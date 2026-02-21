#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> cities(n);

  for (int i = 0; i < n; i++)
  {
    cin >> cities[i];
  }
  
  vector<vector<double>> dist(n, vector<double>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> dist[i][j];
    }
  }
  
  
  
  return 0;
}