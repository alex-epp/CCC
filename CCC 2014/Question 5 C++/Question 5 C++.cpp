// Question 5 C++.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;


int get_max_treats(int curr_node, float max_distance)
{
	static map<std::tuple<int, float>, int> cache;
	if (cache.find(std::tuple<int, float>(curr_node, max_distance)) != cache.end())
	{
		return cache[std::tuple<int, float>(curr_node, max_distance)];
	}
	auto max_treats = 0;
	for (auto i = 0; i < N; ++i)
	{
		if (i == curr_node)
			continue;

		if (node_array[i][curr_node] < max_distance || max_distance == -1)
		{
			max_treats = max(max_treats, get_max_treats(i, node_array[i][curr_node]) + 1);
		}
	}
	cache[std::tuple<int, float>(curr_node, max_distance)] = max_treats;
	return max_treats;
}



template <typename T>
T distance2(vector<T> p1, vector<T> p2)
{
	return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])
}
	
int main(int argc, char *argv[])
{
	int N;
	float x, y;
	cin >> N;
	vector<vector<float>> coords(N, { 0, 0 });
	for (auto &coord : coords)
	{
		cin >> x >> y;
		coord = { x, y };
	}

	// Construct a node array
	// Which, for any two node indices, stores the distance
	vector<vector<float>> node_array(N, vector<float>(N, 0));
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = i + 1; j < N; ++j)
		{
			node_array[i][j] = distance2(coords[i], coords[j]);
			node_array[j][i] = node_array[i][j];
		}
	}

	auto max_treats = 0;
	for (auto i = 0; i < N; ++i)
	{
		max_treats = max(max_treats, get_max_treats(i, -1));
	}
}
