#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int T;	// 테스트 데이터 개수
	cin >> T;

	int H, W, N;
	int height;
	int roomNum;
	while (T--)
	{
		cin >> H >> W >> N;

		if ((N % H) == 0)	// 완벽하게 맞아 떨어지면, 가장 높은 층의 방에 배치
		{
			height = H;
			roomNum = N / H;
			// 방번호는 H만큼씩 커지니까 (1열 채우고, 2열 채우고)
		}
		else
		{
			height = (N % H);	// 나누었을 때의 나머지
			roomNum = (N / H) + 1;	// 나누었을 때의 몫에 +1한 값
		}

		if (roomNum < 10)
		{
			cout << height << "0" << roomNum << "\n";
		}
		else
		{
			cout << height << roomNum << "\n";
		}
	}

	return 0;
}