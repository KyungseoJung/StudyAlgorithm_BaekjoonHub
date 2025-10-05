#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>	// #pow 사용
#include <string>	// # to_string 함수

using namespace std;
// 5671번 문제.

bool checkLuckyRoom(int roomNum)
{
	string roomNumString = to_string(roomNum);
	int length = roomNumString.length();

	vector <int> member;
	int eachMember;	// 각 숫자의 100자릿수, 10자릿수, 1자릿수 멤버 하나씩 넣는 용도
	for (int i = length; i>0; i--)
	{

		eachMember = roomNum / pow(10, i - 1);
		//cout << "roomNum: " << roomNum << ", eachMember: " << eachMember << "\n";
		
		roomNum = roomNum - eachMember * pow(10, i - 1);
		member.push_back(eachMember);
	}

	// 각 숫자가 겹치는지 확인하기
	for (int i = 0; i < member.size()-1; i++)
	{
		for (int j = i + 1; j < member.size(); j++)
		{
			if (member[i] == member[j])
			{
				//cout << member[i] << " " << member[j] << ": 둘이 같음\n";
				member.clear();
				return false;
			}
		}
	}

	member.clear();
	// 위 for문에서 같은 숫자가 하나도 없었다면
	return true;

}

int main()
{
	int N, M;
	int count;
	while (cin >> N >> M)
	{
		count = 0;
		for (int i = N; i <= M; i++)
		{
			if (checkLuckyRoom(i) == true)
			{
				count++;
			}
		}

		cout << count << "\n";
	}
}
