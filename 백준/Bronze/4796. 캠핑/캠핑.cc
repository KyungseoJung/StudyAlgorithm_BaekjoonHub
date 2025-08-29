#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int L, P, V;
	// 캠핑하는 연속하는 P일 중, L일동안만 사용 가능. 이제 막 V일짜리 휴가 시작함.
	int caseNum = 0;
	vector <int> maxDays;

	while (true)
	{
		cin >> L >> P >> V;
	
		if ((L == 0) && (P == 0) && (V == 0))
		{
			break;
		}

		maxDays.push_back( (V / P) * L + min(L, (V % P)) );
		// 총 V일 중, P가 몇 번 차지 가능한가 = (V/P) 몫!
		// ㄴ 그 차이하고 난 후에, 나머지 며칠이 남아있는가 = (V % P) 나머지!

		caseNum++;
	}

	for (int i = 0; i < caseNum; i++)
	{
		cout << "Case " << (i+1) << ": " << maxDays[i] << "\n";
	}

	return 0;
}