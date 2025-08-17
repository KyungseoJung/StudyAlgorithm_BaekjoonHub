#include <iostream>
#include <vector>

using namespace std;
//** 포인트: 이분탐색 코드!!

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long int N, M;
	cin >> N >> M;
	vector <string> criterionVec;
	vector <int> criterionNumVec;

	vector <string> criterionTemp(N);
	vector <int> criterionNumTemp(N);

	//bool alreayExist;
	int ele = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> criterionTemp[i] >> criterionNumTemp[i];
		if (i == 0)
		{
			criterionVec.push_back(criterionTemp[i]);
			criterionNumVec.push_back(criterionNumTemp[i]);
			ele++;	// 벡터에 요소 추가
		}
		else if ( (i > 0) && (criterionNumTemp[i] != criterionNumVec[ele-1]))
		{
			// 이전 벡터 요소와 비교하는 이유: '칭호는 전투력 상한값의 비내림차순으로 주어진다' 조건 때문.
			// ㄴ 이 조건이 없었다면, 전체 벡터 요소와 비교해야 하므로, 코드가 좀더 복잡해졌을 것임.
			// 존재하지 않는 새로운 숫자를 입력했다면, Vector에 추가해주기
			criterionVec.push_back(criterionTemp[i]);
			criterionNumVec.push_back(criterionNumTemp[i]);
			ele++;	// 벡터에 요소 추가
		}
	}

	int input;
	for (int i = 0; i < M; i++)
	{
		cin >> input;

		//for (int j = 0; j < ele; j++)
		//{
		//	//cout << "검사 시작 | 기준 숫자: " << criterionNumVec[j] << "\n";
		//	if (input <= criterionNumVec[j])	// 이런 식으로 하면, 자동으로 다음 j에서 criterionNum[j-1] < input = criterionNum[j]로 분류될 것임
		//	{
		//		// 왜: '칭호는 전투력 상한값의 비내림차순으로 주어진다' 조건 때문.
		//		cout << criterionVec[j] << "\n";

		//		break;
		//	}
		//}
		
		//***** 이분탐색 진행
		// lower_bound: "input 이상이면서 가장 작은 원소의 iterator" 반환
		int idx = lower_bound(criterionNumVec.begin(), criterionNumVec.end(), input) - criterionNumVec.begin();

		cout << criterionVec[idx] << "\n";

	}

	return 0;
}