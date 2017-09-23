#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;

	map<long long, vector<long long>> xs;
	map<long long, vector<long long>> ys;
	
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		xs[y].emplace_back(x);
		ys[x].emplace_back(y);
	}

	for (auto& v : xs) sort(v.second.begin(), v.second.end());
	for (auto& v : ys) sort(v.second.begin(), v.second.end());

	long long numBowties = 0;

	for (auto& v : xs)
	{
		auto y = v.first;
		if (v.second.size() < 3) continue; // Too small
		
		for (size_t i = 1; i < v.second.size() - 1; ++i)
		{
			auto x = v.second[i];

			if (ys[x].size() < 3) continue; // Too small
			
			auto yPos = find(ys[x].begin(), ys[x].end(), y);

			int xIndex = i; // The index in xs[y]
			int yIndex = ys[x].end() - yPos - 1; // The index in ys[x]
			
			numBowties += ((xIndex) * (xs[y].size() - xIndex - 1) * 
				(yIndex) * (ys[x].size() - yIndex - 1) * 2);
		}
	}

	cout << numBowties;
	return 0;
}