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
// 9325번 문제: 얼마?

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int s, n;
	int q, p;
	int sum;
	while (T--)
	{
		sum = 0;
		cin >> s;
		sum += s;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> q >> p;
			sum += q * p;
		}

		cout << sum << "\n";
	}
	
	return 0;
}