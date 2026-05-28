#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = -1;    // 없으면 자동으로 -1을 return 하도록
    int len = A.length();
    int pos;
    bool same;
    for(int i=0; i<len; i++)
    {
        same = true;
        for(int ele = 0; ele<len; ele++)
        {
            pos = i + ele;
            if(pos >= len)
            {
                pos = pos % len; 
            }
            if(A[ele] != B[pos])
            {
                same = false;
                break;
            }
        }
        if(same == true)    // 위 for문에서 다른 글자가 하나도 없었다면 A를 밀어서 B가 될 수 있는 것이므로
        {
            answer = i; // 최소 횟수를 구하는 것이므로, answer을 찾으면 바로 break;
            break;
        }
    }
    return answer;
}