// S1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;

// Create a list of the inside edges grouped in pens
// Create a list of the outside edges, grouped in chains
// If there is only one chain, we must meet inside:
//    Break 1 inside edge per group
//    Break 1 outside edge
//    This is the minimum cost of meeting inside
// If there is more than one chain, meet outside:
//    Break 1 outside edge per chain
//    Break 1 edge per pen (excluding the outside edge/chain)

struct Pen
{
	vector<int> edges;
};

struct Edge
{
	int x1, y1, x2, y1;
	int cost;
	int numPens;
};


int main(int argc, char** argv)
{
	int M;
	cin >> M;

	vector<int> pens(M);
	
	map<Edge, int> edgeMap;



    return 0;
}

