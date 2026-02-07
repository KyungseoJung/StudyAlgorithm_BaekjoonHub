#include <iostream>
#include <vector>

using namespace std;

// 1267번 문제: 핸드폰 요금
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int YTime = 30;
	int YChargePerTime = 10;
	int MTime = 60;
	int MChargePerTime = 15;
	int input;
	int charge;

	int YCharge = 0;
	int MCharge = 0;
	while (N--)
	{
		cin >> input;
		YCharge += ((input / YTime) + 1) * YChargePerTime;
		//cout << "YCharge : "<< YCharge << "\n";;
		MCharge += ((input / MTime) + 1) * MChargePerTime;
		//cout << "MCharge : " << MCharge << "\n";;
	}


	if (YCharge > MCharge)
	{
		cout << "M " << MCharge;
	}
	else if (MCharge > YCharge)
	{
		cout << "Y " << YCharge;
	}
	else
	{
		cout << "Y M " << YCharge;
	}
}
