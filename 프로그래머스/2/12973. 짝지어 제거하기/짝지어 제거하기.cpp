#include <iostream>
#include<string>

#include <stack>    // stack 사용하기 위함
using namespace std;

int solution(string s)
{
    int answer = -1;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    stack <char> st;
    for(int i=0; i<s.length(); i++)
    {
        if((!st.empty()) && (st.top() == s[i]))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    
    if(st.empty())
    {
        answer = 1;
    }
    else
    {
        answer = 0;
    }

    return answer;
}