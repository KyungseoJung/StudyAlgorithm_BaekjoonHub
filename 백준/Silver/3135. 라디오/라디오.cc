#include <iostream>
#include <vector>

using namespace std;
int main()
{
	// 속도 빠르게
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);


	// 입력
	int A, B;
	cin >> A >> B;
	int N;
	cin >> N;
	
	vector <int> saved(N);
	for (int i = 0; i < N; i++)
	{
		cin >> saved[i];
	}

	// 계산하기
	int diff1;
	diff1 = (A - B) > 0 ? (A - B) : (B - A);	// A와 B의 차이 저장

	int diff2;
	int mindiff = diff1;

	int saveMoreBetterEle = -1;	// 즐겨찾기 이용하는 게 더 나은 선택이라면 true
	for (int i = 0; i < N; i++)	// 즐겨찾기 저장된 주파수 중 diff1보다 작은 것이면서, 가장 차이가 작은 주파수 번호를 찾기
	{
		diff2 = (B - saved[i]) > 0 ? (B - saved[i]) : (saved[i] - B);
		if (diff2 < mindiff)
		{
			mindiff = diff2;
			saveMoreBetterEle = i;
		}
	}

	int count = 0;
	if (saveMoreBetterEle != -1)
	{
		count += 1;
		int diff3 = (B - saved[saveMoreBetterEle] > 0) ? (B - saved[saveMoreBetterEle]) : -(B - saved[saveMoreBetterEle]);
		count += (diff3);
	}
	else // 그냥 하나하나 직접 이동하는 게 가장 빠른 방법이라면
	{
		count = (diff1);
	}

	cout << count;
	return 0;
}