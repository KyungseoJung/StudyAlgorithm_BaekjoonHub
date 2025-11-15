#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isupper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#22233번 문제
// getline, stringstream, 
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int participant = 5;
	int num = 4;
	int sum;
	int max = 0;
	int input;
	int ele;
	for (int i = 0; i < participant; i++)
	{
		sum = 0;
		for (int j = 0; j < num; j++)
		{
			cin >> input;
			sum += input;
		}
		if (sum > max)
		{
			max = sum;
			ele = i + 1;
		}
	}
	cout << ele << " " << max;
	return 0;

}
