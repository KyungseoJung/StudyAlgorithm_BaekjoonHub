#include <iostream>
#include <vector>
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
using namespace std;
// 11094번 문제.
	// 헷갈림
	// cin.ignore
	// getline
	// stringstream


int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	cin.ignore();	//** 개행 문자 무시 **
	vector <string> tokens;	// 단어 저장용 벡터

	for (int i = 0; i < N; i++)
	{
		string input;
		getline(cin, input);

		// "Simon says"로 시작하면, 그 뒤(인덱스 10)부터 그대로 출력
		if (input.rfind("Simon says", 0) == 0) {
			cout << input.substr(10) << "\n";
		}
	}


	return 0;
}