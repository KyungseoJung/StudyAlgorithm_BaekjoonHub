#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);	// C++의 cin/cout은 기본적으로 C의 scanf/printf와 **끊임없이 “전화 통화”(동기화)**를 하며 데이터를 주고받습니다.
										// 해결-> 전화 통화 중단 역할 (코드 한 줄로 cin/cout이 C의 입·출력과 대화를 그만두게 만드는 겁니다.)
										// 결과: cin / cout만 단독으로 작동하니 훨씬 가벼워져요.
	std::cin.tie(nullptr);				// 기본 설정에선 cin이 입력을 받을 때마다 “출력 버퍼(cout)를 비워라!” 라고 명령합니다.
										// 비유: 편지를 보낼 때마다 우체국에 들러 “버퍼” 우편함을 비우고 가는 것
										// 해결-> 이 과정을 끊으면(untie), 편지(데이터)를 한꺼번에 보냄 -> 대기 시간이 줄어듭니다.

	int num;
	std::cin >> num;

	int a, b;

	for (int i = 0; i < num; i++)
	{
		std::cin >> a >> b;
		std::cout << (a + b) << "\n";
	}

	return 0;
}