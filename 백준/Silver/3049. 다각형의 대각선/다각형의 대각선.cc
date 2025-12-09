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
// 3049번 문제: 다각형의 대각선

int factorial(int num)
{
	int output = 1;
	for (int i = 1; i <= num; i++)
	{
		output = output * i;
	}

	return output;
}
int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	// 도형: 대각선 개수 -> 교차점 개수
	// 삼각형: 0개 -> 0
	// 사각형: 2개 (1 + 1 + 0 + 0)-> 1 
	// 오각형: 5개 (2 + 2 + 1 + 0 + 0)-> 5
	// 육각형: 9개 (3 + 3 + 2 + 1 + 0 + 0)-> 15

	// 대각선 개수:  0 -> (0+2) -> (2+3) -> (5+4) : 2개, 3개, 4개씩 더해짐
	
	//**** 아이디어 gpt한테 물어봄..ㅠㅠ
	// 사각형에서의 대각선 개수는 2개. 교차점은 1개.
	// 즉, 어떤 도형에서든 사각형 종류의 개수를 세면 됨. 
	//**** (대각선 하나하나는 겹칠 수 있어도, 그 2가지 대각선의 조합은 그 사각형에서만 발견되는 것. So, 대각선 교차점은 겹치지 않는다는 게 포인트)
		// ex) 오각형: 사각형이 5개 만들어질 수 있음. -> 대각선 교차점 5개.
		// ex) 육각형: 사각형이 6_C_4 (=15)개 만들어질 수 있음. -> 대각선 교차점 15개.
	int n;
	cin >> n;

	if (n < 4)
	{
		cout << 0;
	}
	else
	{
		int denominator = 1;
		for (int i = n; i > n - 4; i--)
		{
			denominator = denominator * i;
		}

		int answer = denominator / factorial(4);
		cout << answer;
	}

	return 0;
}