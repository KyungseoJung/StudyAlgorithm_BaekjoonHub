#include <iostream>
#include <string>	// getline 함수
#include <vector>

using namespace std;
// 4458번 문제: 첫 글자를 대문자로
int main()
{
	int N;
	cin >> N;
	cin.ignore();	// N입력하면서 엔터치는 거 무시하기

	string st;
	vector <string> sentence;

	for (int i = 0; i < N; i++)
	{
		getline(cin, st);
		st[0] = toupper(st[0]);
		sentence.push_back(st);
	}
	
	// 출력하기
	for (int i = 0; i < N; i++)
	{
		cout << sentence[i] << "\n";
	}

	return 0;
}