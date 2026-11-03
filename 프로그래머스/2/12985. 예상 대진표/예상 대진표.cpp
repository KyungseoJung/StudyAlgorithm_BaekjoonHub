#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    answer += 1;    // 첫 라운드 시작이니까, answer은 1부터
    int min, max;
    while(true)
    {
        // 1) 만나는 경우를 확인하는 방법
        // a와 b 중 작은 숫자, 큰 숫자를 min, max라고 할 때
        // max % 2 == 0이고, min == max - 1을 만족할 때 둘은 만나게 됨
        max = (a>b)? a : b;
        min = (a>b)? b : a;
        if((max % 2 == 0) && (min == max - 1))
        {
            break;  // while문 종료
        }
        else
        {
            answer++;
        }
        
        // 2) a와 b를 계속 변경해주면 됨.
        // i) a와 b 숫자는 어떻게 바뀌는지 a를 기준으로 설명해보자면: 라운드에서 만나는 더 큰 번호의 참가자 -> 그 라운드에서 승자의 번호는 번호/2으로 바뀌게 됨
        // 만약, a % 2 != 0이라면, a는 (a + 1) / 2로 바뀜
        // 만약, a % 2 == 0이라면, a는 a / 2로 바뀜
        if(a % 2 != 0)
        {
            a = (a+1)/2;
        }
        else if(a % 2 == 0)
        {
            a = a / 2;
        }
        
        if(b % 2 != 0)
        {
            b = (b+1)/2;
        }
        else if(b % 2 == 0)
        {
            b = b / 2;
        }
        
    }

    return answer;
}