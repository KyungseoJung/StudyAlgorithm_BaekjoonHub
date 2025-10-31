#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#10984번 문제
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T, N;
	cin >> T;

	int inputC;
	double inputG;
	int sumC;
	double sumScore;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		sumC = 0;
		sumScore = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> inputC >> inputG;
			sumC += inputC;
			sumScore += inputG * inputC;
		}
		cout << sumC << " " << (double)(sumScore / sumC) << "\n";
	}
	return 0;
}
