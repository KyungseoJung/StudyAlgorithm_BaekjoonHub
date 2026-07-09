#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    int ele = 0;
    for(int num = i; num <=j; num++)
    {
        ele = num;  // ele가 아니라 num을 건들게 되면, for문에서 사용하는 num이 망가져서 for문을 이상하게 돌게 됨.
        while(ele >= 1)
        {
            if(ele % 10 == k)   // 일의 자리수를 확인하기 위해서, 10으로 나눈 나머지 값을 확인하는 것
            {
                answer++;
            }
            ele = ele / 10;
        }
    }
    return answer;
}