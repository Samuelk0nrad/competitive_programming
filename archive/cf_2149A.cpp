#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;

    int res = 0;
    int minus = 0;
    for(int i = 0; i < n; ++i) {
      int e;
      cin >> e;
      if(e == 0) res++;
      else if(e == -1) minus++;
    }

    if(minus%2) res += 2;

    cout << res << "\n";
  }
}
