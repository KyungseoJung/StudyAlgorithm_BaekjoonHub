#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 코드 작동 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;	// 테스트의 개수
	cin >> T;

	int C;	// 각 케이스의 거스름돈
	int restMoney;	// 계산용 변수
	//int answer[4][100];	// 쿼터, 다임, 니켓, 페니의 개수

	vector <int> q(T);	// 쿼터의 개수
	vector <int> d(T);	// 다임의 개수
	vector <int> n(T);	// 니켓의 개수
	vector <int> p(T);	// 페니의 개수

	for (int i = 0; i < T; i++)
	{
		cin >> C;

		q[i] = (C / 25);
		restMoney = (C - 25 * q[i]);
		
		d[i] = restMoney / 10;
		restMoney = (restMoney - 10 * d[i]);

		n[i] = restMoney / 5;
		restMoney = (restMoney - 5 * n[i]);

		p[i] = restMoney / 1;
	}

	for (int i = 0; i < T; i++)
	{
		cout << q[i] << " " << d[i] << " " << n[i] << " " << p[i] << "\n";
	}
	return 0;
}