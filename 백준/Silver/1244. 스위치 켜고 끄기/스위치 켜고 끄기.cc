#include <iostream>
#include <vector>

using namespace std;

vector <int> switches;	// 스위치 ON OFF 상태 입력

void changeSwitches(int _gender, int _num)
{
	switch (_gender)
	{
	case 1 : 
		for (int i = 1; i <= (switches.size() / _num); i++)
		{
			if (switches[_num * i - 1] == 0) // 이미 0이었다면
			{
				switches[_num * i - 1] = 1;
			}
			else // 이미 1이었다면
			{
				switches[_num * i - 1] = 0;
			}
		}
		break;
	case 2: 
		// 일단 받은 숫자의 스위치 상태 바꾸기
		if (switches[_num - 1] == 0)
		{
			switches[_num - 1] = 1;
		}
		else
		{
			switches[_num - 1] = 0;
		}

		int minLength;
		minLength = (_num - 1) > (switches.size() - _num) ? (switches.size() - _num) : (_num - 1);
		// 좌, 우 중 더 짧은 길이만큼만 검사하면 됨.
		for (int i = 1; i <= minLength; i++)
		{
			if ((switches[_num - 1 - i] ) == (switches[_num - 1 + i]))
			{
				if ((switches[_num - 1 - i]) == 0)
				{
					switches[_num - 1 - i] = 1;
					switches[_num - 1 + i] = 1;
				}
				else
				{
					switches[_num - 1 - i] = 0;
					switches[_num - 1 + i] = 0;
				}
			}
			else // 만약 좌우대칭이 맞지 않는다면, 거기서 stop. 더이상 검사하지 말기
			{
				break;
			}
		}
		break;
	}
}

int main()
{
	int numOfSwitch;
	cin >> numOfSwitch;

	switches.resize(numOfSwitch);
	for (int i = 0; i < numOfSwitch; i++)
	{
		cin >> switches[i];
	}

	int numOfStudents;
	cin >> numOfStudents;

	int gender;
	int givenNum;
	for (int i = 0; i < numOfStudents; i++)
	{
		cin >> gender >> givenNum;
		changeSwitches(gender, givenNum);
	}
		  

	// 최종 출력
	for (int i = 0; i < numOfSwitch; i++)
	{
		if ((i >0 ) && (i % 20 == 0)) // 한 줄에 20개씩만 출력. 그 다음부터는 줄 바꿔서 출력.
		{
			cout << "\n";
		}


		cout << switches[i]; // 스위치 값 출력

		if (i != (numOfSwitch - 1))	// 마지막이 아닐 때에만 공백 넣기
		{
			cout << " ";
		}
	}

	return 0;
}