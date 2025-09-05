#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
	int A, B;
	cin >> A >> B;

	vector <int> ele(B+ 1);	// ele[i] : i번째로 몇 번째 숫자가 들어있나	// ele[0]은 의미 없는 값.
	int count = 0;		// 특정 숫자가 ele 벡터로 몇 번 입력되었는지 체크
	int criterionNum = 1;	// 기준이 되는 숫자
	for (int i = 1; i <= B; i++)
	{
		if (count >= criterionNum)
		{
			criterionNum++;
			count = 0;
		}
		ele[i] = criterionNum;
		
		count++;
	}


	vector <int> sums(B + 1);	// sums[i] : 1번째부터 i번째 원소까지 더한 값	// sums[0]은 의미 없는 값.
	sums[0] = 0;

	for (int i = 1; i <= B; i++)
	{
		sums[i] = sums[i - 1] + ele[i];
	}
	
	cout << sums[B] - sums[A-1];	// A번째 숫자부터 B번째 숫자까지 더하려면, B까지 더한 합 - (A-1)까지 더한 합
	return 0;
}