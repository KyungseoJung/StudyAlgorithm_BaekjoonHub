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
// 17202 문제: 핸드폰 번호 궁합

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;

    string checkNum;
    for (int i = 0; i < A.length(); i++)
    {
        checkNum += A[i];
        checkNum += B[i];
    }
    
    //cout << checkNum << "\n";
    string rememberNum;
    while (checkNum.length() > 2)
    {
        rememberNum = "";
        for (int i = 0; i < checkNum.length()-1; i++)
        {
            rememberNum += to_string((checkNum[i] - '0' + checkNum[i + 1] - '0') % 10);
        }

        //cout << rememberNum << "\n";
        checkNum = rememberNum;

    }

    cout << checkNum;

    return 0;
}