#include <iostream>

int main()
{
	int num = 9;	// 입력할 자연수 개수
	int member;
	int max = 0;	// 최댓값 저장할 변수
	int maxNum = 0;	// 최댓값 숫자가 몇 번째 숫자인지
	int arr[9];		// 최댓값 저장할 변수

	for (int i = 0; i < num; i++)
	{
		std::cin >> arr[i];
		if (arr[i] > max)
		{
			max = arr[i];
			maxNum = i+1;
		}
	}

	std::cout << max << "\n" << maxNum;

}