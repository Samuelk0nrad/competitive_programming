#include <vector>
#ifdef EVAL
#include "mauer.h"
#else
#include "grader.cpp"
#endif

#include <iostream>

using namespace std;
vector<int> r;

void build(int n, vector<int> &towers, int bomb) {
  r.resize(n);
  vector<int> t = towers;
  int li = bomb - 1;
  int ri = bomb + 1;
  int c = 1;
  r[bomb] = 0;
  while (li >= 0 || ri < n) {
    if (ri < n && (li >= n || t[li] > t[ri])) {
      r[ri] = c;
      c++;
      ri++;
    } else if (li < n) {
      r[li] = c;
      c++;
      li--;
    } else {
      break;
    }
  }
}

std::vector<int> calculate(std::vector<int> towers, int bomb,
                           std::vector<query> queries) {
  int n = towers.size();
  vector<int> result;
  for (query q : queries) {
    if (q.type == ENHANCE) {
      int index = q.index;
      int rank = q.rank;
    } else if (q.type == CALCULATE) {
      int index = q.index;
      // TODO calculate the number of steps  here.
      if (bomb == 0) {
        result.push_back(index);
      } else if (bomb == n - 1) {
        result.push_back((n - 1) - index);
      } else {
        result.push_back(r[index]);
      }
    } else {
      cerr << "unknown query type\n";
      exit(1);
    }
  }
  return result;
}
