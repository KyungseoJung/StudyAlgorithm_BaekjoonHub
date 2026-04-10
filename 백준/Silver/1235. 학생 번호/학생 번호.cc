#include <iostream>
#include <vector>

using namespace std;
// 1235번 문제: 학생 번호
int main()
{
	int N;
	cin >> N;
	vector <string> numbers(N);
	for(int i=0; i<N; i++)
	{ 
		cin >> numbers[i];
	}

	//cout << "체크1 \n";
	//string st;
	//st = numbers[0][numbers[0].length() - 2];
	//st += numbers[0][numbers[0].length() - 1];

	//cout << st;

	// 가장 작은 k를 찾아보자 (뒤에서 k자리만을 남겨서 구분가능하도록)
	int k = 1;
	vector <string> shortenNumbers(N);
	bool everythingDifferent = true;	// 모든 숫자들이 다르면 true
	while (true)
	{
		for (int i = 0; i < N; i++)
		{
			shortenNumbers[i] = "";
			// 끝에서 k자리만을 남겨서 저장하기
			for (int j = k; j >= 1; j--)
			{
				//cout << "체크2\n";
				shortenNumbers[i] += numbers[i][numbers[i].length() - j];

				//cout << i << "번째 숫자 붙이는 중: " << shortenNumbers[i] << "\n";
			}
		}

		// k자리까지만 남긴 숫자들을 비교하기
		everythingDifferent = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = (i + 1); j < N; j++)
			{
				if (shortenNumbers[i] == shortenNumbers[j])
				{
					everythingDifferent = false;
					break;
				}
			}
			if (everythingDifferent == false)
			{
				break;
			}
		}

		if (everythingDifferent == true)
		{
			cout << k;
			break;
		}
		else
		{
			k++;
		}

	}

	return 0;
}