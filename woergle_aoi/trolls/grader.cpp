#include "trolls.h"

#include <iostream>
#include <vector>
#include <cassert>

std::vector<Troll> trolls;
std::vector<Query> queries;

int main()
{
    std::ios::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> unlinked;
    for (int i = 0; i < N; i++)
    {
        int s, h;
        std::cin >> s >> h;
        trolls.push_back({.s = s, .h = h});
    }

    for (int i = 0; i < Q; i++)
    {
        int k, d;
        std::cin >> k >> d;
        queries.push_back({.k = k, .d = d});
    }

    std::vector<int> results = simulateAttacks(trolls, queries);

    for (auto r : results)
        std::cout << r << "\n";
}
