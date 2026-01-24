#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 1100 문제: 하얀 칸


int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 8x8 체스판
    // [0,0]: 하얀색

    int N = 8;
    vector <vector<char>> chess(N, vector<char>(N));
    // 체스판 입력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> chess[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // i가 0, 2, 4... 일 때, j가 0, 2, 4.. 인 부분 == 하얀색 칸
            if (((i == 0) || (i % 2 == 0)) && ((j == 0) || j % 2 == 0))
            {
                if (chess[i][j] == 'F')
                {
                    count++;
                }
            }
            else if ((i % 2 == 1) && (j % 2 == 1))  // i가 1, 3, 5... 일 때, j가 1, 3, 5... 인 부분 == 하얀색 칸
            {
                if (chess[i][j] == 'F')
                {
                    count++;
                }
            }
        }
    }

    cout << count;


    return 0;
}