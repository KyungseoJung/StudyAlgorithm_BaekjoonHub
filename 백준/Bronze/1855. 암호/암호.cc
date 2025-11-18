#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isincreaseper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#1855번 문제
// getline, stringstream, 
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string input;
	cin >> input;

	int rows = ((input.length() - 1) / N) + 1;	// 행의 크기 미리 지정
	vector<vector<char>> nums(rows, vector <char>(N));	// rows X N 크기의 행렬 완성

	// 입력한 알파벳 넣기
	int row = 0;
	int col = 0;
	int ele = 0;	// input할 알파벳이 몇 번째 알파벳인지
	bool increase = true;	// 현재 col이 증가해야 하는 상태인지, 감소해야 하는 상태인지 설정 및 확인

	while (true)
	{
		if (ele >= input.length())	// 모든 원소들을 다 행렬 안에 넣었다면 그만 멈추기
		{
			break;
		}
		// 행은 차례대로 1줄씩 증가
		nums[row][col] = input[ele];
		// 열은 조금 신경써서 바꿔줘야 함. 0, 1, 2/ 2, 1, 0/ 0, 1, 2 순서로 바뀜
		if ((increase == true) && (col < N-1))
		{
			col++;
		}
		else if ((increase == true) && col == N-1)
		{
			//col 그대로 유지하고, 다음 행으로
			increase = false;
			row++;
		}
		else if ((increase == false) && (col > 0))
		{
			col--;
		}
		else if ((increase == false) && (col == 0))
		{
			//col 그대로 유지하고, 다음 행으로
			increase = true;
			row++;
		}

		ele++;	
		
	}

	// 출력하기
	// 각 col별로
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < ((input.length() - 1) / N) + 1; j++)
		{
			cout << nums[j][i];
		}
	}
	return 0;

}
