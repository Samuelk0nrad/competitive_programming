#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution() {
  int n, m;
  cin >> n >> m;
  vector<int> a;

  int max = 0, last = 0;
  bool md = false;

    for(int i = 0; i < m; i++) {
      cin >> last;
      a.push_back(last);

      if(i != 0){
        if(a[i-1] + 1 != last && last != 1){
          return 0;
        } else {
          if(max < last) {
            max = last;
          }
          else if(a[i-1] + 1 != last && last == 1) md = true;
        }
      }else max = last;
    }

    if(max > n) return 0;
    else if(md) return 1;
    else if(max == last && !md) {
      return n - max + 1;
    } else {
      return n - max;
    }
}

int main() {
  int t;
  cin >> t;

  while(t--) {
    cout << solution() << "\n";
  }
}
