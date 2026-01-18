#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edge(m);
  multiset<int> nodes;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    edge[i] = {x, y};
    nodes.insert(y);
    nodes.insert(x);
  }
  bool reasonable = true;

  for (int i = 1; i <= n; i++) {
    if (nodes.count(i) <= 1)
      continue;
    // cout << i << endl;
    vector<int> node;
    for (int j = 0; j < m; j++) {
      if (edge[j].first == i) {
        node.push_back(edge[j].second);
        // cout << "n: " << edge[j].second << endl;
      } else if (edge[j].second == i) {
        node.push_back(edge[j].first);
        // cout << "n: " << edge[j].first << endl;
      }
    }
    for (int j = 0; j < node.size(); j++) {
      if (nodes.count(node[j]) <= 1) {
        reasonable = false;
        // cout << " j: " << node[j] << endl;
        continue;
      }
      // cout << "== j: " << j << " : " << node[j];
      for (int y = 0; y < node.size(); y++) {
        if (j == y)
          continue;
        else if (nodes.count(node[y]) <= 1) {
          reasonable = false;
          // cout << " y: " << node[y] << endl;
          continue;
        }
        // cout << "== y: " << y << " : " << node[y];
        bool exist = false;
        for (int e = 0; e < m; e++) {
          // cout << edge[e].first << " : " << edge[e].second << endl;
          if ((edge[e].first == node[j] && edge[e].second == node[y]) ||
              (edge[e].first == node[y] && edge[e].second == node[j])) {
            exist = true;
            break;
          }
        }
        if (!exist) {
          // cout << node[j] << " " << node[y] << endl;
          reasonable = false;
          break;
        }
      }
      if (!reasonable)
        break;
    }
    if (!reasonable)
      break;
  }
  cout << (reasonable ? "YES" : "NO");
}
