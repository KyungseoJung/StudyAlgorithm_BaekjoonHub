#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int A, int B)
{
	int min = (A > B) ? B : A;
	for (int i = min; i > 0; i--)
	{
		if ((A % i == 0) && (B % i == 0))
		{
			//std::cout << "gcd: " << i << "\n";
			return i;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A1, A2, B1, B2;
	std::cin >> A1 >> A2 >> B1 >> B2;

	int numerator, denominator; // 각각 두 수의 합을 나타내는 분자, 분모
	numerator = (A1 * B2) + (B1 * A2);
	denominator = A2 * B2;

	//std::cout << "numerator: " << numerator << ", denominator: " << denominator << "\n";

	int divisor = gcd(numerator, denominator);

	std::cout << numerator / divisor << " " << denominator / divisor;

	return 0;
}