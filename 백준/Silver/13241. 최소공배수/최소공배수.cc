#include <iostream>
#include <algorithm>

using namespace std;

int returnDivisor(int A, int B)	// 최대공약수 리턴
{
	int min = (A > B) ? B : A;	// 최대공약수는 두 수 중 더 작은 값보다는 이하이기 때문에 min을 이용해서 for문 실행할 것임
	
	for (int i = min; i >= 1; i--)
	{
		if ((A % i == 0) && (B % i == 0))
		{
			return i;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 두 수의 곱은 최대공약수 * 최소공배수	(최대공약수가 없다면, 1로 취급)
	long long int A, B;
	std::cin >> A >> B;

	int divisor = returnDivisor(A, B);

	std::cout << (A * B) / divisor;

	return 0;


}