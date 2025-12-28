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

    int D, H, W;
    cin >> D >> H >> W;
    // (H*x)^2 + (W*x)^2 = D^2
    // (H^2 + W^2) * x^2 = D^2
    // x = sqrt(D^2 / (H^2 + W^2))

    float x = sqrt(pow(D, 2) / (pow(H, 2) + pow(W, 2)));    

    cout << floor(H * x) << " " << floor(W * x);    // 소수점 버리기

    return 0;
}