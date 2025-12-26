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
// 1452 문제: 누울 자리를 찾아라

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector <vector<char>> room(N, vector<char>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> room[i][j];
        }
    }

    //** 주의해야 할 점: 한 줄에 여러 개의 잘 수 있는 공간이 있을 수 있다는 점
    // 예를 들어 ..X.. 이렇게 되어있으면 잘 수 있는 공간은 한 줄에 2개가 됨
    // .....X 이렇다면 1개이겠지만.
    
    // 이제 i행은 누울 수 있는 것으로 판단되었으므로, 검사 더이상 안해도 됨 -->> 위의 논리 때문에, 이건 틀린 말임!!!

    // 가로로 누울 수 있는 곳 확인하기
    int rowCount = 0;
    int countEmpty;
    for (int i = 0; i < N; i++)
    {
        countEmpty = 0;
        for (int j = 0; j < N; j++)
        {
            if (room[i][j] == '.')
            {
                countEmpty++;
            }
            else
            {
                countEmpty = 0;
            }

            if (countEmpty == 2)    // 2개일 때만 카운팅하기. 3개 이상부터는 추가로 카운팅하는 의미가 없음
            {
                rowCount++;
            }
        }
    }

    // 세로로 누울 수 있는 곳 확인하기
    int colCount = 0;
    for (int j = 0; j < N; j++)
    {
        countEmpty = 0;
        for (int i = 0; i < N; i++)
        {
            if (room[i][j] == '.')
            {
                countEmpty++;
            }
            else
            {
                countEmpty = 0;
            }

            if (countEmpty == 2)
            {
                colCount++;
            }
        }
    }

    cout << rowCount << " " << colCount;
    return 0;
}