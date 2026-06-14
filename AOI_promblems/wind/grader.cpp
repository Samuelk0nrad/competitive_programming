#include "wind.h"
#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int x1, y1, x2, y2, n;
    std::string s;
    std::cin >> x1 >> y1 >> x2 >> y2 >> n >> s;

    std::cout << calculate_days(x1, y1, x2, y2, n, s) << std::endl;
    return 0;
}