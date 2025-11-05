#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#3052번 문제
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A, B;
	int num = 10;
	int criterion = 42;	// 기준 숫자: 42
	vector <int> input(10);
	vector <int> count(43, 0);	// 0부터 42까지의 수. 나머지로 나왔다면 1로 체크. 
	
	// 값 입력 =====================
	for (int i = 0; i < num; i++)
	{
		cin >> input[i];
		// 나머지 체크 =====================
		int ele = input[i] % criterion;
		if (count[ele] == 0)
		{
			count[ele] = 1;
		}
	}

	// 얼마나 다양한 나머지가 있었나 확인=====================
	int countHowDifferent= 0;
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i] == 1)
		{
			countHowDifferent++;
		}
	}

	cout << countHowDifferent;

	return 0;

}
