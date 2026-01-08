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
// 30030 문제: 스위트콘 가격 구하기

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string name;
    int score;
    int N;
    cin >> N;
    while (N--)
    {
        cin >> name >> score;

        if (score >= 97)
        {
            cout << name << " A+\n";
        }
        else if (score >= 90)
        {
            cout << name << " A\n";
        }
        else if (score >= 87)
        {
            cout << name << " B+\n";
        }
        else if (score >= 80)
        {
            cout << name << " B\n";
        }
        else if (score >= 77)
        {
            cout << name << " C+\n";
        }
        else if (score >= 70)
        {
            cout << name << " C\n";
        }
        else if (score >= 67)
        {
            cout << name << " D+\n";
        }
        else if (score >= 60)
        {
            cout << name << " D\n";
        }
        else if (score >= 0)
        {
            cout << name << " F\n";
        }

    }


    return 0;
}