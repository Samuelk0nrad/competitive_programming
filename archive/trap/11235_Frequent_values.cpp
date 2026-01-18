#include <bits/stdc++.h>
#include <vector>

using namespace std;
int n;

vector<int> freq;
vector<int> l;
vector<int> r;
vector<int> st;

void build(int p, int L, int R) {
  if (L == R - 1) {
    st[p] = freq[L];
    return;
  }
  build(2 * p + 1, L, (L + R) / 2);
  build(2 * p + 2, (L + R) / 2, R);
  st[p] = max(st[2 * p + 1], st[2 * p + 2]);
}

int query(int p, int L, int R, int i, int j) {
  if (L >= i && R <= j) {
    return st[p];
  }
  if (L >= j || R <= i) {
    return 0;
  }
  return max(query(2 * p + 1, L, (L + R) / 2, i, j),
             query(2 * p + 2, (L + R) / 2, R, i, j));
}

void solution() {
  int q;
  cin >> q;

  freq.assign(n, 0);
  l.assign(n, 0);
  r.assign(n, 0);
  st.assign(4 * n, 0);

  vector<int> a(n);
  int lv = 0;
  int li = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i == 0) {
      lv = a[i];
    }

    if (lv != a[i]) {
      int frequence = i - li;
      for (int j = li; j < i; ++j) {
        freq[j] = frequence;
        l[j] = li;
        r[j] = i - 1;
      }
      li = i;
      lv = a[i];
    }
  }

  int frequence = n - li;
  for (int j = li; j < n; ++j) {
    freq[j] = frequence;
    l[j] = li;
    r[j] = n - 1;
  }

  build(0, 0, n);

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x;
    if (x == 0)
      break;
    cin >> y;
    x--;
    y--;

    if (l[x] == l[y]) {
      cout << y - x + 1 << "\n";
    } else {
      int left = freq[x] - (x - l[x]);
      int middle = 0;
      if (r[x] + 1 <= l[y] - 1) {
        middle = query(0, 0, n, r[x] + 1, l[y]);
      }
      int maxv = max(left, middle);
      int right = freq[y] - (r[y] - y);
      maxv = max(maxv, right);

      cout << maxv << "\n";
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  while (true) {
    cin >> n;
    if (n == 0)
      break;
    solution();
  }
}
