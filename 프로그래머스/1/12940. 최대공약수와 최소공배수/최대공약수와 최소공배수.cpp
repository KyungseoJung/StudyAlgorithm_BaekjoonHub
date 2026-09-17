#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int min, max;
    if(n > m)
    {
        min = m;
        max = n;
    }
    else
    {
        min = n;
        max = m;
    }
    
    // 고민: 최대공약수를 먼저 구하는 게 빠를까 or 최소공배수를 먼저 구하는 게 빠를까
    // 최대공약수는 최대 1000000번의 for문 루프가 필요함
    // 최소공배수는..? 그것보단 작지 않을까?
    
    // 최소공배수 구하기 - 작은 수의 x배 = 큰 수의 y배 구하기 (큰 수에 곱하는 순서로 구해야, 계산량 적어지겠지)
    int lcm;
    int mul = 1;
    while(true)
    {
        if((max * mul) % min == 0)
        {
            lcm = max * mul;
            break;
        }
        else
        {
            mul ++;
        }
    }

    
    // 최대공약수 구하기 -> 최소공배수 x 최대공배수의 곱 = 두 수의 곱과 같음
    // gcd * lcm = n * m;
    int gcd = (n*m)/lcm;

    answer.push_back(gcd);
    answer.push_back(lcm);

    return answer;
}