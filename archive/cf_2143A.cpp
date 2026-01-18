#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;

    vector<int> a;

    int max = 0;
    int maxpos = 0;

    for(int i = 0; i < n; i++) {
      int e;
      cin >> e;
      a.push_back(e);

      if(e > max){
        max = e;
        maxpos = i;
      }
    }

    int start = maxpos;
    int end = maxpos;

    int i = n -1;
    while(i > 1) {
      if(start > 0 && a[start-1] == i){
        start--;
      } else if(end < n && a[end+1] == i) {
        end++;
      } else {
        break;
      }
      i--;
    }

    if(i <= 1) {
      cout << "yes" << "\n";
    } else {
      cout << "no" << "\n";
    }
  }
}

