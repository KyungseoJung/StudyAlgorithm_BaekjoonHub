#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#11047번 문제
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 입력들 ======================
	int N, K;
	cin >> N >> K;
	vector <int> coins(N);
	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}

	// K원을 만드는 데 필요한 동전 개수 최솟값 찾기======================
	int count = 0;
	int num;
	while (K > 0)
	{
		for (int i = (N - 1); i >= 0; i--)
		{
			if (K / coins[i] >= 1)	// K원보다 작거나 같은 수 중 가장 높은 가치를 찾기
			{
				num = (K / coins[i]);
				K -= coins[i] * num;
				count += num;
			}
		}
	}

	cout << count;

	return 0;

}
