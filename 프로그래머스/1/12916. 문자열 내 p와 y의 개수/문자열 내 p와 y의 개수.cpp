#include <string>
#include <iostream>
#include <cctype>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    int countP = 0;
    int countY = 0;
    
    char c;
    for(int i=0; i<s.length(); i++)
    {
        c = tolower(s[i]);
        if(c == 'p')
        {
            countP++;
        }
        else if(c == 'y')
        {
            countY++;
        }
    }
    
    if(countP == countY)
    {
        answer = true;
    }
    else
    {
        answer = false;
    }

    return answer;
}