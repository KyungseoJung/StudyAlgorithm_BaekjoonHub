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
// 1009 문제: 분산 처리


int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 데이터이의 개수: a^b
    // ex) 3^7 => 3^1=3/ 3^2=9/ 3^3=27(일의 자리 7)/ 3^4=일의자리 1/ 3^5= 일의자리3
    //          3^6= 일의자리 9/ 3^7= 일의자리7
    //          3^10= 일의자리 9
    // 5번 제곱한 것에서 일의자리 숫자가 다시 동일해짐 ->> Cycle = 4
    // 7%4=3 -> 3^7의 일의자리와 3^3의 일의자리는 동일!

    //** 즉 Cycle만큼 나눈 나머지만큼 제곱해준 것과 동일
    //만약 3^100을 물어본다면, 100%4=0 -> 3^4의 일의자리와 동일할 것임
    int T;
    cin >> T;
    int a, b;

    int cycleNum;
    int rememberNum;
    int subtractNum;    // 제곱 계산에 사용하는 수

    int len;    // 일의 자리를 알아내기 위해 사용되는 변수
    char lastNum;   // 일의 자리를 char형태로 저장
    while (T--)
    {
        cin >> a >> b;


        // 복잡한 Cycle 로직 대신 이것만 써도 정답입니다. ->>> 걍 b번 제곱해주기...!!!!
        int result = 1;
        for (int i = 0; i < b; i++) {
            result = (result * a) % 10;
        }

        // 컴퓨터 번호 알아내기----------------------
        int rest = result % 10;
        int computerNum;

        if (rest == 0)
        {
            computerNum = 10;
        }
        else
        {
            computerNum = rest;
        }

        cout << computerNum << "\n";
    }


    return 0;
}