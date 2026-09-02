#include <string>
#include <vector>

#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    // 약수의 개수가 홀수이려면, 제곱수여야 함. Ex) 16의 약수 -> 중심에 4가 존재하고, 대칭으로 세트씩 존재
    int sqrtNum;
    bool plus;
    for(int i=left; i<=right; i++)
    {
        sqrtNum = sqrt(i);  // 일부러 소수점 버려서 저장하기 위해 int로 저장
        if(sqrtNum * sqrtNum == i)  // 만약 제곱값이 i와 동일하다면, i는 제곱수라는 것
        {
            plus = false;
        }
        else
        {
            plus = true;
        }
        
        if(plus == true)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }
    
    return answer;
}