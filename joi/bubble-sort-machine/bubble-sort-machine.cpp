#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

vector<ll> a;
vector<ll> fen;
int n;

ll sum(int r) {
  ll sum = 0;
  for (int i = 0; i < 32; i++) {
    if (!(r & 1 << i)) {
      sum += fen[r];
      r -= 1 << i;
    }
    if (r < 0) {
      break;
    }
  }
  return sum;
}

ll query(int l, int r) { return sum(r) - sum(l - 1); }

void build(vector<ll> &a) {
  vector<ll> bit(35);
  for (int i = 0; i < n; i++) {
    bool ne = true;
    for (int j = 0; j < 32; j++) {
      if (!(i & 1 << j)) {
        bit[j] += a[i];
        if (ne) {
          ne = false;
          fen[i] = bit[j];
          bit[j] = 0;
        }
      }
    }
  }
}

void bubble() {
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      ll tmp = a[i];
      a[i] = a[i + 1];
      a[i + 1] = tmp;
    }
  }
  build(a);
}

int main() {
  cin >> n;

  a.resize(n);
  fen.resize(n + 5);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(a);

  int q;
  cin >> q;
  int t, l, r;
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      bubble();
    } else if (t == 2) {
      cin >> l >> r;
      cout << query(l - 1, r - 1) << "\n";
    }
  }
}

// 4
// 5 3 5 2
// 6
// 2 1 3
// 1
// 2 1 1
// 2 2 4
// 1
// 2 1 2
