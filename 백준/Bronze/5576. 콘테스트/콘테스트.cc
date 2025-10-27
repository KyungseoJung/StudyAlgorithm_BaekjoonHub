#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#2460번 문제
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int num1 = 10;
	vector <int> scores1(num1);
	int num2 = 10;
	vector <int> scores2(num1);

	int input;
	for (int i = 0; i < num1; i++)
	{
		cin >> input;
		scores1[i] = input;
	}
	sort(scores1.begin(), scores1.end());

	for (int i = 0; i < num2; i++)
	{
		cin >> input;
		scores2[i] = input;
	}
	sort(scores2.begin(), scores2.end());

	int sum1 = 0;
	for (int i = num1 - 3; i < num1; i++)
	{
		sum1 += scores1[i];
	}

	int sum2 = 0;
	for (int i = num2 - 3; i < num2; i++)
	{
		sum2 += scores2[i];
	}

	cout << sum1 << " " << sum2;

	return 0;
}
