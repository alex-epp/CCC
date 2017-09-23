// S1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cstring> // for memset
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

void pause()
{
#if defined(_MSC_VER)
	system("PAUSE");
#endif
}


int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i < s1.length(); ++i)
	{
		char c = s1[i]; // Find c
		auto pos = s2.find_first_of(c);
		if (pos == std::string::npos) pos = s2.find_first_of('*');
		if (pos == std::string::npos)
		{
			cout << "N";
			return 0;
		}
		else
		{
			s2.erase(pos, 1);
		}
	}

	cout << "A";
    return 0;
}

