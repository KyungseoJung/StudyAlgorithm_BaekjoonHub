#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int test;
	cin >> test;
	
	vector <double> people(test, 0);	// 처음에는 모두 0명으로 설정
	//** 오답 포인트: float이 아니라 double로 가기 (숫자가 엄청 커질 수 있으므로) 
	int input;
	for (int i = 0; i < test; i++)
	{
		cin >> input;

		for (int j = 0; j < input; j++)
		{
			people[i] = (people[i] + 0.5) * 2;
		}

	}

	for (int i = 0; i < test; i++)
	{
		cout << (int)people[i];
		if (i < test - 1)
		{
			cout << "\n";
		}
	}

	return 0;
}