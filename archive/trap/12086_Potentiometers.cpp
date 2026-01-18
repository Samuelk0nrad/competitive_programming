// https://onlinejudge.org/external/120/12086.pdf
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int n;
vector<int> st;

void build(int p, int L, int R, vector<int> &x) {
  if (L == R - 1) {
    st[p] = x[L];
  } else {
    build(2 * p + 1, L, (R + L) / 2, x);
    build(2 * p + 2, (L + R) / 2, R, x);
    st[p] = st[2 * p + 1] + st[2 * p + 2];
  }
}

int query(int p, int L, int R, int i, int j) {
  if (i <= L && j >= R) {
    return st[p];
  } else if (i >= R || j <= L) {
    return 0;
  }
  return query(2 * p + 1, L, (L + R) / 2, i, j) +
         query(2 * p + 2, (L + R) / 2, R, i, j);
}

void update(int p, int L, int R, int i, int x) {
  if (L == R - 1) {
    if (L == i) {
      st[p] = x;
    }
    return;
  }
  if (L > i || R <= i) {
    return;
  }
  update(2 * p + 1, L, (L + R) / 2, i, x);
  update(2 * p + 2, (L + R) / 2, R, i, x);
  st[p] = st[2 * p + 1] + st[2 * p + 2];
}

void solve(int n) {
  vector<int> x(n);
  st.assign(4 * n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  build(0, 0, n, x);

  while (true) {
    string o;
    cin >> o;
    if (o == "END")
      break;
    int x, y;
    cin >> x >> y;
    if (o == "M") {
      int res = query(0, 0, n, x - 1, y);
      cout << res << "\n";
    } else {
      update(0, 0, n, x - 1, y);
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int t = 1;
  while (true) {
    cin >> n;
    if (n == 0)
      break;
    else if (t != 1) {
      cout << "\n";
    }
    cout << "Case " << t << ":\n";
    solve(n);
    t++;
  }
}
