#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main()
{
	int N;
	cin >> N;

	int count = 0;
	for (int B = 1; B <= 500; B++)	// B 서치에 대한 for문
	{
		for (int A = B; A <= 500; A++)	// A 서치에 대한 for문 (B <= A <= 500)
		{
			if (pow(A, 2) - pow(B, 2) == N)	// 쌍이 존재한다면 count++
			{
				count++;
			}
		}
	}

	cout << count;
	return 0;

}