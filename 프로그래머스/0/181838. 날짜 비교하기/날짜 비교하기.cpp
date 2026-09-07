#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2) {
    int answer = 0;
    int checkNum = 3;
    for(int i=0; i<checkNum; i++)
    {
        // 완전히 같은 날짜라면, 아래 중 어느것도 해당되지 않아서 자연스럽게 answer은 0으로 설정됨 
        if(date1[i] > date2[i])
        {
            answer = 0;
            break;
        }
        else if(date1[i] < date2[i])
        {
            answer = 1;
            break;
        }
    }
    return answer;
}