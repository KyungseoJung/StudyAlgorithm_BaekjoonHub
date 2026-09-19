#include <string>
#include <vector>

#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int alphabetNum;
    char alphabet;
    cout << (int) 'a' << " " << (int)'z' << "\n";
    cout << (int) 'A' << " " << (int)'Z' << "\n";
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            alphabet = s[i];
        }
        else
        {
            alphabetNum = s[i] + n;    
            if(((int)(s[i])  <= 90))  // 대문자라면 &&
            {
                if(alphabetNum > 90)   //  alphabet이 Z를 넘어갔다면 다시 처음으로 돌아가도록 하기
                {
                    alphabet = (char)(alphabetNum - 26);
                }
                else
                {
                    alphabet = (char)(alphabetNum);
                }
            }
            else    // 소문자라면
            {
                if(alphabetNum > 122)
                {
                    alphabet = (char)(alphabetNum - 26);
                }
                else
                {
                    alphabet = (char)(alphabetNum);
                }
            }
        }
        answer = answer + alphabet;
    }
    return answer;
}