#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isincreaseper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#10833번 문제: 사과

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int stu, apple;
	int rest = 0;

	while (N--)
	{
		cin >> stu >> apple;
		rest += ( apple % stu);
	}

	cout << rest;
	
	return 0;

}
