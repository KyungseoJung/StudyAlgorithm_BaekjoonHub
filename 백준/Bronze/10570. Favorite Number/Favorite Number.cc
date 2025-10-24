#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
// 10570번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int V;
	int arr[1001] = { 0 };	// 1부터 1000까지의 숫자를 카운팅하기 위함.
	int input;
	int minInput,  maxInput;

	int maxCount, maxCountEle;
	for (int i = 0; i < N; i++)
	{
		cin >> V;	// 총 N번 V를 입력해야 하기 때문.

		// 각 경우마다 데이터 초기화
		fill(arr, arr+1001, 0);		//0으로 초기화 (쪽지수 카운팅 하기 전에)
		maxInput = 0;
		minInput = 9999;
		maxCount = 0;
		for (int j = 0; j < V; j++)
		{
			cin >> input;

			// arr 서치 범위를 정해주기 위함
			if (input > maxInput)
			{
				maxInput = input;
			}
			if (input < minInput)
			{
				minInput = input;
			}
			arr[input] += 1;
		}

		// 가장 많이 선택된 숫자를 출력 (많이 선택된 수가 여러개라면 그 중 작은 수를 출력)
		for (int j = minInput; j <= maxInput; j++)
		{
			if (arr[j] > maxCount)
			{
				maxCount = arr[j];
				maxCountEle = j;
			}
		}

		// 각 테스트마다 쪽지에서 가장 많이 선택된 수를 출력
		cout << maxCountEle << "\n";
	}

	return 0;
}