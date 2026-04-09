#include "kcolor.h"
#include <iostream>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    std::vector<bool> mayBeBlack(n);
    std::vector<pair<int, int>> edges(m);

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        mayBeBlack[i] = tmp;
    }

    for (auto &[a, b] : edges)
    {
        cin >> a >> b;
    }

    cout << calculate_colorings(n, k, edges, mayBeBlack);
    return 0;
}