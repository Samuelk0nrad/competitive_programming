// basic O(n*q) solution that performs a bfs for each query
#include <iostream>
#include <vector>
#include <utility>
#include "zug2.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n;
	vector<pair<int, int>> nodes(n - 3);
	for (int i = 0; i < n - 3; ++i)
	{
		int u, v;
		cin >> u >> v;
		nodes[i] = {u, v};
	}
	init(n, nodes);

	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		int s, t;
		cin >> s >> t;
		cout << calculate(s, t) << '\n';
	}
}