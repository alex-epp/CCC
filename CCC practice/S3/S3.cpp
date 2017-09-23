// S3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Reading
{
	int number;
	int frequency;

	bool operator > (Reading& rhs)
	{
		return frequency > rhs.frequency;
	}
};

int main()
{
	int N;
	cin >> N;
	
	int largest = 0, secondLargest = 0;
	vector<int> lIndexes, slIndexes;

	vector<int> frequencies(1000, 0); 
	for (int i = 0; i < N; ++i)
	{
		int R;
		cin >> R;
		frequencies[R]++;
		if (frequencies[R] > largest)
		{
			lIndexes = { R };
			largest = frequencies[R];
		}
		else if (frequencies[R] == largest)
		{
			lIndexes.emplace_back(R);
			largest = frequencies[R];
		}
		else if (frequencies[R] > secondLargest)
		{
			slIndexes = { R };
			secondLargest = frequencies[R];
		}
		else if (frequencies[R] == secondLargest)
		{
			slIndexes.emplace_back(R);
			secondLargest = frequencies[R];
		}
	}

	std::sort(slIndexes.begin(), slIndexes.end());
	std::sort(lIndexes.begin(), lIndexes.end());

	if (lIndexes.size() > 1)
	{
		cout << lIndexes.back() - lIndexes[0];
	}
	else if (slIndexes.size() > 1)
	{
		cout << max(abs(lIndexes[0] - slIndexes[0]), abs(lIndexes[0] - slIndexes.back()));
	}
	else
	{
		cout << abs(lIndexes[0] - slIndexes[0]);
	}

    return 0;
}

