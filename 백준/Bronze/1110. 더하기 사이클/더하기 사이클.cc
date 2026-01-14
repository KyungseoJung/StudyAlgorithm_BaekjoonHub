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
// 1110 문제: 더하기 사이클

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int firstNum;
    cin >> firstNum;

    int num = -1; // num: 현재 사용하고 있는 숫자 (처음에는 while문을 작동시키기 위해 -1로 임시로 설정)
    int num1, num2; // 1의 자리수, 10의자리수
    int sum;    // 1의 자리수와 10의 자리수를 더한 값

    int cycle = 0;  // 사이클 횟수 카운팅

    while (num != firstNum)
    {
        if (cycle == 0)
        {
            num = firstNum;
        }
        if (num >= 10)
        {
            num1 = num / 10;
            num2 = num % 10;
        }
        else if (num < 10)
        {
            num1 = 0;
            num2 = num % 10;
        }

        sum = num1 + num2;
        
        num = num2 * 10 + (sum % 10);
        cycle++;
    }

    cout << cycle;
    
    return 0;
}