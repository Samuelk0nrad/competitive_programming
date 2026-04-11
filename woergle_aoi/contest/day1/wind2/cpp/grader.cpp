// DIESE DATEI NICHT BEARBEITEN
#include <iostream>
#include <vector>

#include "wind2.h"

using namespace std;


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> edges(m, vector<int>(3, 0));
	for (int i = 0; i < m; i++) {
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	}
	init(n, q, edges);
	int u, v, k;
	char c;
	for (int i = 0; i < q; i++) {
		cin >> c;
		cin >> u >> v >> k;
		if (c == 'q') 
			cout << query(u, v, k) << "\n"; 
		else
			insert(u, v, k);
	}
}
