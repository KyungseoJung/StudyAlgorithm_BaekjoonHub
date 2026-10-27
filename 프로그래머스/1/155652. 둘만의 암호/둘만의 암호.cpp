#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
   
    // 직접 하나하나 s[i]를 skip과 비교하면서 변환하기
    char startChar;
    int countIndex;
    for(int i=0; i<s.length(); i++)
    {
        startChar = s[i];
        for(int count = 0; count < index; count++)
        {
            // startChar을 한 칸씩 이동하기
            if(startChar == 'z')
            {
                startChar = 'a';
            }
            else
            {
                startChar++;    // 한 칸 이동 ***
            }
            
            for(int j=0; j<skip.length(); j++)
            {
                if(startChar == skip[j])
                {
                    count -=1; // 덧셈 무효처리
                    break;
                }
            }         
        }
        
        answer = answer + startChar;        
        
        

    }
    
    return answer;
}