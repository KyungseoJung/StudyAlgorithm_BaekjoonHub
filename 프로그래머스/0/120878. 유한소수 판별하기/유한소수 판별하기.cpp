#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    // 유한소수가 되기 위한 분수의 조건: 기약분수로 나타냈을 때 분모의 소인수가 2와 5뿐이어야 함
    
    // 기약분수로 만들기 ----------------
    bool dividable = true;
    while(dividable)
    {
        dividable = false;
        // 아래 for문에서 나눠지는 숫자가 있으면 dividable은 true가 될 것임
        for(int i=2; i<=a; i++)
        {
            if((a % i == 0) && (b % i == 0))
            {
                a = a/i;
                b = b/i;
                dividable = true;
            }
        }
    }
    
    // 기약분수로 만들기 ----------------
    while(true)
    {
        if(b % 2 == 0)
        {
            b = b / 2;
        }
        else if(b % 5 == 0)
        {
            b = b / 5;
        }
        else
        {
            // 2와 5 중 어떤 것으로도 나눠지지 않는다면 while문 나오기
            // while문을 나왔을 때 1이면, 그 분모는 소인수가 2와 5만 존재하는 숫자였던 것 
            break;
        }
    }   
    
    if(b == 1)
    {
        answer = 1;
    }
    else
    {
        answer = 2;
    }
    
    return answer;
}