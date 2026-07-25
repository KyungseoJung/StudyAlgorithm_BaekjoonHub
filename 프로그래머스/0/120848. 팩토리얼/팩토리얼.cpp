#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long int num = 1;
    answer = 1;
    while(true)
    {
        num = num * answer;
        if(num > n)
        {
            answer -= 1;
            break;
        }
        answer++;

    }
    return answer;
}