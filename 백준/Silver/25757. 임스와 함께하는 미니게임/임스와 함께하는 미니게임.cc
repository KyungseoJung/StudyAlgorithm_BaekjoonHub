#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isupper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#25757번 문제

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	char gameType;
	cin >> N >> gameType;

	// 사람들 정보 입력
	//vector <string> names;
	unordered_set <string> names;
	names.reserve(N * 2);	// 넉넉하게 크기 잡아놓기
	
	string inputName;
	//bool alreadyRegister;
	for (int i = 0; i < N; i++)
	{
		cin >> inputName;
		names.insert(inputName);	// unordered_set 을 사용하면 자동으로 중복 데이터를 제거해준대
		//alreadyRegister = false;
		//for (int j = 0; j < names.size(); j++)
		//{
		//	if (names[j] == inputName)
		//	{
		//		alreadyRegister = true;
		//	}
		//}
		//if (alreadyRegister == false)
		//{
		//	names.push_back(inputName);
		//}
	}

	int peopleNum = names.size();	// unique한 사람들의 숫자 (사람들이 몇 명인지 카운팅한 것)

	int numOfNeedMore;	// 임스를 제외한 추가로 필요한 사람의 숫자
	switch (gameType)
	{
	case 'Y':
		numOfNeedMore = 1;
		cout << peopleNum / numOfNeedMore;
		break;

	case 'F':
		numOfNeedMore = 2;
		cout << peopleNum / numOfNeedMore;
		break;

	case 'O':
		numOfNeedMore = 3;
		cout << peopleNum / numOfNeedMore;
		break;
	}

	return 0;

}
