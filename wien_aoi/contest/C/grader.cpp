#include <bits/stdc++.h>
#include "grf.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> smaller(n), larger(n);
    for (int i = 0; i < n; i++) cin >> smaller[i];
    for (int i = 0; i < n; i++) cin >> larger[i];
    int solution = solve(n, smaller, larger);
    cout << solution << endl;
    return 0;
}

