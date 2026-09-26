#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    char criterionChar = s[0];
    int check = 0;  // x와 같은 글자이면 +1, 다른 글자이면 -1
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == criterionChar)
        {
            check ++;
        }
        else
        {
            check --;
        }
        
        if((i == s.length()-1) || (check == 0) )    // 마지막 순서이거나, check가 0이면 분리
        {
            if(i+1 < s.length())
            {
                criterionChar = s[i+1];         // 기준 알파벳 재정의    
            }
            
            // 만약 한 글자 남아서, 위 if문이 성립되지 않는다면 -> 굳이 기준 알파벳 잡아주지 않아도 끝날 일이라 무시해도 됨
            answer ++;
        }
    }
    return answer;
}