#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int n;
  freopen("blocks.in", "r", stdin);
  cin >> n;
  vector<int> l(26, 0);
  string a, b;
  for (int i = 0; i < n; i++) {
    vector<int> al(26);
    vector<int> bl(26);
    cin >> a >> b;
    for (char e : a) {
      al[e - 97]++;
    }
    for (char e : b) {
      bl[e - 97]++;
    }
    for (int j = 0; j < 26; j++) {
      l[j] += max(al[j], bl[j]);
    }
  }
  freopen("blocks.out", "w", stdout);
  for (int i = 0; i < 26; i++) {
    cout << l[i] << "\n";
  }
}
