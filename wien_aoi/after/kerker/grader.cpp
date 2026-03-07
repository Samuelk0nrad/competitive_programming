#include "kerker.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

static int cnt;

vector<int> res;

std::vector<int> mark_lock(const std::vector<int> &q) {
  cnt++;
  cout << "?";
  for (const int a : q) {
    cout << " " << a;
  }

  vector<int> answ(q.size());
  for (int i = 0; i < q.size(); i++) {
    answ[i] = res[q[i] - 1];
  }
  random_device rd;
  mt19937 gen{rd()};
  // shuffle(answ.begin(), answ.end(), gen);

  cout << " :";

  for (const int a : answ) {
    cout << " " << a;
  }

  cout << endl;
  return answ;
}

int main() {
  int n;
  cin >> n;
  res.resize(n);
  for (int i = 0; i < n; i++) {
    // cin >> res[i];
    res[i] = i + 1;
  }
  // mark_lock({1, 2});

  vector<int> arr = find_combination(n);
  cout << "!";
  for (const int a : arr) {
    cout << " " << a;
  }
  cout << endl;
  cout << "Number of queries:" << cnt << endl;
}
