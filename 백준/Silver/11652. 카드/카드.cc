#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
// ** 핵심 아이디어: 새로운 숫자를 입력할 때마다, 이미 있는 숫자인지 확인하면 계산 복잡도(O(N^2))가 너무 높음
// ㄴ따라서, (1) 모든 숫자를 입력하고, (2) 각 숫자를 정렬한 다음, (3) i번째 수와 i-1번째 수가 같은지 확인하면서 개수를 카운팅 하면 됨.

// ** for문에서 N-1번째의 경우도 고려해줘야 함.
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
 
	// 입력 ---------------------------
	vector <long long int> input(N);
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}


	// 정렬 ---------------------------
	sort(input.begin(), input.end());	// 작은 숫자에서 큰 숫자 순서대로 정렬될 것임.


	// 숫자들 카운팅
	// 이전 숫자와 동일할 때까지만 카운팅
	int nowCount = 0;

	// 어떤 숫자 종류들이 있고, 각 숫자가 몇 번 나왔는지 저장하는 벡터
	vector <long long int> numMembers;
	vector <int> countMembers;


	for (int i = 0; i < input.size(); i++)
	{
		//cout << i << "번째 수: " << input[i] << "\n";

		if (i == 0)
		{
			nowCount = 1;
		}
		else
		{
			if (input[i] == input[i - 1])
			{
				nowCount++;

			}
			else if(input[i] != input[i-1])	
			{
				// 만약 다른 숫자가 나왔다면, 이전의 숫자를 기록에 추가해주기
				numMembers.push_back(input[i - 1]);
				countMembers.push_back(nowCount);

				nowCount = 1;	// i번째 숫자의 카운팅을 새롭게 시작해주기
			}
		}
	}
	// (위 for문에서는 다른 숫자가 나오는지만 검사해서, 마지막 원소 -1까지만 push 해주고 있음)
	// 따라서, i가 N-1일 때에도 고려해주기
	numMembers.push_back(input[N - 1]);
	countMembers.push_back(nowCount);

	//for (int i = 0; i < numMembers.size(); i++)
	//{
	//	//cout << "숫자 멤버: " << numMembers[i] << "| 개수: " << countMembers[i] << "\n";
 //	}
	
	// 기록된 정보들을 기반으로 어떤 수가 가장 큰지 검사
	int maxCount = -1;
	long long int answerNum = numMembers[0];
	for (int i = 0; i < countMembers.size(); i++)
	{
		if (countMembers[i] > maxCount)
		{
			maxCount = countMembers[i];
			answerNum = numMembers[i];
		}
		else if (countMembers[i] == maxCount)
		{
			if (numMembers[i] < answerNum) 
			{
				answerNum = numMembers[i];	// 더 작은 수를 answerNum으로 저장
			}
		}
	}

	cout << answerNum;
	return 0;
}