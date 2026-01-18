// https://onlinejudge.org/external/114/11402.pdf
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int n;
vector<int> st;
// 0: set to 0, 1: set to 1, 2: toggle (1-0, 0-1), -1: no lazy
vector<int> lazy;

void build(int p, int L, int R, vector<int> &a) {
  if (L == R - 1) {
    st[p] = a[L];
    return;
  }
  build(2 * p + 1, L, (L + R) / 2, a);
  build(2 * p + 2, (L + R) / 2, R, a);
  st[p] = st[2 * p + 1] + st[2 * p + 2];
}

int mergeLazy(int lazy, int s) {
  if (lazy == -1 || s != 2) {
    return s;
  } else if (lazy == 1) {
    return 0;
  } else if (lazy == 0) {
    return 1;
  } else {
    return -1;
  }
}

void propagate(int p, int L, int R) {
  if (lazy[p] != -1) {
    int s = lazy[p];
    lazy[p] = -1;
    if (s == 0) {
      st[p] = 0;
    } else if (s == 1) {
      st[p] = R - L;
    } else {
      st[p] = (R - L) - st[p];
    }

    if (L != R - 1) {
      int first = 2 * p + 1;
      lazy[first] = mergeLazy(lazy[first], s);
      int sec = 2 * p + 2;
      lazy[sec] = mergeLazy(lazy[sec], s);
    }
  }
}

int query(int p, int L, int R, int i, int j) {
  propagate(p, L, R);
  if (L >= i && R <= j) {
    return st[p];
  }
  if (L >= j || R <= i) {
    return 0;
  }
  return query(2 * p + 1, L, (L + R) / 2, i, j) +
         query(2 * p + 2, (L + R) / 2, R, i, j);
}

void update(int p, int L, int R, int i, int j, int s) {
  propagate(p, L, R);
  if (L >= i && R <= j) {
    lazy[p] = mergeLazy(lazy[p], s);
    propagate(p, L, R);
    return;
  }
  if (L >= j || R <= i)
    return;
  update(2 * p + 1, L, (L + R) / 2, i, j, s);
  update(2 * p + 2, (L + R) / 2, R, i, j, s);
  st[p] = st[2 * p + 1] + st[2 * p + 2];
}

void solve() {
  int m;
  n = 0;
  cin >> m;
  vector<string> s(m);
  vector<int> a;
  for (int i = 0; i < m; ++i) {
    int e;
    cin >> e >> s[i];
    n += e * s[i].size();
    vector<int> b;
    for (auto n : s[i]) {
      int e;
      if (n == '0')
        e = 0;
      else
        e = 1;
      b.push_back(e);
    }
    for (int j = 0; j < e; ++j) {
      a.insert(a.end(), b.begin(), b.end());
    }
  }

  st.assign(4 * n, 0);
  lazy.assign(4 * n, -1);
  build(0, 0, n, a);

  int q;
  cin >> q;
  int qc = 1;
  for (int i = 0; i < q; ++i) {
    int x, y;
    char s;
    cin >> s >> x >> y;
    if (s == 'F') {
      update(0, 0, n, x, y + 1, 1);
    } else if (s == 'E') {
      update(0, 0, n, x, y + 1, 0);
    } else if (s == 'I') {
      update(0, 0, n, x, y + 1, 2);
    } else if (s == 'S') {
      int res = query(0, 0, n, x, y + 1);
      cout << "Q" << qc << ": " << res << "\n";
      qc++;
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case " << i << ":\n";
    solve();
  }
}
