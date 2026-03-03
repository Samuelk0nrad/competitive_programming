#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct node {
  int i;
  int comp = -1;
  vector<int> e;
};

vector<node> a;

void dfs(int i, int comp) {
  vector<int> s;
  s.push_back(i);
  while (s.size() != 0) {
    int i = s[s.size() - 1];
    s.pop_back();
    for (int e : a[i].e) {
      if (a[e].comp == -1) {
        a[e].comp = comp;
        s.push_back(e);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  a.resize(n + 5);

  for (int i = 0; i < m; i++) {
    int o, b;
    cin >> o >> b;
    a[o].e.push_back(b);
    a[b].e.push_back(o);
  }

  int comp = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].comp == -1) {
      dfs(i, comp);
      comp++;
    }
  }
  cout << comp;
}
