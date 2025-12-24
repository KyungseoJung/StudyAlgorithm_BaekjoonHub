#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 2303번 문제: 숫자 게임
// ** 번호가 크다는 사람이 = 3개 숫자의 합이 큰 사람이 아니라, 부여받은 idnex 번호가 큰 사람이었음...
int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long int len;
	cin >> len;

	cin.ignore();	// len 입력한 뒤의 엔터 한번 무시
	
	string input;
	getline(cin, input);

	string saveNum;
	vector<long long int> saveNums;
	for (long long int i = 0; i < len; i++)
	{
		if (isdigit(input[i]) != 0)	// 만약 숫자라면
		{
			saveNum = input[i];
			if (i == (len - 1))	// 마지막 자릿수라면
			{
				saveNums.push_back(stoi(saveNum));
				break;	// for문 자체를 돌 이유가 없어짐
			}
			//cout << input[i] << "는 숫자 \n";
			for (long long int j = i+1; j < len; j++) // 그 다음, 다음 다음 입력들도 숫자인지 확인하기
			{
				if (isdigit(input[j]) != 0) // 숫자라면
				{
					saveNum += input[j];

					if (j == (len - 1))	// 마지막 자릿수라면
					{
						saveNums.push_back(stoi(saveNum));
						i = j;	// 이거 안 하면, (123) 같은 값이 입력되면 -> 123 + 23 + 1 해버림
					}
				}
				else
				{
					//숫자가 아닌 수가 나온다면, j의 for문 통과하기
					// 저장했던 j만큼 i도 증가시켜주기
					i = j;
					saveNums.push_back(stoi(saveNum));
					break;
				}
			}
		}
		// 숫자 아니면 건너뛰기~
	}

	long long int sum = 0;
	for (long long int i = 0; i< saveNums.size(); i++)
	{
		sum += saveNums[i];
	}

	cout << sum;
	return 0;
}