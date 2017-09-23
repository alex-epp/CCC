// S4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cstring> // for memset
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <list>

using namespace std;

void pause()
{
#if defined(_MSC_VER)
	system("PAUSE");
#endif
}

struct RiceBall
{
	RiceBall* right;
	int size;
};

int solve(RiceBall* r)
{
	bool processed = false;
	// First test
	int re = 0;
	auto curr = r;
	while (curr->right->right != nullptr)
	{
		if (curr->size == curr->right->size)
		{
			int st = curr->size;
			int sum = curr->size * 2;
			auto rt = curr->right;
			curr->size = sum;
			curr->right = curr->right->right;
			re = max(solve(r), re);
			curr->size = st;
			curr->right = rt;

			processed = true;
		}
		curr = curr->right;
	}
	curr = r;
	while (curr->right->right->right != nullptr)
	{
		if (curr->size == curr->right->right->size)
		{
			int st = curr->size;
			int sum = curr->size * 2 + curr->right->size;
			auto rt = curr->right;
			curr->size = sum;
			curr->right = curr->right->right->right;
			re = max(solve(r), re);
			curr->size = st;
			curr->right = rt;

			processed = true;
		}
		curr = curr->right;
	}
	
	if (!processed)
	{
		curr = r;
		while (curr != nullptr)
		{
			re = max(re, curr->size);
			curr = curr->right;
		}
	}
	return re;
}

int main()
{
	int N;
	cin >> N;

	RiceBall* r = new RiceBall();
	RiceBall* t = r;
	for (int i = 0; i < N; ++i)
	{
		cin >> t->size;
		t->right = new RiceBall();
		t = t->right;
	}
	delete t->right;
	t->right = nullptr;

	cout << solve(r);

	pause();
	return 0;
}

