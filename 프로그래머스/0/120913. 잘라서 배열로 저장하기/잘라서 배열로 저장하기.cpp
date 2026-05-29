#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    
    int ele = 0;
    int len = 0;
    for(int i=0; i<my_str.length(); i++)
    {
        if(len == 0)    // 만약 ele번째 요소에 처음으로 넣는 거라면
        {
            answer.push_back("");
        }
        answer[ele] += my_str[i];
        len++;  
        
        if(len >= n)
        {
            len = 0;
            ele++;
        }
    }
    return answer;
}