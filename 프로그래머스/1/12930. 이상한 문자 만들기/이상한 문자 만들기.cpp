#include <string>
#include <vector>

#include <cctype>   // toupper 함수 사용하기 위함

using namespace std;

string solution(string s) {
    string answer = "";
    int ele = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(ele % 2 == 0)
        {
            answer = answer + char(toupper(s[i]));  // char 안적으면 틀림. toupper 자체는 숫자를 반환함
        }
        else
        {
            answer = answer + char(tolower(s[i]));
        }
    
        // ** 각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾸는 것이기 때문에, 
        // 지금 살펴보고 있는 i번째 문자가 각 단어에서 짝수/홀수번째인지 확인해야 함.
        if(s[i] == ' ')
        {
            ele = 0;
        }
        else
        {
            ele ++;             
        }
    }
    
    return answer;
}