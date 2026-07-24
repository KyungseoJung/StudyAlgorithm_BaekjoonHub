#include <string>
#include <vector>

#include <cmath>    // sqrt 함수 사용하기 위함
using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 약수: 어떤 수를 나누어떨어지게 하는 수
    // ex) 4의 약수: 1, 2, 4   // ex) 8의 약수: 1, 2, 4, 8
    
    // 어떤 수의 제곱근까지만 카운팅하면 됨. -> 그 후 x2배
    // 그리고 만약 그 어떤 수가 num^2 모양으로 만들어진다면, 카운팅 + 1
    
//     float num = sqrt(n);
    
//     // 제곱근까지 카운팅해보기
//     for(int i=1; i<num; i++)
//     {
//         if(n % i == 0)
//         {
//             answer ++;
//         }
//     }
//     answer = answer * 2;
    
//     // num^2 모양으로 만들어지는지 확인
//     if(int(num * num) == n)
//     {
//         answer ++;
//     }
    
    // 이렇게 하면, int(num * num) == n 무조건 성립하게 됨..... float과 int를 비교하는 것에서 문제가 생겨서 별로 적절하지 않은 방법
    // --------------------------
    // 그냥 제곱근까지 모두 for문으로 포함해서 계산하되, 한번 더 확인하는 if문 장치를 만드는 게 더 적절
    
    int count = 0;
    for(int ele = 1; ele<=n; ele++)
    {
        count = 0;  // 각 숫자의 약수 개수 카운팅
        for(int i=1; i * i <= ele; i++)
        {
            if(ele % i == 0)
            {
                count ++;
                if(i != ele / i)    // ex) ele: 36, i: 6일 때 => 6은 한번만 카운팅하도록
                {
                    count++;
                }
            }
        }
        if(count >= 3)
        {
            answer++;
        }
    }
        
        
    
    
    return answer;
}