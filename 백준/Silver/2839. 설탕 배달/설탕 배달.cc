#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
// 2839번. 설탕 배달
using namespace std;
int main()
{
	// 최대한 적은 수의 봉지
	// 5킬로그램, 3킬로그램 봉지가 있음
	int N;
	cin >> N;

	int bags3, bags5;	// 3kg봉지는 최대가 1666개, 5kg 봉지는 최대가 1000개일 것임.
	// 5kg봉지가 최대가 될수록 좋으니까, 처음엔 5kg 봉지를 최대로 놓고, 그 다음부터는 1개씩 줄여가면서 계산해보기

	//int bags5 = N / 5;	// 5kg봉지의 최대 개수는 이 계산 값의 몫임.
	for (int bags5 = N / 5; bags5 >= 0; bags5--)	// 5kg 봉지의 최대 기수 bags5부터 최소 개수 0까지 테스트하기
	{
		// 계산이 성립되는 순간, 그 순간의 상태가 5kg봉지가 최대일 때므로 바로 출력. 
		// 끝까지 맞는 경우가 없다면, 정확하게 N킬로그램을 만들 수 없는 것임.
		if ((N - bags5 * 5) % 3 == 0)
		{
			bags3 = (N - bags5 * 5) / 3;	// (남은 무게 /3) = 필요한 3kg봉지 개수
			cout << bags5 + bags3;
			return 0;
		}
	}

	cout << -1;
	return 0;


}