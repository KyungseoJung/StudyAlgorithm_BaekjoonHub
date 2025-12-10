#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isincreaseper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#12788번 문제: 제 2회 IUPC는 잘 개최될 수 있을까?

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector <int> penNum(N);

	int M, K;
	cin >> M >> K;
	int needPen = M * K;	// 필요한 펜 개수
	for (int i = 0; i < N; i++)
	{
		cin >> penNum[i];
	}

	// 정렬해서 가장 펜이 많은 사람들 순서대로 확인하기
	sort(penNum.begin(), penNum.end());
	int sum = 0;
	int ele = 0;	// 펜을 빌린 회원의 수
	for (int i = N-1; i >= 0; i--)
	{
		sum += penNum[i];
		ele++;
		//cout << "sum : " << sum << " | needPen : " << needPen << "\n";
		if (sum >= needPen)	// 원하는 펜을 모두 얻었다면 바로 종료
		{
			cout << ele;
			return 0;	
		}
	}

	// 만약 모든 for문을 거쳤는데도 펜이 부족하다면
	cout << "STRESS";

	return 0;

}
