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
// 1259 문제: 팰린드롬수


int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string input;
    bool pelindrom;
    while (true)
    {
        pelindrom = true;
        cin >> input;
        if (input == "0")
        {
            return 0;
        }
        for (int i = 0; i < (input.length() / 2); i++)
        {
            if (input[i] != input[input.length() - i - 1])
            {
                pelindrom = false;
                break;
            }
        }

        if (pelindrom == false)
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
    }

    //return 0;
}