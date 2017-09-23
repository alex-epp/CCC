// S2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cstring> // for memset
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

void pause()
{
#if defined(_MSC_VER)
	system("PAUSE");
#endif
}

map<string, string> cache;
void solve(string* c, string* a, int N)
{
	if (cache[*c] != "")
	{
		auto t = a;
		*a = cache[*c];
		c = t;
	}
	// Handle the first and last characters differently
	if (c->at(N - 1) != c->at(1) && (c->at(1) == '1' || c->at(N - 1) == '1'))
		a->at(0) = '1';
	else
		a->at(0) = '0';

	if (c->at(N - 2) != c->at(0) && (c->at(0) == '1' || c->at(N - 2) == '1'))
		a->at(N - 1) = '1';
	else
		a->at(N - 1) = '0';


	// Loop through the rest
	for (int j = 1; j < c->size() - 1; ++j)
	{
		if (c->at(j - 1) != c->at(j + 1) && (c->at(j - 1) == '1' || c->at(j + 1) == '1'))
			a->at(j) = '1';
		else
			a->at(j) = '0';
	}
	cache[*c] = *a;
}

int main()
{
	int N, T;
	cin >> N >> T;

	string strip;
	cin >> strip;
	string other = strip;

	string* c = &strip;
	string* a = &other;

	// Solve
	for (int i = 0; i < T; ++i)
	{
		solve(c, a, N);
		swap(c, a);
	}
	cout << *c;

	pause();
	return 0;
}