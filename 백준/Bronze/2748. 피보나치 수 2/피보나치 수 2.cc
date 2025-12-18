#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 17413번 문제: 단어 뒤집기 2

int main()
{
	int n;
	cin >> n;

	vector <long long int> nums(n+1);	// 0부터 n까지 담을 수 있도록 vector 구성
	nums[0] = 0;
	nums[1] = 1;

	for (int i = 2; i <= n ; i++)
	{
		nums[i] = nums[i - 2] + nums[i - 1];
	}

	cout << nums[n];

	return 0;
}