#include <iostream>
#include <vector>
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
using namespace std;
// 11944번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string N;
	int M;
	cin >> N >> M;

	int count = 0;
	
	for(int i=0; i<stoi(N); i++)
	{
		for (int j = 0; j < N.length(); j++)
		{
			if (count >= M)
			{
				return 0;
			}
			cout << N[j];
			count++;
		}
	}

}