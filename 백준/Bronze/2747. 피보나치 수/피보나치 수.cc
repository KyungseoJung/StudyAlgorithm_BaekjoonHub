#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isupper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#25757번 문제

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector <int> nums(N+1);
	nums[0] = 0;
	nums[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		nums[i] = nums[i - 2] + nums[i - 1];
	}

	cout << nums[N];
	return 0;

}
