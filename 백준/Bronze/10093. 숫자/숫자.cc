#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 10093번 문제: 숫자

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long int num1, num2;    // 높은 수를 잘 출력하기 위해, 변수 type을 long long으로 지정
	cin >> num1 >> num2;

	long long int max = (num1 > num2) ? num1 : num2;
	long long int min = (num1 > num2) ? num2 : num1;

	// 사이 숫자 개수 출력 : 두 숫자가 동일할 때에도 출력 고려해주기
	if (max == min)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << max - min - 1 << "\n";
	}

	for (long long int i = min + 1; i < max; i++)
	{
		cout << i << " ";
	}
	return 0;
}