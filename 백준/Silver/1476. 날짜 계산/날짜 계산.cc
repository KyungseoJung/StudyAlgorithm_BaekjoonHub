#include <iostream>
#include <vector>

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int ERange = 15;
	int SRange = 28;
	int MRange = 19;

	int E = 1;
	int S = 1;
	int M = 1;

	// 찾고자 하는 E,S,M을 입력
	int wantE;
	int wantS;
	int wantM;
	cin >> wantE >> wantS >> wantM;

	int year = 1;
	while (true)
	{
		if ((E == wantE) && (S == wantS) && (M == wantM))
		{
			cout << year;
			return 0;
		}

		year++;	// 아래 코드들을 실행하면서, 우리 연도 +1

		E += 1;
		S += 1;
		M += 1;

		if (E > ERange)
		{
			E = 1;
		}
		if (S > SRange)
		{
			S = 1;
		}
		if (M > MRange)
		{
			M = 1;
		}


	}
}