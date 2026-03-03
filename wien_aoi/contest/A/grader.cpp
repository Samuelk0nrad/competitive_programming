// DIESE DATEI NICHT BEARBEITEN
#include <iostream>

#include "zugfahrt.h"

using namespace std;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, h;
	cin >> n >> m >> h;
	vector<int> a(m), b(m), w(m);
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> w[i];
	int minimum_length = find_path(n, m, h, a, b, w);
	cout << minimum_length << endl;
	return 0;
}
