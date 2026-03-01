#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int inputNum;
	string inputString;

	int minMax;	// 크다고 말한 값 중에 가장 작은 값
	int maxMin;	// 작다고 말한 값 중에 가장 큰 값
	bool dishonest = false;
	minMax = 99999999999999;
	maxMin = -1;

	while (true)
	{

		cin >> inputNum;	
		if (inputNum == 0)
		{
			return 0;
		}

		cin.ignore();
		getline(cin, inputString);
		
		if (inputString == "too high")
		{
			if (inputNum < minMax)
			{
				minMax = inputNum;
			}
			if (inputNum <= maxMin)
			{
				dishonest = true;
			}
		}
		else if (inputString == "too low")
		{
			//cout << "inputNum: " << inputNum << " | " << "maxMin: " << maxMin << "\n";

			if (inputNum > maxMin)
			{
				maxMin = inputNum;
			}
			if (inputNum >= minMax)
			{
				dishonest = true;
			}
		}
		else if (inputString == "right on")
		{
			//cout << "maxMin : " << maxMin << "\n";
			//if (inputNum <= maxMin)
			//{
			//	//cout << "거짓말!! \n";
			//}
			if ((!(inputNum > maxMin)) || (!(inputNum < minMax)))
			{
				// Min보다 크지 않거나, Max보다 작지 않다면 거짓말 한 것임
				cout << "Stan is dishonest\n";
			}
			else if(dishonest == true)	// 말하는 문장들 사이에도 모순이 있었다면
			{
				cout << "Stan is dishonest\n";
			}
			else
			{
				cout << "Stan may be honest\n";
			}

			// 다음 게임을 위해 초기화
			dishonest = false;
			minMax = 99999999999999;
			maxMin = -1;
		}

	}
}