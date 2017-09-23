// S3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	vector<char> res;

	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;

		int next = 1;
		deque<int> branch;

		vector<int> cars(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> cars[N - i - 1];
		}

		bool failed = false;
		for (int i = 0; i < N; ++i)
		{
			int C = cars[i];

			if (failed) break;

			// Try from branch
			while (branch.size() != 0 && branch.front() == next)
			{
				branch.pop_front();
				++next;
			}

			if (C == next)
				++next;	// Success
			else if (branch.empty())
				branch.emplace_front(C);	// Put in branch
			else if (C < branch.front())
				branch.emplace_front(C);	// Put in branch
			else
			{
				failed = true;
			}
		}
			
		if (failed) res.emplace_back('N');
		else res.emplace_back('Y');

	}
	
	for (int i = 0; i < (res.size() - 1); ++i)
		cout << res[i] << endl;
	cout << res.back();

    return 0;
}

