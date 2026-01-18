#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  while(t--) {
    int n, s, r;

    cin >> n >> s >> r;

    cout << s-r << " ";

    int average = r / (n-1);
    int diff = (s-r) - average;
    int los = r - (average * (n-1));

    int max;
    if(diff != 0) { max = los / diff; } else { max = 0;}

    for(int i = 0; i < n-2; i++) {
      if(i < max) {
        cout << average + diff << " ";
        r -= average + diff;
      } else {
        cout << average << " ";
        r -= average;
      }
    }

    cout << r << "\n";
  }
}
