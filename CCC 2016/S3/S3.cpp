// S3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cstring> // for memset
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <climits>
#include <queue>

using namespace std;

void pause()
{
#if defined(_MSC_VER)
	system("PAUSE");
#endif
}

struct Resturaunt
{
	bool pho;
	bool visited;

	vector<int> paths;

	Resturaunt() : pho(false), visited(false) {}
};

struct Solution
{
	int distance;
	int numPho;
	int current;
	vector<int> visited;
};


bool operator < (const Solution& lhs, const Solution& rhs) 
{
	return (lhs.distance > rhs.distance ? true : (lhs.distance == rhs.distance ? (lhs.numPho > rhs.numPho) : false));
}

int solve(vector<Resturaunt> v, int start, int maxPho)
{
	priority_queue<Solution> q;
	Solution s;
	s.distance = 0;
	s.numPho = 1;
	s.visited.resize(v.size());
	s.current = start;
	s.visited[s.current] = 1;
	q.emplace(s);

	if (s.numPho == maxPho)
	{
		return s.distance;
	}

	int count = 0;
	while (!q.empty())
	{
		Solution s = q.top();
		q.pop();
		
		for (int i = 0; i < v[s.current].paths.size(); ++i)
		{
			if (s.visited[s.current] > 2) continue;
			Solution ss = s;
			ss.current = v[s.current].paths[i];
			ss.distance = s.distance + 1;
			ss.numPho += (v[ss.current].pho && !ss.visited[ss.current] ? 1 : 0);
			ss.visited[ss.current]++;
			q.push(ss);

			if (s.numPho == maxPho)
			{
				return s.distance;
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;

	vector<Resturaunt> v(N);
	vector<int> pho(M);
	for (int i = 0; i < M; ++i)
	{
		int p;
		cin >> p;
		v[p].pho = true;
		pho[i] = p;
	}
	
	for (int i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a].paths.emplace_back(b);
		v[b].paths.emplace_back(a);
	}

	int re = INT_MAX - 1;
	for (int i = 0; i < pho.size(); ++i)
	{
		re = min(re, solve(v, pho[i], pho.size()));
	}
	cout << re;
	pause();
	return 0;
}

