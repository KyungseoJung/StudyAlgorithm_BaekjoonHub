#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N;
	std::cin >> N; // 첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000) //이 수는 10,000보다 작거나 같은 자연수
	int inputNum;
	int input[10001] = { 0 };	// 0부터 10,000의 숫자가 각각 몇 번 입력되었는지 저장

	// 테스트용 코드
	//input[0]++;
	//std::cout << input[0];

	for (int i = 0; i < N; i++)
	{
		std::cin >> inputNum;
		input[inputNum]++;
	}
	
	for (int i = 0; i <= 10000; i++)
	{
		for (int j = 0; j < input[i]; j++)
		{
			std::cout << i << "\n";
		}
	}

	return 0;
}