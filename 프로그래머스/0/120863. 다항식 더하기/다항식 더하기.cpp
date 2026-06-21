#include <string>
#include <vector>

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    stringstream ss(polynomial);
    string word;
    int xNum = 0;   // x의 계수 더하기
    int num = 0;    // 그냥 정수 더하기
    while(ss >> word)
    {
        if(word == "+")
        {
            continue;   // + 기호는 패스~~
        }
        // cout << word << "\n";
        if(word[word.length()-1] == 'x')
        {
            word.pop_back();    // 맨 뒤의 글자인 'x' 빼기
            if(word.length() == 0)  // 'x'로만 이루어진 문자였다는 거니까, 계수는 1이었다는 것임
            {
                xNum += 1;                
            }
            // 만약 한 자리 숫자라면, char -> int 변환 ==> 아님!!!! 처음 태어날 때 string이면 계속 string이래 (뒷글자가 빠져서, 한 글자가 되어도) 
            // 내가 맨 처음에 word(string형식)으로 글자를 받아왔으므로 이것들은 다 string이래
            else    // 두 자리 이상의 숫자라면, string -> int 변환 // 그건 char이 아니라 string이기 때문
            {
                xNum += (stoi)(word);
            }

        }
        else // 그냥 숫자값이면 그대로 더하기
        {
            num += (stoi)(word);
        }
    }
    
    // 덧셈 출력하기
    if(xNum > 0)
    {   
        if(xNum > 1)    // 계수가 1이 아닐 때만, 계수 생략하지 않고 적도록 (계수가 1이면 숫자 생략하고 바로 x~ 적기)
        {
            answer += to_string(xNum);
        }
        
        if(num == 0)    // 뒤에 작성할 정수값이 없다면 "x"만 적기
        {
            answer += "x";
        }
        else if(num > 0)    // 뒤에 작성할 정수값이 있다면 "x + " 적기
        {
            answer += "x + ";
            answer += to_string(num);            
        }
    }
    else    // x의 계수가 0이라면, 정수값만 적기
    {
        answer += to_string(num);
    }
    
    return answer;
}