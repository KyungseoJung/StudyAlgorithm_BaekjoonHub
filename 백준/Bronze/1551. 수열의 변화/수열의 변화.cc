#include <iostream>
#include <vector>
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
using namespace std;
// 1551번 문제.

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	// 숫자들 입력받기 시작 ----------------------------
	cin.ignore();	// 버퍼의 개행문자 무시
	string line;
	// 한 줄 전체를 입력받음
	getline(cin, line);

	// 입력받은 문자열을 stringstream 객체에 넣음
	stringstream ss(line);
	string token;
	vector <string> tokens;

	while (getline(ss, token, ','))
	{
		tokens.push_back(token);
	}
	// 숫자들 입력받기 끝----------------------------
	vector <int> nums(N);

	// 일단 그대로 숫자 배열에 넣기
	for (int i = 0; i < N; i++)
	{
		nums[i] = stoi(tokens[i]);
	}

	// K번 반복하기 
	int size = N;
	while (K--)
	{
		//cout << "차원 축소------" << "\n";
		for (int i = 0; i < size-1; i++)
		{
			nums[i] = nums[i + 1] - nums[i];
			//cout << "nums[" << i << "]: " << nums[i] << "\n";
		}
		size -= 1;
	}

	// 출력
	for (int i = 0; i < size; i++)
	{
		if (i == (size-1))
		{
			cout << nums[i] ;
		}
		else
		{
			cout << nums[i] << ",";
		}
	}

	return 0;
}