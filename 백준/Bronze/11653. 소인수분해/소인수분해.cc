#include <iostream>
#include <vector>
int main()
{
	int N;	// 정수 주어짐
	std::cin >> N;

//	int member[10000];	// 소인수분해 요소들 저장할 array
	std::vector <int> member(10000000);
	int ele = 0;

	while (N != 1)
	{
//		std::cout << "시작 --------" << "\n";
		for (int i = 2; i <= N; i++)
		{
			if (N % i == 0)
			{
				N = N / i;
				member[ele] = i;
				ele++;
//				std::cout << "mem: " << i << "\n";
				break;
			}
		}
//		std::cout << "끝 ----------" << "\n";
	}

	for (int i = 0; i < ele; i++)
	{
		std::cout << member[i] << "\n";
	}
    
    return 0;
}