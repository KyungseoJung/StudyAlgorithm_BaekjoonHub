#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	//cout << char('a' + 4);
	string inputString;
	int ele = 0;
	vector <int> countAlphabet(26);	// a부터 z까지 등장 횟수 저장
	int alphabetNum;
	while (getline(cin, inputString))
	{
		for (int i = 0; i < inputString.length(); i++)
		{
			if (inputString[i] != ' ')
			{
				alphabetNum = (inputString[i] - 'a');
				countAlphabet[alphabetNum]++;
				//cout << inputString[i] << "는 숫자로: " << alphabetNum << "\n";
			}
		}
		ele++;
	}

	// 가장 많이 나온 문자 알아내기
	int maxCount = 0;
	vector <int> maxEle;
	for (int i = 0; i < countAlphabet.size(); i++)
	{
		if (countAlphabet[i] > maxCount)	// 가장 많이 나온 문자가 새롭게 업데이트 된다면
		{
			maxCount = countAlphabet[i];
			maxEle.clear();
			maxEle.push_back(i);
		}
		else if (countAlphabet[i] == maxCount)	// 가장 많이 나온 문자가 여러개라면
		{
			maxCount = countAlphabet[i];
			maxEle.push_back(i);
		}
	}

	//cout << char('a' + maxEle);
	for (int i = 0; i < maxEle.size(); i++)
	{
		cout << char('a' + maxEle[i]);
	}
	return 0;
}