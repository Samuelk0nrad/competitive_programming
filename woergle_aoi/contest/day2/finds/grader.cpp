#include "find-scores.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

static const int MAX_N = 255;
static int n, hidden[MAX_N], num_queries;
static bool has[MAX_N];

int query1(int i) {
	num_queries++;
	assert(0 <= i && i < n);
	return hidden[i];
}

std::vector<int> query2(const std::vector<int>& is) {
	num_queries++;
	for (int i : is) {
		assert(0 <= i && i < n && !has[i]);
		has[i] = true;
	}
	int k = is.size();
	std::vector<int> ans;
	for (int i = 0; i < k; i++)
		for (int j = i+1; j < k; j++)
			ans.push_back(std::abs(hidden[is[i]] - hidden[is[j]]));
	std::sort(ans.begin(), ans.end());
	for (int i : is)
		has[i] = false;
	return ans;
}

int main()
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> hidden[i];
	for (int x : find_scores(n))
		std::cout << x << " ";
	std::cout << "\n";
	std::cout << "num queries: " << num_queries << "\n";
	return 0;
}
