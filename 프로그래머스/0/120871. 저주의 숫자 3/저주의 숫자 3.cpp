#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    int count = 0;  // 저주의 숫자가 아닌 숫자에 대해 카운팅 (이 카운팅의 숫자가 n과 동일할 때의, num을 구하는 게 목표)
    int num = 0;    // 현재 num
    while(count < n)
    {
        num++;
      
        // 만약 3의 배수라면, count는 더해주지 말고 num만 추가
        if(num % 3 == 0)
        {
            continue;
        }
        // 만약 3이 들어갔다면, count는 더해주지 말고 num만 추가
        // 일의 자리에 3 들어가면, %10 == 3
        // 십의 자리에 3 들어가면, /10 해주고 %10 == 3
        // 백의 자리에 3 들어가면, /100 해주고 %10 == 3
        // if((num / 1 == 3) || (num / 10 == 3) || (num / 100 == 3) || (num / 1000 == 3))
        
        if((num % 10 == 3) || ((num / 10) % 10 == 3) || ((num / 100) % 10 == 3))
        {
            continue;
        }
        
        // 위의 두 경우에 모두 해당 안되면, count++
        count++;
        
    }
    
    answer = num;
    return answer;
}