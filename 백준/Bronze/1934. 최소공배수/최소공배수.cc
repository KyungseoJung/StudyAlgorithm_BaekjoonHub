#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int divisor(int A, int B)
{
	// 최대 공약수 출력하는 함수
	int min = (A > B) ? B: A;
	for (int i = min; i >0; i--)
	{
		if ((A % i == 0) && (B % i == 0))
			return i;
	}

}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	//**** 최대공약수와 최소공배수의 관계
	// 최대공약수 * 최소공배수 = 두 수의 곱
	// 즉, 최소공배수 = 두 수의 곱 / 최대공약수

	int T;	// 테스트의 개수
	std::cin >> T;

	int A, B;
	int divisorNum;
	vector<int> answer(T);	// 출력할 답의 개수
	
	for (int i = 0; i < T; i++)
	{
		std::cin >> A >> B;
		divisorNum = divisor(A, B);

		answer[i] = (A * B) / divisorNum;

	}

	for (int i = 0; i < T; i++)
	{
		std::cout << answer[i] << "\n";
	}
	
	return 0;
}