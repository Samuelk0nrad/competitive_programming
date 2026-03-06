#include <algorithm>
#include <iostream>
#include <set>
#include "kerker.h"

using namespace std;

static int cnt;

std::vector<int> mark_lock(const std::vector<int> &q)
{
	cnt++;
	cout << "?";
	for (const int a : q)
	{
		cout << " " << a;
	}
	cout << endl;

	vector<int> answ(q.size());
	for (int &a : answ)
	{
		cin >> a;
	}
	return answ;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr = find_combination(n);
	cout << "!";
	for (const int a : arr)
	{
		cout << " " << a;
	}
	cout << endl;
	cout << "Number of queries:" << cnt << endl;
}
