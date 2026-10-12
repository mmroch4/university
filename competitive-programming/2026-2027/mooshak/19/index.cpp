#include <bits/stdc++.h>

using namespace std;

bool DEBUG_MODE = false;

// #1's, interval range, switches to propagate [3]
typedef vector<int> SEGTREE_VALUE;
#define SEGTREE_QUERY_NEUTRAL 0
#define SEGTREE_INITIAL_VALUE {0, 1, 0}

vector<int> values;
vector<SEGTREE_VALUE> segtree;

SEGTREE_VALUE merge(SEGTREE_VALUE& a, SEGTREE_VALUE& b) {
    return {a[0] + b[0], a[1] + b[1], 0};
}

// NOTA: CRIADO COM IA PARA FAZER DEBUGGING
void draw_segtree(int P, int L, int R) {
    auto label = [&](int p, int l, int r) {
        string s = "[" + to_string(l) + (l == r ? "" : "," + to_string(r)) + "]{";
        for (int i = 0; i < (int)segtree[p].size(); i++) {
            s += (i ? "," : "") + to_string(segtree[p][i]);
        }
        return s + "}";
    };

    // cada node com flag de propagacao = 1 ganha uma cor propria (pastel, sempre diferente)
    int flagCount = 0;
    auto nextColor = [&]() {
        double h = fmod(flagCount++ * 0.61803398875, 1.0), s = 0.5, v = 0.95;
        double c = v * s, x = c * (1 - fabs(fmod(h * 6, 2) - 1)), m = v - c;
        double rr = 0, gg = 0, bb = 0;
        int sector = (int)(h * 6);
        if (sector == 0) { rr = c; gg = x; }
        else if (sector == 1) { rr = x; gg = c; }
        else if (sector == 2) { gg = c; bb = x; }
        else if (sector == 3) { gg = x; bb = c; }
        else if (sector == 4) { rr = x; bb = c; }
        else { rr = c; bb = x; }
        return array<int, 3>{(int)((rr + m) * 255), (int)((gg + m) * 255), (int)((bb + m) * 255)};
    };

    int W = 0, D = 0;
    function<void(int, int, int, int)> scan = [&](int p, int l, int r, int d) {
        W = max(W, (int)label(p, l, r).size());
        D = max(D, d);
        if (l == r) return;
        int m = l + (r - l) / 2;
        scan(2 * p, l, m, d + 1);
        scan(2 * p + 1, m + 1, r, d + 1);
    };
    scan(P, L, R, 0);
    W += 2;

    int cols = (R - L + 2) * W;
    vector<vector<string>> g(2 * D + 1, vector<string>(cols, " "));
    int leaves = 0;

    function<int(int, int, int, int, vector<array<int, 3>>)> place =
        [&](int p, int l, int r, int d, vector<array<int, 3>> inherited) -> int {
        if (segtree[p].size() > 2 && segtree[p][2] == 1) inherited.push_back(nextColor());

        int x;
        if (l == r) {
            x = leaves * W + W / 2;
            leaves++;
        } else {
            int m = l + (r - l) / 2;
            int lx = place(2 * p, l, m, d + 1, inherited);
            int rx = place(2 * p + 1, m + 1, r, d + 1, inherited);
            x = (lx + rx) / 2;
            for (int c = lx; c <= rx; c++) g[2 * d + 1][c] = "─";
            g[2 * d + 1][lx] = "┌";
            g[2 * d + 1][rx] = "┐";
            g[2 * d + 1][x] = "┴";
        }

        string s = label(p, l, r);
        int start = max(0, x - (int)s.size() / 2);
        string pre = "", post = "";
        if (!inherited.empty()) {
            // cores que colidem sao misturadas com transparencia (media), assim todas continuam visiveis
            int cr = 0, cg = 0, cb = 0;
            for (auto& c : inherited) { cr += c[0]; cg += c[1]; cb += c[2]; }
            int n = inherited.size();
            pre = "\033[48;2;" + to_string(cr / n) + ";" + to_string(cg / n) + ";" + to_string(cb / n) + "m\033[30m";
            post = "\033[0m";
        }
        for (int i = 0; i < (int)s.size(); i++) {
            g[2 * d][start + i] = (i == 0 ? pre : "") + string(1, s[i]) + (i + 1 == (int)s.size() ? post : "");
        }
        return x;
    };
    place(P, L, R, 0, {});

    for (auto& row : g) {
        int last = cols - 1;
        while (last >= 0 && row[last] == " ") last--;
        if (last < 0) continue;
        for (int c = 0; c <= last; c++) cout << row[c];
        cout << "\n";
    }
}

void rotate(int p) {
    segtree[p][0] = segtree[p][1] - segtree[p][0];
    segtree[p][2] = (segtree[p][2] + 1) % 2;
}

void propagate(int p, int l, int r) {
    if (segtree[p][2] == 0) return;

    if (l == r) return;
    
    int m = l + (r - l) / 2;

    rotate(2 * p);
    // folhas não devem propagar
    if (l == m) {
        segtree[2 * p][2] = 0;
    }
    
    rotate(2 * p + 1);

    if (m + 1 == r) {
        segtree[2 * p + 1][2] = 0;        
    }

    segtree[p][2] = 0;
}

int query(int p, int l, int r, int a, int b) {
  if (r < a || b < l) {
    return SEGTREE_QUERY_NEUTRAL;
  }

  if (a <= l && r <= b) {
    return segtree[p][0];
  }

  int m = l + (r - l) / 2;

  propagate(p, l, r);

  return query(2 * p, l, m, a, b) + query(2 * p + 1, m + 1, r, a, b);
}

void build(int p, int l, int r) {
    if (l == r) {
        segtree[p] = SEGTREE_INITIAL_VALUE;
        return;
    }

    int m = l + (r - l) / 2;
    
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);

    segtree[p] = merge(segtree[2 * p], segtree[2 * p + 1]);
}

void update(int p, int l, int r, int a, int b) {
    // apenas nos nodes finais que eu faço switch.
    // nos outros eu apenas faço o merge dos nodes
    
    if (r < a || b < l) {
      return;
    }

    if (a <= l && r <= b) {
        rotate(p);
        return;
    }

    propagate(p, l, r);

    int m = l + (r - l) / 2;

    update(2 * p, l, m, a, b);
    update(2 * p + 1, m + 1, r, a, b);

    segtree[p] = merge(segtree[2 * p], segtree[2 * p + 1]);
}

int main() {
  int N, M;
  cin >> N >> M;

  segtree.resize(4 * N);

  build(1, 0, N - 1);

  if (DEBUG_MODE) {
  cout << "INITIAL SEGTREE:\n";
  draw_segtree(1, 0, N - 1);
  cout << "\n\n----\n\n";
  }

  while (M--) {
    int t, a, b;
    cin >> t >> a >> b;
    a--; b--;

    if (t == 0) {
        if (DEBUG_MODE) {
            cout << "UPDATE: " << a << " - " << b << "\n\n";
            cout << "before:\n\n";
            draw_segtree(1, 0, N - 1);
            cout << "\n\n";
        }
        
        update(1, 0, N - 1, a, b);

        if (DEBUG_MODE) {
            cout << "after:\n\n";
            draw_segtree(1, 0, N - 1);
            cout << "\n\n\n-------------\n\n\n";
        }
    }
    else {
        if (DEBUG_MODE) {
        cout << "QUERY: " << a << " - " << b << "\n\n";    
        }
        
        cout << query(1, 0, N - 1, a, b) << "\n";

        if (DEBUG_MODE) {
            
        cout << "\n\n\n-------------\n\n\n";
        }
    }

  }

  return 0;
}
