// S4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Pane
{
	int x1, y1, x2, y2, tint;
};

int main(int argc, char** argv)
{
	int N;
	cin >> N;

	int T;
	cin >> T;


	vector <Pane> panes(N);

	int xMax = 0, yMax = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> panes[i].x1 >> panes[i].y1
			>> panes[i].x2 >> panes[i].y2
			>> panes[i].tint;

		xMax = max(xMax, panes[i].x2);
		yMax = max(yMax, panes[i].y2);
	}


    return 0;
}

