#include <string>
#include <vector>

#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    answer = s;
    
    bool blank = true;  // 공백 문자인지 확인하기
    for(int i=0; i<answer.length(); i++)
    {
        if(blank == true) // 이전 글자가 공백이었다면
        {
            if(answer[i] == ' ')
            {
                // blank = true;   // 유지
                continue;   // 현재 글자가 공백이라면 넘어가기
            }
            else if(isdigit(answer[i]))
            {
                blank = false;
            }
            else    // 현재 글자가 문자라면
            {
                answer[i] = toupper(answer[i]);
                blank = false;
            }
        }
        else    // 이전 글자가 공백이 아니었다면
        {
            if(answer[i] == ' ')    // 현재 글자가 공백이라면
            {
                blank = true;
            }
            else    // 현재 글자가 '숫자' 또는 '문자'라면
            {
                // 그냥 넘어가기 -> 하면 안되고, 대문자인것을 소문자로 바꿔줘야 함
                answer[i] = tolower(answer[i]); // 어차피 숫자이면 tolower 해도 아무 변화 없음
            }
        }
    }
    
    
    
    return answer;
}