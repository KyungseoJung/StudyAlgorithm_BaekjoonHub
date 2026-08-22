#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    while(true)
    {
        if (answer * 7 >= n)
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