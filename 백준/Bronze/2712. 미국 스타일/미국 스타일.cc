#include <iostream>
#include <iomanip>	// setprecision 사용하기 위함?

using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	float num;
	float changeNum;
	string unit;
	while (N--)
	{
		cin >> num;
		cin >> unit;

		if (unit == "kg")
		{
			changeNum = num * 2.2046;
			cout << fixed << setprecision(4) << changeNum << " lb\n";
		}
		else if (unit == "lb")
		{
			changeNum = num * 0.4536;
			cout << changeNum << " kg\n";
		}
		else if (unit == "l")
		{
			changeNum = num * 0.2642;
			cout << changeNum << " g\n";
		}
		else if (unit == "g")
		{
			changeNum = num * 3.7854;
			cout << changeNum << " l\n";
		}

	}
}