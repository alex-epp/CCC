
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

int cache[5000000];

int cmptCost(int c, int N)
{
	int& ret = cache[c - 1];
	if (ret != -1) return ret;

	if (c == 1) return ret = 0;

	ret = 1000000000;
	for (auto i = 1; i <= c / 2; ++i)
	{
		if ((i*c) % (i+1) == 0)
			ret = min(ret, cmptCost((i*c)/(i+1), N) + i);
	}

	return ret;
}

int main()
{
	memset(cache, -1, sizeof cache);

	int N;
	cin >> N;

	cout << cmptCost(N, N);

	pause();
	return 0;
}

