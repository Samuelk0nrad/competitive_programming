#include <iostream>

using namespace std;

int main() {
  int n = 0;
  string s = "";
  cin >> n >> s;
  char last = ' ';
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == last) {
      res++;
    } else {
      last = s[i];
    }
  }
  cout << res;
}
