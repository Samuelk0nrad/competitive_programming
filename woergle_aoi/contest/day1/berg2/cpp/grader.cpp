// DIESE DATEI NICHT BEARBEITEN
#include <iostream>
#include <vector>

#include "berg2.h"

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<pair<long, long>> intervals(n);
	for (int i = 0; i < n; i++) {
		cin >> intervals[i].first >> intervals[i].second;
	}
	int solution = calculate(intervals);
	cout << solution << endl;
	return 0;
}
