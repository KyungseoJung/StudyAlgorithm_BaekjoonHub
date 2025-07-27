#include <iostream>
#include <cmath> // 꼭 필요한 듯. 없으면 문제 제출창에서 <컴파일 에러> 발생

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	int numOfCase;
	cin >> N;

	// 각 블록이 N개일 때, 경우의 수: 2 ^ N
	numOfCase = pow(2, N);
	cout << numOfCase;

	return 0;
}