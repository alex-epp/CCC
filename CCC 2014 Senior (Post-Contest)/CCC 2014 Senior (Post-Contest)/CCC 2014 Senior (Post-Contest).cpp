// CCC 2014 Senior (Post-Contest).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char** argv)
{
	int K, m;
	

	cin >> K;
	cin >> m;


	vector <int> friends(K);

	for (int i = 0; i < K; ++i)
		friends[i] = i + 1;

	for (int i = 0; i < m; ++i)
	{
		int r;
		cin >> r;
		
		vector<int> t;
		for (int j = 0; j < K; ++j)
		{
			if ((j+1) % r != 0) t.emplace_back(friends[j]);
		}
		friends = t;
		K = friends.size();
	}

	for (int i = 0; i < friends.size() - 1; ++i)
		cout << friends[i] << endl;
	cout << friends.back();

    return 0;
}

