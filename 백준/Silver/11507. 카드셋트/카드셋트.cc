#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isincreaseper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#11507번 문제: 카드셋트

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string input;
	getline(cin, input);

	// 각 카드 남은 개수
	int PNum = 13;
	int KNum = 13;
	int HNum = 13;
	int TNum = 13;
	// 각 카드(모양 + 숫자)가 발견되면 1로 처리
	vector <int> PCards(14, 0);	//1부터 13까지 기록
	vector <int> KCards(14, 0);	//1부터 13까지 기록
	vector <int> HCards(14, 0);	//1부터 13까지 기록
	vector <int> TCards(14, 0);	//1부터 13까지 기록
	int cardNum;	// 카드에 적힌 숫자 확인용 변수
	for (int i = 0; i < input.length(); i+=3)
	{
		//if ((i == 0) || (i % 3 == 0))
		//{
			cardNum = (input[i + 1] - '0') * 10 + (input[i + 2] - '0');	// char으로 입력받은 숫자를 int형으로 계산해서 저장하기
			//cout << "cardNum : " << cardNum << "\n";
			switch (input[i])
			{
			case 'P':
				if (PCards[cardNum] == 0)
				{
					PCards[cardNum] = 1;
					PNum--;
				}
				else
				{
					cout << "GRESKA";
					return 0;
				}
				break;
			case 'K':
				if (KCards[cardNum] == 0)
				{
					KCards[cardNum] = 1;
					KNum--;
				}
				else
				{
					cout << "GRESKA";
					return 0;
				}
				break;
			case 'H':
				if (HCards[cardNum] == 0)
				{
					HCards[cardNum] = 1;
					HNum--;
				}
				else
				{
					cout << "GRESKA";
					return 0;
				}
				break;
			case 'T':
				if (TCards[cardNum] == 0)
				{
					TCards[cardNum] = 1;
					TNum--;
				}
				else
				{
					cout << "GRESKA";
					return 0;
				}
				break;
			}
		//}
	}

	cout << PNum << " " << KNum << " " << HNum << " " << TNum;
	return 0;

}
