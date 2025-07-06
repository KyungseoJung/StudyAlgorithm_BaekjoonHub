#include <iostream>
#include <vector>

using namespace std;
int returnGCD(int A, int B)
{
	int min = (A > B) ? B : A;
	for (int i = min; i > 0; i--)
	{
		if ((A % i == 0) && (B % i == 0))
		{
			//std::cout << "GCD return: " <<  i<< "\n";
			return i;
		}
	}
}
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;	// 이미 심어져 있는 가로수의 수
	cin >> N;
	vector <long long int> pos(N);

	int posMem;
	for (int i = 0; i < N; i++)	// 각 가로수 위치 입력 ----------------------
	{
		cin >> posMem;
		pos[i] = posMem;
	}

	// 각 가로수 간격 저장----------------------
	vector <long long int> diff(N - 1);
	for (int i = 0; i < pos.size()-1; i++)
	{
		diff[i] = pos[i + 1] - pos[i];
	}

	long long int gcd;	// 가로수의 간격 찾기 (각 가로수의 간격의 공통 최대 공악수)(어쩔 수 없이, 2개 숫자끼리 비교해가며 최대공약수 구해보자)
	// 1번째 최대공약수 먼저 찾아주기
	gcd = returnGCD(diff[0], diff[1]);

	for (int i = 1; i < diff.size()-1; i++)
	{
		gcd = returnGCD(gcd, diff[i + 1]);
	}
	//cout << gcd << "\n";



	int answer = 0;	// 가로수 간격을 기반으로 -> 최소 심어야 하는 가로수 개수 찾기------------------------
	for (int i = 0; i < N-1; i++)
	{
		answer += (pos[i + 1] - pos[i])/gcd - 1;
	}

	std::cout << answer;

	return 0;
}