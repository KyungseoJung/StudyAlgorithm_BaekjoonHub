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
// 5054 문제: 주차의 신

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    int n;

    vector <int> positions;
    int sum = 0;
    int centerPos;
    int walking = 0;
    int diff;


    for (int i = 0; i < t; i++)
    {
        cin >> n;

        positions.assign(n, 0); // 크기는 n으로 내부 원소들은 모두 0으로 만들기
        sum = 0;
        centerPos = 0;
        walking = 0;
        diff = 0;

        int min = 999;
        int max = -1;
        for (int j = 0; j < n; j++)
        {
            cin >> positions[j];
            sum += positions[j];

            if (positions[j] < min)
            {
                min = positions[j];
            }
            if (positions[j] > max)
            {
                max = positions[j];
            }
        }

        centerPos = sum / n;

        // centerPos에서 차 대고 출발해서, min으로 가, max까지 쇼핑하고, max에서 centerPos로 돌아가기
        walking = (max - min) + (centerPos - min) + (max - centerPos);
        cout << walking << "\n";
    }

    
    return 0;
}