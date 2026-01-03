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

    float A, B;
    cin >> B;
    // A + A*(0.1) = B
    // 1.1 * A = B
    // A = B / 1.1

    A = B / 1.1;
    cout << A;


    return 0;
}