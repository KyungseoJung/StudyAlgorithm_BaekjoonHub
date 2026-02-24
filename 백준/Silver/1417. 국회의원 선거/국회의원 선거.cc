#include <iostream>
#include <vector>

using namespace std;
int main()
{
	// 다른 모든 사람의 득표수보다 많이 받았을 때 우승하는 것!
	// 즉, 1번 후보의 득표수가 무조건 최댓값이 되어야 함.

	int N;
	cin >> N;

	int max = 0;
	int maxEle = 0;
	vector <int> nums(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	int peopleNum = 0;
	// 매수해야 하는 사람 체킹 시작 -------------
	while (true)
	{
		// 최대 득표수와, 최대 득표수를 가진 사람 확인하기 -----------------------
		max = 0;
		for (int i = 0; i < N; i++)
		{
			if (nums[i] >= max)// 동점이면 가장 뒷번호가 maxEle가 되도록 (그래야 다솜이가 혼자 독보적 1위일 때 maxEle가 자동으로 다솜이가 됨. 
				// 즉, 이렇게 해야 별개 처리를 안해줘도 됨)
			{
				maxEle = i;
				max = nums[i];
			}
		}

		if (maxEle == 0)	// 만약 다솜이가 현재 1등이라면
		{
			//cout << "다솜이가 이제 1등~\n";
			break;
		}
		else
		{
			// 최대 득표수를 갖고 있는 사람의 표 하나를 매수하기 -> 다솜이에게 +1
			max--;
			nums[maxEle]--;
			nums[0]++;
			peopleNum++;
		}
	}

	cout << peopleNum;

}