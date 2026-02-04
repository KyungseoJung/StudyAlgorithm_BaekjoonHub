#include <iostream>

using namespace std;
// 1356번 문제: 유진수
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string N;
	cin >> N;
	long long int leftNum;
	long long int rightNum;
	if (N.length() == 1)
	{
		cout << "NO";
		return 0;
	}

	for (int i = 0; i < N.length(); i++)
	{
		leftNum = 1;
		rightNum = 1;

		for (int j = 0; j <= i; j++)
		{
			leftNum = leftNum * (N[j] - '0');
		}
		for (int j = (i + 1); j < N.length(); j++)
		{
			rightNum = rightNum * (N[j] - '0');
		}

		if (leftNum == rightNum)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}