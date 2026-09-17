#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    // 고민: 최대공약수를 먼저 구하는 게 빠를까 or 최소공배수를 먼저 구하는 게 빠를까
    // 최대공약수는 최대 1000000번의 for문 루프가 필요함
    // ㄴ아님!!! 유클리드 호제법을 이용하면 굉장히 빠르게 구할 수 있다 O(log(n))
    
    // *** "두 수의 최대공약수는 큰 수를 작은 수로 나눈 나머지와 작은 수의 최대공약수와 같다" ***
    // GCD(min, max) == GCD(min, max % min)
    
    int gcd;
    int num1 = n;   // 처음엔 n, m 중 아무수나 등록해도 상관 없음~
    int num2 = m;

    int divider, dividend;  // 나누는 수, 나눠지는 수
    while(true)
    {
        if(num1 > num2)
        {
            num1 = num1 % num2;
            divider = num2;
            dividend = num1;
        }
        else
        {
            num2 = num2 % num1;
            divider = num1;
            dividend = num2;
        }
        
        if(dividend == 0)
        {
            gcd = divider;
            break;
        }
    }
    int lcm = (m * n) / gcd;
//     // 최소공배수 구하기 - 작은 수의 x배 = 큰 수의 y배 구하기 (큰 수에 곱하는 순서로 구해야, 계산량 적어지겠지)
//     int lcm;
//     int mul = 1;
//     while(true)
//     {
//         if((max * mul) % min == 0)
//         {
//             lcm = max * mul;
//             break;
//         }
//         else
//         {
//             mul ++;
//         }
//     }

    
//     // 최대공약수 구하기 -> 최소공배수 x 최대공배수의 곱 = 두 수의 곱과 같음
//     // gcd * lcm = n * m;
//     int gcd = (n*m)/lcm;

    answer.push_back(gcd);
    answer.push_back(lcm);

    return answer;
}