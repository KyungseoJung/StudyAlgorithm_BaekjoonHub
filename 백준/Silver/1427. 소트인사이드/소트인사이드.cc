#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>	// stoi 함수

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// string 입력
	string input;
	cin >> input;

	// 숫자로 따로 뽑아서 vector의 원소들로 넣기
	vector <int> nums(input.length());
	for (int i = 0; i < input.length(); i++)
	{
		//cout << nums[i] << " " << input[i] << "\n";
		// 각각의 원소의 type은 char이므로, stoi 사용은 적절하지 X
		nums[i] = input[i] - '0';
	}

	// 정렬
	sort(nums.begin(), nums.end());

	// 내림차순이므로, 정렬된 값의 역 순서로 출력
	for (int i = nums.size()-1 ; i >= 0; i--)
	{
		cout << nums[i];
	}

	return 0;
	
}
