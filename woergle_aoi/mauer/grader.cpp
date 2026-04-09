#include "mauer.h"

#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, bomb;
    cin >> n >> bomb;
    vector<int> towers(n);

    for (int &x : towers)
    {
        cin >> x;
    }

    cin >> q;
    std::vector<query> queries(q);
    for (query &qu : queries)
    {
        char c;
        cin >> c;

        if (c == 'E')
        {
            int i, e;
            cin >> i >> e;
            qu = {ENHANCE, i, e};
        }
        else if (c == 'C')
        {
            int b;
            cin >> b;
            qu = {CALCULATE, b, 0};
        }
        else
        {
            cerr << "expected Query to start with E or F\n";
            exit(1);
        }
    }

    auto results = calculate(towers, bomb, queries);
    for (int r : results)
    {
        cout << r << "\n";
    }
}
