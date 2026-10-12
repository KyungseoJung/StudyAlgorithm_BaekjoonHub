#include <string>
#include <vector>

#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    // 길이 검사
    if((s.length() != 4) && (s.length() != 6))
    {
        answer = false;
        return answer;
    }
    
    for(int i=0; i<s.length(); i++)
    {
        cout << s[i] - '0' << "\n";
        // if((s[i]-'0' < 0) || (s[i] - '0' > 9))
        if(! isdigit(s[i]))
        {
            answer = false;
            return answer;
        }
    }
    return answer;
}