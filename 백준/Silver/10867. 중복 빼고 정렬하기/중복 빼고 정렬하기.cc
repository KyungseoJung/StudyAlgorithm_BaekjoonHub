#include <iostream>
#include <vector>
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 10867번 문제.
//** set: 자동으로 중복된 요소 무시. 자동으로 정렬됨
//** 출력할 땐, i번째 요소에 일일이 직접 접근 X -> for(int val: sets) -> val을 다 출력

int main()
{
	// 코드 속도 빠르게 하기 위한 설정
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	// 중복을 자동으로 제거하도록
	set <int> sets;
	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		sets.insert(input);	// 중복된 수는 자동으로 무시 && 자동으로 정렬되어 삽입됨
	}


	// 출력
	for (int val : sets)
	{
		cout << val << " ";
	}
	return 0;
}