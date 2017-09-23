// S5.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;


struct coord
{
	coord() {}
	coord(int _x, int _y) : x(_x), y(_y) {}
	int x, y;
};

int dist(coord& c1, coord& c2)
{
	return (c1.x - c2.x)*(c1.x - c2.x) + (c1.y - c2.y)*(c1.y - c2.y);
}

struct Packet
{
	Packet() {}
	Packet(int _x, int _y, int _d) : x(_x), y(_y), lastDistance(_d) {}
	int x, y, lastDistance;

	bool operator == (const Packet& p) const
	{
		return x == p.x && y == p.y && lastDistance == p.lastDistance;
	}
};

struct packethash
{
	size_t operator()(const Packet& p) const
	{
		return hash<int>()(p.x) ^ hash<int>()(p.y) ^ hash<int>()(p.lastDistance);
	}
};


unordered_map<Packet, int, packethash> res;
int maxTreats(vector<coord>& v, Packet&& p)
{
	if (res[p]) return res[p];

	coord lastSpot(p.x, p.y);
	int lastDistance = p.lastDistance;
	int treats = 0;
	for (auto& c : v)
	{
		int d = dist(c, lastSpot);
		if (d < lastDistance || lastDistance == -1)
			treats = max(treats, 1 + maxTreats(v, Packet(c.x, c.y, d)));
	}
	return treats;
}

int main(int argc, char** argv)
{
	int N;
	cin >> N;

	vector<coord> coords(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> coords[i].x >> coords[i].y;
	}

	cout << maxTreats(coords, Packet(0, 0, -1)) - 1;

    return 0;
}

