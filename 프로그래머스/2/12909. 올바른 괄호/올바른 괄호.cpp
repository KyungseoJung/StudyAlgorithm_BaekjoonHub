#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    stack <char> st;
    for(int i=0; i<s.length(); i++)
    {
        if( (s[i] == ')') && (st.top() == '(') )
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
        answer = true;
    }
    else
    {
        answer = false;
    }

    return answer;
}