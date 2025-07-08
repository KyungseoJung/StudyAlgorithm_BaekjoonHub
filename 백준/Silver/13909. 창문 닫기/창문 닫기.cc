#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// N개 창문까지 열려있는 창문의 개수: N개수까지 약수가 홀수인 경우	(1과 자기자신까지 포함)
	//*** 새로운 지식: 일반적으로 약수는 짝수개이지만, 유일하게 완전제곱수만 약수가 홀수
	// 즉, 1부터 N까지 완전제곱수의 개수만 구하면 됨.
	
	// 1^2, 2^2, 3^2, 4^2, ..., sqrt(N)^2
	// 즉, sqrt(N)개가 열려있는 것임.
	int N;
	cin >> N;

	int open = floor(sqrt(N));
	cout << open;

	return 0;
}