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
// 2355 문제: 시그마

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long int A, B;
    cin >> A >> B;

    long long int max = (A > B) ? A : B;
    long long int min = (A < B) ? A : B;

    //*** 등차수열의 합 공식
    // A부터 B까지의 합은 (A+B)*개수 / 2

    long long int sum = 0;
    sum = ((min + max) * (max - min + 1)) / 2;    
    // 계산이 너무 커질 수 있으니까 나누기부터 하자 -->> 결과값이 달라질 수 있으므로 그러지 말자,,,,


    cout << sum;

    return 0;
}