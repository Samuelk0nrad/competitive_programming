// DIESE DATEI NICHT BEARBEITEN
#include <iostream>

#include "stocks.h"

using namespace std;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) cin >> prices[i];
	long long solution = calculate_max_profit(n, k, prices);
	cout << solution << endl;
	return 0;
}
