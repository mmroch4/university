#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> nums;

  int v;
  int c = N;

  while (c--) {
    cin >> v;

    nums.push_back(v);
  }

  sort(nums.begin(), nums.end());

  int toRemove = 0;
  int count = 1;
  
  for (int i = 1; i < N; i++) {
      if (nums[i - 1] == nums[i]) {
          count++;
          continue;
      }

      if (count < nums[i - 1]) {
          toRemove += count;
      }
      else {
          toRemove += count - nums[i - 1];
      }

      count = 1;
  }

  if (count < nums[N - 1]) {
      toRemove += count;
  }
  else {
      toRemove += count - nums[N - 1];
  } 

  cout << toRemove << "\n";
}
