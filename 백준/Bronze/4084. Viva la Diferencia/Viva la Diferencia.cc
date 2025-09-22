#include <iostream>
#include <vector>

using namespace std;

vector <int> v(4);

int counting()
{
	int count = 0;

	int tempNum[4];	

	while (true)
	{
		if ((v[0] == v[1]) && (v[0] == v[2]) && (v[0] == v[3]))
		{
			return count;
		}
		else
		{
			count++;
		}


		// 계산하기 위한 temp 숫자 미리 저장
		for (int i = 0; i < v.size(); i++)
		{
			tempNum[i] = v[i];
		}

		// 실제값 업데이트
		// |a-b| |b-c| |c-d| |d-a|
		v[0] = (tempNum[0] - tempNum[1] > 0) ? (tempNum[0] - tempNum[1]) : -(tempNum[0] - tempNum[1]);
		v[1] = (tempNum[1] - tempNum[2] > 0) ? (tempNum[1] - tempNum[2]) : -(tempNum[1] - tempNum[2]);
		v[2] = (tempNum[2] - tempNum[3] > 0) ? (tempNum[2] - tempNum[3]) : -(tempNum[2] - tempNum[3]);
		v[3] = (tempNum[3] - tempNum[0] > 0) ? (tempNum[3] - tempNum[0]) : -(tempNum[3] - tempNum[0]);
	}
}

int main()
{
	int input[4];

	while (true)
	{
		cin >> input[0] >> input[1] >> input[2] >> input[3];
		if ((input[0] == 0) && (input[1] == 0) && (input[2] == 0) && (input[3] == 0))
		{
			return 0;	// int main 종료
		}

		for (int i = 0; i < v.size(); i++)
		{
			v[i] = input[i];
		}

		cout << counting() << "\n";
	}



}