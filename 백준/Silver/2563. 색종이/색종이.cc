#include <iostream>

int main()
{
	int paperNum;	// 첫째 줄에 색종이의 수가 주어짐
	std::cin >> paperNum;

	int arr[100][100] = { 0 };	// 검은색 종이의 넓이 확인용 array

	//std::cout << arr[0][0] << " | " << arr[1][1] << " | " << arr[100][100];
	int x, y;
	//int overlap = 0;	// 겹친 부분 파악	// 파악할 필요 자체가 없어

	// 목표: 색종이가 붙은 검은 영역의 넓이를 출력하기 (즉, 전체 검은 종이 개수*100 - 겹친 부분 넓이)
	for (int i = 0; i < paperNum; i++)
	{
		std::cin >> x >> y;
		for (int j = 0; j < 10; j++)	// 좌표가 아니라, 크기 1에 해당하는 정사각형 중심에 점을 찍는다고 생각
		{
			for (int k = 0; k < 10; k++)
			{
				arr[x + j][y + k] = 1;	// 검은 종이가 있는 부분은 1로 설정
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1)
			{
				sum += 1;
			}
		}
	}

	std::cout << sum;
}