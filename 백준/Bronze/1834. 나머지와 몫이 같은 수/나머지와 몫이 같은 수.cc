#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#1834번 문제
// 포인트: 큰 숫자의 자연수를 다루는 만큼, 코드에서 사용되는 모든 int를 long long int로 설정해야 함!
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	// 나머지와 몫이 모두 같은 자연수를 찾기
	// (N*1 + 1), (N*2 + 2), (N*3 + 3), ...(N*m + m) 순으로 찾으면 되는데,
	// 이때, m은 N보다 작아야 하는 것이 핵심. 나누는 수보다 큰 나머지는 나올 수 없으므로.

	long long int sum = 0;
	// for문의 i도 int가 아니라 long long int로 설정해야 하는 게 포인트!!!
	for (long long int i = 1; i < N; i++)
	{
		sum += (N * i + i);
	}

	cout << sum;
	return 0;
	
}
