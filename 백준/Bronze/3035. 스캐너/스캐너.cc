#include <iostream>
#include <vector>
#include <cmath>	// sqrt 함수
#include <algorithm>
#include <sstream>	// stringstream
#include <string>	// stoi 함수
#include <cctype>	// isdigit 함수/ isupper, islower 함수 (소문자인지, 대문자인지 확인)
#include <unordered_set>	// unordered_set 함수 사용 목적
//#3035번 문제

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int R, C, ZR, ZC;
	cin >> R >> C >> ZR >> ZC;

	char arr[50][50];
	vector <vector <char>> vec(R, vector <char>(C));
	char input;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> input;
			vec[i][j] = input;
		}
	}

	// 출력
	// 행을 ZR번 반복해서 출력. 열을 ZC번 반복해서 출력
	for (int i = 0; i < R; i++)
	{

		// 한 행을 마치고 나서, 그 행을 똑같이 ZR번 반복해서 또 출력하기.
		for (int row = 0; row < ZR; row++)
		{
			for (int j = 0; j < C; j++)
			{
				// 각 행에 대해서 출력할 때, ZC번 반복해서 더 출력하기
				for (int col = 0; col < ZC; col++)
				{
					cout << vec[i][j];
				}
			}
			cout << "\n";
		}
	}

	return 0;

}
