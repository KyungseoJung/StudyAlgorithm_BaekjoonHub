#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
//#include <cctype>

//#10832번 문제
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 일단 숫자들 따로 받아서 vector에 넣기 ----------------------
	string input;
	getline(cin, input);

	stringstream ss(input);	// input을 그대로 ss 에 넣기
	string token;
	vector <string> tokens;
	while (getline(ss, token, ','))
	{
		tokens.push_back(token);
	}

	//// 숫자들이 정수인지 확인 ----------------------
	//int count = 0;
	//for (int i = 0; i < tokens.size(); i++)
	//{
	//	if (tokens[i] % 1 == 0)
	//	{
	//		count++;
	//	}
	//}

	cout << tokens.size();
	return 0;

}
