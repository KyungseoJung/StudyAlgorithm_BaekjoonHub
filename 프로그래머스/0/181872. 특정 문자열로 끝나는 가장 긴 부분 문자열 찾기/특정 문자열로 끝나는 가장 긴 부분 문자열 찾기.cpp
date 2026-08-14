#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    
    // myString의 뒤에서부터 pat을 찾기
    // 찾은 다음에는 그 앞에까지의 알파벳을 저장하고 마지막에 +pat만 붙이면 됨
    
    int ele = 999;
    bool same;
    for(int i=myString.length()-1; i>=0; i--)
    {
        same = false;
        if(myString[i] == pat[pat.length()-1])
        {
            same = true;
            for(int j=1; j<pat.length(); j++)
            {
                if(myString[i-j] != pat[pat.length() -1 -j])
                {
                    same = false;   // 하나라도 다르면 false
                    break;
                }
            }
        }
        
        if(same == true)
        {
            ele = i-pat.length();
            break;
        }
    }
    
    if(ele != 999)  // pat으로 끝나는 부분이 있긴 했다면 (= 999는 아니라면)
    {
        for(int i=0; i<=ele; i++)
        {
            answer = answer + myString[i];
        }
        answer += pat;
    }
    else // 만약 999라면 answer은 그냥 빈 문자열
    {
        
    }

    
    return answer;
}