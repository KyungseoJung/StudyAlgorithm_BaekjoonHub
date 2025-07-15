#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main()
{
	int T;
	cin >> T;
	string testData;
	vector <string> answer(T);
	int tNum = 0;
	stack <int> st;
	while (T--)
	{
		while (!st.empty()) // stack 초기화
		{
			st.pop();
		}
		cin >> testData;
		// VPS문제
		// 괄호 열린 걸 닫아주는 게 핵심. 열지도 않았는데 닫으면 NO
		for (int i = 0; i < testData.length(); i++)
		{
			//cout << testData[i];	//  at(i);
			if (testData[i] == '(')
				st.push(1);
			else if (testData[i] == ')')
			{

				if (st.empty())	// 열지도 않았는데 닫으면 NO
				{
					answer[tNum] = "NO";
					//cout << "check용: i번째 - " << tNum << "\n";
					break;
				}
				else
				{
					st.pop();
				}
			}
		}
		if ((answer[tNum] == "" ) && st.empty())	// 아직 answer 답이 입력되지 않았고, st가 비어있다면 (= 열린 괄호가 닫힌 괄호와 짝이 잘 맞아서 아무것도 남지 않은 것)
			answer[tNum] = "YES";
		else if ((answer[tNum] == "") && !st.empty())	// 아직 answer 답이 입력되지 않았지만, st가 비어있지 않다면 (= 닫히지 않은 열린 괄호 '('가 남아있는 것 )
			answer[tNum] = "NO";


		tNum++;
	}

	for (int i = 0; i < tNum; i++)
	{
		//cout << T << "번째 답\n";
		cout << answer[i] << "\n";
	}

	return 0;
}