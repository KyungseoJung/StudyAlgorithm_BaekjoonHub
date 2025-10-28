#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 2592번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int num = 10;
	vector <int> nums(num);
	int input;
	int sum = 0;

	vector <int> counting(101,0);	
	// 첫 element 들은 모두 0으로 설정. 각각의 숫자가 몇 번 언급되었는지 카운팅 목적
	// 1부터 100까지 들어가도록 (각각의 숫자는 10의 n배수를 의미함)
	// 1이라면 10의 1배수인 10. 9라면 10의 9배수인 90
	for (int i = 0; i < num; i++)
	{
		cin >> input;
		nums[i] = input;
		counting[input / 10] += 1;

		sum += input;	// 평균을 계산하기 위한 숫자의 총합 계산
	}

	int mean = sum / num;
	int maxCounting = 0;
	int rememberEle = 0;
	for (int i = 1; i < counting.size(); i++)
	{
		if (counting[i] > maxCounting)
		{
			maxCounting = counting[i];
			rememberEle = i;
		}
	}
	int mode = rememberEle * 10;

	cout << mean << "\n" << mode;


	return 0;
}