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
// 1026번 문제: 보물

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	int arrNum = 2;
	vector <int> A(N);
	vector <int> B(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}

	//** 아이디어: A의 가장 큰 수(작은 수)가 B의 가장 작은 수(큰 수)와 곱해지도록 하면 됨
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int minS = 0;
	for (int i = 0; i < N; i++)
	{
		minS += A[i] * B[N - 1 - i];
	}

	cout << minS;
	
	return 0;
}