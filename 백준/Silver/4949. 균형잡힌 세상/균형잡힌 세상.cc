#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>	// getline 함수를 쓰기 위함

using namespace std;
int main()
{
	string inputString;

	stack <char> checkST;
	//stack <int> checkBigST;

	bool balance = true;
	//cout << "발란스 배열 체크: " << balance[0] << balance[1] << balance[2] << "\n";

	string answer[9999];
	int answerEle = 0;
	while (true)
	{
		balance = true;

		//cin >> inputString;
		getline(cin, inputString);	// 그냥 cin이 아닌, getline을 사용함으로써, 각 문장당 이 while문이 한번씩 실행되는 것임

		//cout << "for문 시작\n";

		if ((inputString.size() == 1) && (inputString[0] == '.'))
		{
			//cout << "테스트 종료";
			for (int i = 0; i < answerEle; i++)
			{
				cout << answer[i] << "\n";
			}



			return 0;
		}


		for (int i = 0; i < inputString.size(); i++)
		{
			if(i == inputString.size() - 1)	// 문장의 마지막에
			{
				//cout << answerEle << "번째 문장의 끝 \n"  << balance << " | " << checkST.empty() << "\n";

				if (balance && (checkST.empty() == true))	// bool형이 true이고, checkST (스택)이 모두 비어있다면
				{
					answer[answerEle] = "yes";
					//cout << answerEle << "번째 answer: " << answer[answerEle] << "\n";
				}
				else
				{
					answer[answerEle] = "no";
					//cout << answerEle << "번째 answer: " << answer[answerEle] << "\n";
				}

				// stack 초기화
				while (checkST.size())
					checkST.pop();
				answerEle++;
			}
			else
			{
				if (inputString[i] == '(')
					checkST.push('(');
				if (inputString[i] == '[')
					checkST.push('[');

				if (inputString[i] == ')')
				{
					if (checkST.empty())
						balance = false;
					else if (checkST.top() == '(')
						checkST.pop();
					else // 짝지을 열린 괄호도 없는데, 닫힌 괄호가 입력됨
					{
						balance = false;
					}
				}
				if (inputString[i] == ']')
				{
					if (checkST.empty())
						balance = false;
					else if (checkST.top() == '[')
						checkST.pop();
					else // 짝지을 열린 괄호도 없는데, 닫힌 괄호가 입력됨
					{
						balance = false;
					}
				}

			}
		}


	}
}