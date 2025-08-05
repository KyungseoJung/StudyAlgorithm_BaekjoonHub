//재귀 문제 | 칸토어집합 (4779번 문제)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector <char> sentence;
int firstLen;

void changeSentence(int len)
{
	//cout << "\n 확인용 문장: ";
	//for (int i = 0; i < firstLen; i++)
	//{
	//	cout << sentence[i];
	//}

	//int num1 = len / 3;
	//int num2 = len * 2 / 3;
	for (int i = 0; i < firstLen/len; i++)
	{
		for (int j = (len/3 * (1 + 3*i)); j < (len/3) * (2+3*i); j++)
		{
			sentence[j] = ' ';
		}
	}
	len = len / 3;	// 각 선의 길이가 1/3이 된 것임.


	if (len > 1)	// 변화를 거친 선의 길이가 1이 아니라면,
	{
		changeSentence(len);
	}


}

int main()
{
	int N;
	while (cin >> N)	// 입력하는 케이스마다 출력하도록
	{
		// 문자열 설정 시작
		firstLen = pow(3, N);
		sentence.resize(firstLen);


		for (int i = 0; i < firstLen; i++)
		{
			sentence[i] = '-';
		}

		// 변형 시작
		changeSentence(firstLen);

		//cout << "\n 최종 출력:";
		for (int i = 0; i < firstLen; i++)
		{
			cout << sentence[i];
		}
		cout << "\n";
	}


	return 0;
}