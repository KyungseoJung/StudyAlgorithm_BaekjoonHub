#include <iostream>

using namespace std;
int main()
{
	int R1, S;
	cin >> R1 >> S;

	// S = (R1 + R2) / 2
	// 2*S = (R1 + R2)
	// R2 = 2 * S - R1
	cout << (S * 2 - R1);
	return 0;

}