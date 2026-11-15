#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int ele = 1;
    if(s[0] == '-')
    {
        for(int i=s.length()-1; i>0; i--)
        {
            answer += (s[i] - '0') * ele;
            ele = ele * 10;
        }
        answer = answer * (-1);
    }
    else if(s[0] == '+')
    {
        for(int i=s.length()-1; i>0; i--)
        {
            answer += (s[i] - '0') * ele;
            ele = ele * 10;
        }
    }
    else
    {
        for(int i=s.length()-1; i>=0; i--)
        {
            answer += (s[i] - '0') * ele;
            ele = ele * 10;
        }
    }

    return answer;
}