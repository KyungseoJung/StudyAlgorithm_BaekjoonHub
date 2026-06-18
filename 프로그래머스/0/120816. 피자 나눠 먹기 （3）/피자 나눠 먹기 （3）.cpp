#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    answer = 1;
    while(true)
    {
        if(slice * answer >= n)
        {
            break;
        }
        else
        {
            answer ++;
        }
    }
    return answer;
}