#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수 목적
#include <string>	// stoi 함수 목적
#include <algorithm>	// sort, reverse 함수 목적

using namespace std;

long long int reverseNum(string st)
{
	int length = st.length();
	reverse(st.begin(), st.end());

	//int iter = sqrt(length);
	//char temp;
	//for (int i = 0; i < iter; i++)
	//{
	//	temp = st[i];
	//	st[i] = st[length - 1 - i];
	//	st[length - 1 - i] = temp;
	//}

	return stoll(st);	// long long int를 반환해야 하므로 stoi는 적절하지 않대  stoi(st);
}

int main()
{
	int t;
	cin >> t;
	vector <string> input(t);
	vector <long long int> nums(t);
	for (int i = 0; i < t; i++)
	{
		cin >> input[i];

		//cout << reverseNum(input[i]) << "\n";
		nums[i] = reverseNum(input[i]);
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < t; i++)
	{
		cout << nums[i] << "\n";
	}
	
	return 0;
}