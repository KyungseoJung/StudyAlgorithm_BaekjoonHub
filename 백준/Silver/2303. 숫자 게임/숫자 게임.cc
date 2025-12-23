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

	int N;
	cin >> N;
	
	int n = 5;
	int input;
	
	vector <vector<int>> nums(N, vector<int>(n));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nums[i][j];
		}
	}
	vector <int> maxNum(N);	// 각 사람마다 일의 자리 수가 최대일 때의 값을 저장하기

	int checkNum;
	int rememberMax = 0;
	//int rememberMaxSum = 0;	// 일의 자리가 최대인 수가 나왔을 때, 3개 숫자의 합
	int rememberPerson = 0;
	for (int person = 0; person < N; person++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = (i + 1); j < n; j++)
			{
				for (int k = (j + 1); k < n; k++)
				{
					checkNum = nums[person][i] + nums[person][j] + nums[person][k];
					if (checkNum % 10 >= rememberMax)
					{
						//cout << "-- " << person + 1 << "번째 사람이 " << checkNum << "숫자로, 일의 자리(" << (checkNum % 10) << ") 가장 큼!\n";
						rememberPerson = person;
						rememberMax = checkNum % 10;
					}
				}
			}
		}
	}

	cout << rememberPerson+1;	// 기존 벡터는 0부터 시작하니까. 실제 몇 번째인지 말할 땐, +1 해주기


	return 0;
}