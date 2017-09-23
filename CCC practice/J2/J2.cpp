// J2.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

long long f(long long t, long long h)
{
	return t*t * (h*t - 6*t*t) + 2 * t*t + t;
}

int main(int argc, char** argv)
{
	int h, M;

	cin >> h >> M;

	for (int t = 1; t <= M; ++t)
	{
		if (f(t, h) <= 0)
		{
			cout << "The balloon first touches ground at hour:" << endl;
			cout << t;
			return 0;
		}
	}

	cout << "The balloon does not touch ground in the given time.";
	
    return 0;
}

