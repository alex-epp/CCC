

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
#include <functional>

using namespace std;

void pause()
{
#if defined(_MSC_VER)
	system("PAUSE");
#endif
}


int main()
{
	int Question;
	cin >> Question;

	int N;
	cin >> N;

	vector<int> Dm(N);
	for (auto& d : Dm)
		cin >> d;

	vector<int> Pe(N);
	for (auto& p : Pe)
		cin >> p;

	if (Question == 1)
	{
		// If question 1 is asked, we find the minimum. That is, the fastest are paired w/ the fastest, and vice versa
		// This makes the speed difference negligible
		sort(Dm.begin(), Dm.end());
		sort(Pe.begin(), Pe.end());

	}
	else
	{
		// If question 2, we must maximize the differences
		sort(Dm.begin(), Dm.end());
		sort(Pe.begin(), Pe.end(), greater<int>());
	}
	int total = 0;
	for (int i = 0; i < N; ++i)
	{
		total += max(Dm[i], Pe[i]);
	}
	cout << total;

	pause();
	return 0;
}

