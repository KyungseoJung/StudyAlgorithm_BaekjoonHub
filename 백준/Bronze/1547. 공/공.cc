#include <iostream>
#include <vector>
using namespace std;
// 1547번 문제: 공
int main()
{
	int N;
	cin >> N;
	int cupNum = 3;	// 컵의 개수는 3개
	vector <int> checkBall(cupNum+1, 0);	// 1,2,3번 컵에 각각 공이 있는지 없는지 확인
	// 0이면 공이 없는 것. 1이면 공이 있는 것.
	checkBall[1] = 1;	// 처음에는 1번 컵에 공이 있도록 하기

	int cup1, cup2;
	int temp = 0;
	while (N--)
	{
		cin >> cup1 >> cup2;
		//cout << cup1 << "번 컵과 " << cup2 << "번 컵을 바꿔치기 \n";
		//cout << cup1 << "컵은 공이 있나? : " << checkBall[cup1] << "\n";
		//cout << cup2 << "컵은 공이 있나? : " << checkBall[cup2] << "\n";

		temp = checkBall[cup1];
		checkBall[cup1] = checkBall[cup2];
		checkBall[cup2] = temp;
	}

	// 공이 어디있나 확인~~
	for (int i = 1; i < cupNum + 1; i++)
	{
		if (checkBall[i] == 1)
		{
			cout << i;
			return 0;
		}
	}
}