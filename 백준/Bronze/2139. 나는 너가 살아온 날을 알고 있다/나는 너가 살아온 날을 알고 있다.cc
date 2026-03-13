#include <iostream>

using namespace std;
// 2139번 문제: 나는 너가 살아온 날들을 알고 있다
int main()
{
	int day, month, year;

	while (true)
	{
		cin >> day >> month >> year;
		if ((day == 0) && (month == 0) && (year == 0))
		{
			break;
		}
		bool leapYear = false;	// 윤년이면 true
		if ((year % 4 == 0) && (year % 100 != 0))
		{
			leapYear = true;
		}
		else if (year % 400 == 0)	// 400으로 떨어지는 년도는 포함해주기!!
		{
			leapYear = true;
		}

		int dayCount = 1;
		// 1) 먼저 month을 계산하기
		for (int i = 1; i < month; i++)
		{
			switch (i)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				dayCount += 31;
				break;

			case 4:
			case 6:
			case 9:
			case 11:
				dayCount += 30;
				break;

			case 2:
				if (leapYear == true)
				{
					dayCount += 29;
				}
				else
				{
					dayCount += 28;
				}
				break;

			}
		}

		// 2) 그 다음 day를 계산하기
		dayCount += (day - 1);

		cout << dayCount << "\n";
	}
	
	return 0;
}