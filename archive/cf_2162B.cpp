#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t = 0;
  cin >> t;

  for(int i = 0; i < t; i++){

    int n = 0;
    cin >> n;

    string s;

    cin >> s;

    vector<int> pos;

    for(int i = 0; i < n; i++){
      if(s[i] == '1') pos.push_back(i+1);
    }

    cout << (int)pos.size() << "\n";

    for(auto& p : pos) cout << p << " ";

    cout << "\n";
  }
}
