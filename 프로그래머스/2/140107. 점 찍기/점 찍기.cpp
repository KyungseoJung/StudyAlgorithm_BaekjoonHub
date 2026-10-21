#include <string>
#include <vector>

#include <iostream>
#include <cmath>    // sqrt 함수 사용 목적

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

//     int a = 0;
//     int b = 0;
//     while(a * k <= d)
//     {
//         b = 0;
//         while(a*a*k*k + b*b*k*k <= d*d)
//         {
//             // 거리가 한번 벗어나면, 해당 b는 더이상 계산할 필요가 없음. 계속 범위를 벗어날 것이기 때문에
//             answer++;
//             b++;
//         }
        
//         a++;
//     }
    
    // 그냥 y가 고정되어있으면, x가 몇 개 찍힐 수 있는지 알 수 있음. 그 원리를 이용해서 계산해보자
    // long long int D = d*d;   // 이렇게 계산하면, long long으로 선언했어도, d 자체가 int이기 때문에, 오버플로우 된 d*d 값이 D로 들어가버림

    // (long long)(d*d)    // ❌ 곱한 뒤에 변환 → 이미 늦음
    // (long long)d * d    // ✅ d를 먼저 변환 → long long끼리 곱함   // ⭐⭐⭐하나라도 long long인 것을 같이 곱해주면, 나머지도 자동으로 long long으로 변환되나봐
    
    long long int D = (long long)d*d;
    long long int num;
    for(long long int b = 0; b * k <= d; b++)
    {
        // 좌표가 (x, y)라면 -> x*x + y*y <= d*d
        // 즉, x*x <= d*d - y*y  // sqrt를 씌우면, 0 <= x <= sqrt(d*d - y*y)
        // a, b, k로 표현하면, 0 <= a*k <= sqrt(d*d - b*b*k*k)
        num = sqrt(D - b*b*k*k );
        
        answer += ((num / k) + 1);  // (num/k)로 계산함으로써 자동으로 소수점 제외시켜버리기 // 0부터 더하는 거니까 개수 +1 추가해주기
        
    }
    
    
    return answer;
}