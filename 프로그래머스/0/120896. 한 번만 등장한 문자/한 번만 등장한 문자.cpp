#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    char checkLetter = 'a';
    int count = 0;
    for(int i=0; i<26; i++)
    {
        count = 0;
        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == checkLetter + i)
            {
                count++;
            }
        }
        if(count == 1)  // 한 번 밖에 안 나왔으면 그대로 바로 answer에 추가 (어차피 a, b, c 순서대로 검사하기 때문에)
        {
            answer += (checkLetter + i);
            
        }
    }
    
    return answer;
}