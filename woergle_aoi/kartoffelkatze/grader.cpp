#include "potato.h"
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::pair<int, int> georg, kartoffelkatze;
    int n;
    std::cin >> georg.first >> georg.second >> kartoffelkatze.first >> kartoffelkatze.second >> n;
    std::vector<std::pair<int, int>> hindernisse(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> hindernisse[i].first >> hindernisse[i].second;
    }
    
    std::string moves = find_potatocat(georg, kartoffelkatze, hindernisse);

    if (moves.size()) {
        std::cout << moves << "\n";
    } else {
        std::cout << "" << "\n";
    }
}