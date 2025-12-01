#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isincreaseper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#2857번 문제: FBI

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 5;
	string inputName;
	vector <int> FBIMember;
	for(int i=0; i<N; i++)
	{
		cin >> inputName;
		for (int j = 0; j < inputName.length()-2; j++)
		{
			if ((inputName[j] == 'F') && (inputName[j+1] == 'B') && (inputName[j+2] == 'I'))
			{
				FBIMember.push_back(i+1);
				break;	// 한번 발견하면 이제 그만 찾고, 다음 inputName 검사하기
				// **** 이게 필수인 이유는, FBI-2FBI 같이 이름에 FBI가 2번 들어갈 수 있기 때문임
			}
		}
	}

	if (FBIMember.size() == 0)	// FBI 멤버가 한 명도 없다면
	{
		cout << "HE GOT AWAY!";
	}
	else
	{
		for (int i = 0; i < FBIMember.size(); i++)
		{
			cout << FBIMember[i] << " ";
		}
	}
	return 0;

}
