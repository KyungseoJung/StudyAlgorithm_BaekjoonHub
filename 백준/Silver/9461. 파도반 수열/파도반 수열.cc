#include <iostream>
#include <vector>

using namespace std;

// 동적 프로그래밍. 그 중 Bottom-up 방식

int main()
{
	int caseNum;
	cin >> caseNum;

	while (caseNum--)
	{
		int N;
		cin >> N;
		vector <long long int> P(N);
		P[0] = 1;
		P[1] = 1;
		P[2] = 1;

		for (int i = 3; i < N; i++)
		{
			P[i] = P[i - 3] + P[i - 2];
		}
		
		cout << P[N - 1] << "\n";
	}


	return 0;
}