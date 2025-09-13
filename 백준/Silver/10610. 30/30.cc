#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>	// stoi 함수 사용하기 위함

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 30의 배수이려면, (1) 마지막 숫자자리에 0이어야 하고, (2) 모든 숫자들의 합이 3의 배수여야 함
	string N;
	cin >> N;

	vector <int> nums(N.length());
	for (int i = 0; i < N.length(); i++)
	{
		nums[i] = N[i] - '0';
		// char 변수를 int로 저장하기 위함.
		// N[i]의 값들은 숫자의 아스키코드값을 갖고 있음. 따라서, '0'의 값을 빼주면 
		// 본래 갖고 있던 아스키코드값 - 0의 아스키코드값 = 해당 숫자// 얻을 수 있음.
	}

	sort(nums.begin(), nums.end());


	// 검사하기 (1) 첫 번째 자리가 0이어야 함. (sort 후에는 가장 작은 수부터 앞에 와있을테니까)
	if (nums[0] != 0)
	{
		cout << "-1";
		return 0;
	}
	// (2) 숫자들의 합이 3의 배수이어야 함.
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}
	if (sum % 3 != 0)
	{
		cout << "-1";
		return 0;
	}

	// 역으로 출력하기 (sort 후에는 가장 작은 수부터 앞에 와있을테니까)
	// 위 2가지 경우를 모두 통과한 것이면, 가장 큰 숫자 순서대로 정렬해서 나타난 숫자가 답임
	for (int i = nums.size() -1; i >=0 ; i--)
	{
		cout << nums[i];
	}
	return 0;
}