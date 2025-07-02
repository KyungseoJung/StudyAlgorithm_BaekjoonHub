#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int M, N;
	std::cin >> M >> N;
	vector <int> answer(N - M + 1);
	int decimal = 0;
	int member = 0;

	for (int i = M; i <= N; i++)
	{
		//if (i % 2 == 0)	// 짝수로 안 나누어지면
		//	continue;
		//for (int j = 1; j < N; j += 2)	// 홀수로 나눠보기
		//{
		//	if (i % j == 0)
		//		continue;
		//}
		decimal = 0;	// i의 decimal 개수 세기
		for (int j = 1; j <= N; j++)	// 2부터 N까지의 숫자로 모두 나눠보기 // 끝까지 어떤 수로도 나눠지지 않는다면 아래 코드 실행
		{
			if (i % j == 0)
			{
				decimal++;
			}
		}
		if (decimal == 2)	// 1과 자기자신 뿐이라면
		{
			answer[member] = i;
			member++;
		}

		decimal = 0;	// 다음 수 체크를 위해 decimal 초기화
	}

	int sum = 0;
	if (member == 0)	// 소수가 아예 없다면
	{
		std::cout << "-1";
		return 0;
	}

	// 소수가 하나라도 있다면
		for (int i = 0; i < member; i++)
		{
			sum += answer[i];
		}

		std::cout << sum << "\n" << answer[0];

		return 0;

}