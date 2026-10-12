#include <bits/stdc++.h>

using namespace std;

#define SEGTREE_NEUTRAL {}
typedef vector<int> SEGTREE_VALUE;


vector<int> values;
vector<SEGTREE_VALUE> segtree;

SEGTREE_VALUE merge(SEGTREE_VALUE& a, SEGTREE_VALUE& b) {
  int i = 0;
  int j = 0;

  int Mi = a.size();
  int Mj = b.size();

  vector<int> ordered;

  while (i < Mi && j < Mj) {
      if (a[i] <= b[j]) {
          ordered.push_back(a[i]);
          i++;
      }
      else {
          ordered.push_back(b[j]);
          j++;
      }
  }

  while (i < Mi) {
      ordered.push_back(a[i]);
      i++;
  }

  while (j < Mj) {
      ordered.push_back(b[j]);
      j++;
  }

  return ordered;
}

int countGreater(vector<int>& elements, int value) {
    int l = 0;
    int r = elements.size() - 1;

    while (l < r) {
        int m = l + (r - l) / 2;

        if (elements[m] > value) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }

    if (elements[l] <= value) return 0;

    return elements.size() - l;
}

int query(int p, int l, int r, int a, int b, int k) {
  if (r < a || b < l) {
    return 0;
  }

  if (a <= l && r <= b) {
    return countGreater(segtree[p], k);
  }

  int m = l + (r - l) / 2;

  return query(2 * p, l, m, a, b, k) + query(2 * p + 1, m + 1, r, a, b, k);
}

void build(int p, int l, int r) {
    if (l == r) {
        segtree[p] = {values[l]};
        return;
    }

    int m = l + (r - l) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);

    segtree[p] = merge(segtree[2 * p], segtree[2 * p + 1]);
}

int main() {
  int N, Q;
  cin >> N >> Q;

  values.resize(N);
  segtree.resize(4 * N);
  
  for (int i = 0; i < N; i++) {
      cin >> values[i];
  }

  build(1, 0, N - 1);

  while (Q--) {
    int i, j, k;
    cin >> i >> j >> k;
    i--;
    j--;

    cout << query(1, 0, N - 1, i, j, k) << "\n";
  }

  return 0;
}
