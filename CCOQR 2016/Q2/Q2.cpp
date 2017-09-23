// Q2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int getIndexToMe(vector<vector<pair<int, int>>> rooms, int start, int end)
{
	for (int i = 0; i < rooms[end].size(); ++i)
	{
		if (rooms[end][i].first == start)
			return i;
	}
	return -1;
}

int solve(vector<vector<pair<int, int>>> rooms, int start, int end)
{
	//cout << "Solving..." << endl;

	if (start == end) return 0;

	int currCorridor = getIndexToMe(rooms, end, start);
	int currRoom = start;
	int num = 0;
	while (currRoom != end)
	{
		// Move
		int nextCorridor = currCorridor + 1;
		if (nextCorridor == rooms[currRoom].size())
			nextCorridor = 0;

		num++;
		auto nextRoom = rooms[currRoom][nextCorridor].first;
		currCorridor = rooms[currRoom][nextCorridor].second;
		if (currCorridor == -1)
		{
			rooms[currRoom][nextCorridor].second = getIndexToMe(rooms, currRoom, nextRoom);
			currCorridor = rooms[currRoom][nextCorridor].second;
		}
		currRoom = nextRoom;

		//cout << "Num: " << num << endl;
	}

	return num;
}

int main()
{
	int N;
	cin >> N;

	// First is self, second is dest
	vector<vector<pair<int, int>>> rooms(N);

	for (int i = 0; i < rooms.size(); ++i)
	{
		int k;
		cin >> k;
		rooms[i].resize(k);

		for (auto& c : rooms[i])
		{
			cin >> c.first;
			c.first -= 1;
			c.second = -1;
		}
	}

	int Q;
	cin >> Q;
	vector<int> ans(Q);
	for (auto& a : ans)
	{
		int start;
		cin >> start;
		start -= 1;
		a = 0;
		for (int i = 0; i < rooms[start].size(); ++i) // Loop through corridors
		{
			a = max(a, solve(rooms, rooms[start][i].first, start) + 1);
		}
	}

	for (int i = 0; i < ans.size() - 1; ++i)
	{
		cout << ans[i] << endl;
	}
	cout << ans.back();

	//system("PAUSE");
    return 0;
}

