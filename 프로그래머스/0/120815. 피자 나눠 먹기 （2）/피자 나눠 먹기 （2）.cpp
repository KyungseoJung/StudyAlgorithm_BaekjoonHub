#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    answer = 1;
    // n과 6의 최소공배수 찾기
    while(true)
    {
        if((answer * 6)% n == 0)
        {
            break;
        }
        else
        {
            answer++;
        }
    }
    return answer;
}