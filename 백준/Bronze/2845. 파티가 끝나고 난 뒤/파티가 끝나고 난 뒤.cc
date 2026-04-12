#include <iostream>
#include <vector>

using namespace std;
// 2845번 문제: 파티가 끝나고 난 뒤
int main()
{
	int L, P;
	cin >> L >> P;
	int peopleNum = L * P;
	
	int N = 5;
	vector <int> countNums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> countNums[i];
	}

	// 차이 출력
	for (int i = 0; i < N; i++)
	{
		cout << countNums[i] - peopleNum << " ";
	}

	return 0;
}