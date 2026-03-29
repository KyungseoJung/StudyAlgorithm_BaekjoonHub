#include <iostream>
#include <iomanip>	

using namespace std;
int main()
{
	long long int A, B, C;
	cin >> A >> B >> C;
	
	// A + B * n < C * n이 되는 n을 찾기
	// 1) 답이 없는 경우: 만약 (C-B)*n이 음수라면
	if (C - B <= 0)
	{
		cout << -1;
	}
	else
	{
		long long int criterion;
		criterion = A / (C - B);
		//cout << criterion << "\n";
		long long int num = criterion + 1;
		cout << num;
	}
	return 0;

}