#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[2001];

int dfs(int s) {
  int max = 0;
  for (auto p : adj[s]) {
    max = std::max(max, dfs(p) + 1);
  }
  return max;
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    if (p != -1)
      adj[p].push_back(i);
    else
      adj[0].push_back(i);
  }

  cout << dfs(0);
}
