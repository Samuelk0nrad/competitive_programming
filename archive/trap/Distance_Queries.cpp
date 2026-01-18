#include <bits/stdc++.h>
#include <vector>

using namespace std;
const int MAXP = 18;
int n;

vector<vector<int>> t;
vector<int> depth;

int main() {
  int q;
  cin >> n >> q;
  t.assign(MAXP, vector<int>(n + 1, 0));
  depth.assign(n + 2, 0);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    t[]
  }
}
