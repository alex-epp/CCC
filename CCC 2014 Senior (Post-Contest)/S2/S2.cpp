// S2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int N;
	cin >> N;

	vector<string> v1(N), v2(N);

	for (int i = 0; i < N; ++i)
		cin >> v1[i];
	for (int i = 0; i < N; ++i)
		cin >> v2[i];

	bool bad = false;
	for (int i = 0; i < N && !bad; ++i)
	{
		if (v1[i] == v2[i])
		{
			bad = true;
			break;
		}
		for (int j = 0; j < N; ++j)
		{
			if ((v1[i] == v2[j]) != (v1[j] == v2[i]))
			{
				bad = true;
				break;
			}
		}
	}
	if (bad) cout << "bad";
	else cout << "good";

    return 0;
}

