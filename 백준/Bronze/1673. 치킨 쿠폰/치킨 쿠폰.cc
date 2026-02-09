#include <iostream>

using namespace std;
// 1673번 문제: 치킨 쿠폰
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, k;

	while (cin >> n >> k)
	{
		int serviceCriterion = k;	// 서비스 기준
		int chickenNum = 0;	// 먹을 수 있는 치킨 마리 수
		int coupon = n;	// 현재 갖고 있는 쿠폰 수
		int cumulativeChicken = 0;	// 지금까지 먹은 치킨 수 카운팅
		int stamp = 0;	// 현재 갖고 있는 스탬프 수

		while (coupon > 0)
		{
			cumulativeChicken += coupon;	// 가진 쿠폰만큼 치킨을 모두 먹음
			stamp += coupon;	// 쿠폰을 사용한만큼 스탬프 추가로 생김
			coupon = stamp / k;	// 스탬프 k개-> coupon으로 교환	(다음 turn에서 치킨을 살 때 사용하겠지)
			stamp = stamp % k;	// 남은 스탬프 개수 업데이트
		}

		cout << cumulativeChicken << "\n";

	}


	return 0;
}