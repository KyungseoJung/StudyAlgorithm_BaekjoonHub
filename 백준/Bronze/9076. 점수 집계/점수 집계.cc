#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#90764번 문제
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	int num = 5;
	vector <int> scores;
	int input;
	int sum;	// 최고점과 최저점을 하나씩 제외한 점수의 합을 총점으로 계산하기 위함
	while (T--)
	{
		scores.clear();
		sum = 0;
		for (int i = 0; i < num; i++)
		{
			cin >> input;
			scores.push_back(input);
		}

		// 5명의 점수들을 정렬.
		sort(scores.begin(), scores.end());
		// 0번째, 4번째 데이터는 버리고, 1번째와 3번째의 점수 차이가 4이상인지 확인.
		if (scores[3] - scores[1] >= 4)
		{
			cout << "KIN\n";
		}
		else
		{
			sum = scores[1] + scores[2] + scores[3];
			cout << sum << "\n";
		}
	}

	return 0;
}
