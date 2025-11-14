#include <iostream>
#include <vector>
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
using namespace std;
// 11094번 문제.
	// 헷갈림
	// cin.ignore
	// getline
	// stringstream


int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 4;
	
	vector <int> numOfPeople(N);

	int in;
	int out;
	int num = 0;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> out >> in;
		num -= out;
		num += in;
		if (num > max)
		{
			max = num;
		}
	}

	cout << max;

	return 0;
}