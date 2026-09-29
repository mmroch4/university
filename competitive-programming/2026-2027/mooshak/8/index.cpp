#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

void safeRemove(int key, int value, map<int, int> &m) {
  auto it = m.find(key);

  if (it == m.end()) {
    return;
  }

  if (it->second < value) {
    throw invalid_argument("cannot remove more than the value of the key");
    return;
  }

  it->second -= value;

  if (it->second == 0) {
    m.erase(it);
  }
}

void safeAdd(int key, int value, map<int, int> &m) {
  auto it = m.find(key);

  if (it != m.end()) {
    it->second += value;

    return;
  }

  m.insert({key, value});
}

int main() {
  int X;
  cin >> X;
  int N;
  cin >> N;

  map<int, pair<int, int>> intervals;
  set<int> trafficLights;
  map<int, int> distances;

  int v;

  cin >> v;

  intervals.insert({v, {v, X - v}});
  trafficLights.insert(v);

  safeAdd(v, 1, distances);
  safeAdd(X - v, 1, distances);

  cout << distances.rbegin()->first << " ";

  int minTL = v;
  int maxTL = v;

  for (int i = 1; i < N; i++) {
    cin >> v;

    if (v < minTL) {
      int right = *(trafficLights.begin());

      safeRemove(intervals[right].first, 1, distances);

      int rD = right - v;
      int lD = v;

      intervals[right].first = rD;
      intervals.insert({v, {lD, rD}});

      safeAdd(rD, 2, distances);
      safeAdd(lD, 1, distances);
    } else if (maxTL < v) {
      int left = *(trafficLights.rbegin());

      safeRemove(intervals[left].second, 1, distances);

      int rD = X - v;
      int lD = v - left;

      intervals[left].second = lD;
      intervals.insert({v, {lD, rD}});

      safeAdd(lD, 2, distances);
      safeAdd(rD, 1, distances);
    } else {
      auto rightIt = trafficLights.upper_bound(v);
      int right = *rightIt;
      int left = *(--rightIt);

      safeRemove(intervals[right].first, 2, distances);

      int rD = right - v;
      int lD = v - left;

      intervals[right].first = rD;
      intervals[left].second = lD;

      intervals.insert({v, {lD, rD}});

      safeAdd(lD, 2, distances);
      safeAdd(rD, 2, distances);
    }

    maxTL = max(v, maxTL);
    minTL = min(v, minTL);

    trafficLights.insert(v);

    cout << distances.rbegin()->first << " ";
  }

  cout << "\n";
}
