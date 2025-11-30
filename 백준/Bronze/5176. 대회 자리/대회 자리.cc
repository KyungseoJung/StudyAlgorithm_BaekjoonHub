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
// 5176번 문제: 대회 자리

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	
	int P, M;
	vector <int> seats;
	int wantNum;	// 각 참가자들이 원하는 의자의 번호
	int noPariticpateNum;	// 참가하지 못하는 사람의 수 카운팅
	while (T--)
	{
		cin >> P >> M;
		seats.assign(M+1, 0);	// M개 사이즈로 고정. 모든 요소를 0으로 초기화
		noPariticpateNum = 0;	
		while (P--)
		{
			cin >> wantNum;
			if (seats[wantNum] == 0)
			{
				seats[wantNum]++;
			}
			else
			{
				noPariticpateNum++;
			}
		}

		cout << noPariticpateNum << "\n";
	}


	return 0;
}