#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

int main() {
  int w = 0;
  cin >> w;
  if (w <= 2) {
    cout << "NO";
  } else if (w % 2) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
