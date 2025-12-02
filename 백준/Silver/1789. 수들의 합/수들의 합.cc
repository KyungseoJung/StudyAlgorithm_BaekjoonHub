#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isincreaseper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#1789번 문제: 수들의 합

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long int S;
	cin >> S;

	// 1, 2, 3, ... 순서대로 더했을 때, S보다 커지면 멈추기 (S보다 작을 때까지 더한 개수를 출력하기. 어차피 마지막 수는 이미 더했던 숫자와 중복될 테니까)

	long long int sum = 0;
	//if ((S == 1) || (S == 2))	// 1과 2는 아래 for문을 너무 조금 돌아서 따로 예외 처리해주기
	//{
	//	cout << 1;
	//}
	//else
	{
		for (int i = 1; i < S+10; i++)	// 넉넉하게 그냥 +10만큼해주기 (1,2,3 같이 작은 숫자들은 for문을 너무 조금 돌아서)
		{
			sum += i;
			if (sum > S)
			{
				cout << i - 1;
				break;
			}
		}

	}

	//cout << sum;
	
	return 0;

}
