#include <vector>

constexpr int ENHANCE=0;
constexpr int CALCULATE=1;

struct query
{
    int type;
    int index;
    int rank;
};

std::vector<int> calculate(std::vector<int> towers, int bomb, std::vector<query> queries);
