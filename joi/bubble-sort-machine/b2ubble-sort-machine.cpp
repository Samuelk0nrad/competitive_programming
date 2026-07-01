#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> seg;
vector<int> a;
vector<int> tw;

void build(vector<int> &a, int p, int l, int r) {
  if (r - 1 == l) {
    seg[p] = a[l];
    return;
  }
  build(a, 2 * p, l, (r - l) / 2 + l);
  build(a, 2 * p + 1, (r - l) / 2 + l, r);
  seg[p] = seg[2 * p] + seg[2 * p + 1];
}

ll query(int p, int l, int r, int ql, int qr) {
  if (l >= ql && qr >= r) {
    return seg[p];
  }
  if (qr <= l || ql >= r) {
    return 0;
  }
  int ans = query(2 * p, l, (r - l) / 2 + l, ql, qr) +
            query(2 * p + 1, (r - l) / 2 + l, r, ql, qr);

  return ans;
}

int main() {
  int n;
  cin >> n;

  seg.resize(n * 4);
  a.resize(n + 5);
  tw.push_back(-1);
  int e;
  for (int i = 0; i < n; i++) {
    cin >> e;
    if (e == 1)
      e = 0;
    else {
      e = 1;
      tw.push_back(i);
    }
    a[i] = e;
  }
  build(a, 1, 0, n);

  int q;
  cin >> q;
  int bubble = 0;
  int tws = tw.size() - 1;
  int t, l, r;
  for (int i = 0; i < q; i++) {
    cin >> t;

    if (t == 1) {
      bubble++;
      if (bubble >= tws) {
        bubble = tws - 1;
      }
    } else if (t == 2) {
      cin >> l >> r;
      l = l - 1 + bubble;
      r = r + bubble;

      int t = 0;
      if (r > n) {
        if (l >= n) {
          cout << (r - l) * 2 << "\n";
          continue;
        }
        t = r - n;
        r = n;
      }

      int lt = tw[bubble];
      int o = 0;
      if (l <= lt) {
        if (r <= lt) {
          cout << (r - l) << "\n";
          continue;
        }
        o = lt + 1 - l;
        l = lt + 1;
      }

      ll ans = t * 2 + o;
      int rt = query(1, 0, n, l, r);
      ans += rt * 2;
      ans += (r - l) - rt;
      cout << ans << "\n";
    }
  }
}
