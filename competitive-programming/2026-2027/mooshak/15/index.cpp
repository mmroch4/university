#include <bits/stdc++.h>

#define PII pair<int, int>
#define NEUTRAL {-1, 1}

using namespace std;

vector<int> warriors;
vector<PII> segtree;

PII merge(PII a, PII b) {
  if (a.first == b.first) {
    return {a.first, a.second + b.second};
  } else if (a.first < b.first) {
    return b;
  } else {
    return a;
  }
}

PII query(int p, int l, int r, int a, int b) {
  if (r < a || b < l) {
    return NEUTRAL;
  }

  if (a <= l && r <= b) {
    return segtree[p];
  }

  int m = l + (r - l) / 2;

  return merge(query(2 * p, l, m, a, b), query(2 * p + 1, m + 1, r, a, b));
}

void build(int p, int l, int r) {
    if (l == r) {
        segtree[p] = {warriors[l], 1};
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

  warriors.resize(N);
  segtree.resize(4 * N);
  
  for (int i = 0; i < N; i++) {
      cin >> warriors[i];
  }

  build(1, 0, N - 1);

  while (Q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    PII r = query(1, 0, N - 1, a, b);

    cout << r.first << " " << r.second << "\n";
  }

  return 0;
}
