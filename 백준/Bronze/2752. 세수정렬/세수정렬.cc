#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수 목적
#include <string>	// stoi 함수 목적
#include <algorithm>	// sort, reverse 함수 목적

using namespace std;
int main()
{
	int t = 3;
	vector <int> nums(t);
	for (int i = 0; i < t; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	for (int i = 0; i < t; i++)
	{
		cout << nums[i] << " ";
	}

	return 0;

}