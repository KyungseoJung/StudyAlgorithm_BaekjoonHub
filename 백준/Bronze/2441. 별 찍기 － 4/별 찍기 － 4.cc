#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>	// #pow 사용
#include <string>	// # to_string 함수

using namespace std;
// 2441번 문제.

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		for (int j = i; j < N; j++)
		{
			cout << "*";
		}

		cout << "\n";
	}
    
    return 0;
}
