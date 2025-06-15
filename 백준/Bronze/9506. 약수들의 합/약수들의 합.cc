#include <iostream>

int main()
{
	int factor[100000];	// 약수들을 넣는 배열
	int factorNum = 0;
	int sum = 0;
	int num;
	while (1)
	{
		std::cin >> num;
		if (num == -1)
			break;

		factorNum = 0;
		sum = 0;
		//factor[100000] = { 0 };	// 0으로 초기화?

		for (int i = 1; i < 100000; i++)	// 약수를 배열 안에 넣기
		{
			if (num % i == 0)
			{
				factor[factorNum] = i;
				factorNum++;
			}
		}

		// 완전수인지 확인
		// 완전수가 아니라면 if문의 내용만 출력
		// 완전수라면 아래 else문 실행
		for (int i = 0; i < factorNum-1; i++)	// 자기 자신에 해당하는 마지막 약수는 덧셈에서 제외
		{
			sum += factor[i];
		}

		if (sum != num)
			std::cout << num << " is NOT perfect.\n";
		else
		{

			std::cout << num << " = ";
			for (int i = 0; i < factorNum; i++)
			{
				if (i == 0)	// 첫 번째 약수
					std::cout << factor[i];
				else if (i == factorNum - 1)	// 마지막 약수
				{
					std::cout << "\n";
				}
				else
				{
					std::cout << " + " << factor[i];
				}

			}
		}

	}
}