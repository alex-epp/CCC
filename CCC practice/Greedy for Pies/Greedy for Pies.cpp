// Greedy for Pies.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <cmath>
#include <cstring>

using namespace std;

void pause()
{
#if defined(_MSC_VER)
	system("PAUSE");
#endif
}

int cache[3000][100][100][2];

int maxSugar(vector<int>& N, vector<int>& M, int iN, int Mstart, int Mend, bool skip)
{
	int& re = cache[iN][Mstart][Mend][skip];
	if (re != -1)
		return re;

	re = 0;
	//if (skip)
	//{
		if (iN < N.size()) re = max(re, maxSugar(N, M, iN + 1, Mstart, Mend, false));
		if (Mstart <= Mend) re = max(re, maxSugar(N, M, iN, Mstart, Mend - 1, false));
	//}
	if (!skip)
	{
		if (iN < N.size()) re = max(re, N[iN] + maxSugar(N, M, iN + 1, Mstart, Mend, true));
		if (Mstart <= Mend) re = max(re, M[Mstart] + maxSugar(N, M, iN, Mstart + 1, Mend, true));
	}
		
	return re;
}

int main()
{
	memset(cache, -1, sizeof cache);

	int N;
	cin >> N;
	vector<int> vn(N);
	for (int i = 0; i < N; ++i)
		cin >> vn[i];

	int M;
	cin >> M;
	vector<int> vm(M);
	for (int i = 0; i < M; ++i)
		cin >> vm[i];

	sort(vm.begin(), vm.end(), std::greater<int>());

	cout << maxSugar(vn, vm, 0, 0, vm.size() - 1, false);

	pause();

	return 0;
}

