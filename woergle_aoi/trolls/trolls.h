#pragma once

#include <vector>

struct Troll
{
    int s;
    int h;
};

struct Query
{
    int k;
    int d;
};

std::vector<int> simulateAttacks(std::vector<Troll> trolls, std::vector<Query> queries);