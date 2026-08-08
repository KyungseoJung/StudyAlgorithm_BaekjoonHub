#include <string>
#include <vector>

#include <iostream>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    // double sum = 0;
    
    int aEle = a.length() - 1;
    int bEle = b.length() - 1;
    int sum;
    bool plus = false;
    while(true)
    {
        if((aEle >= 0) && (bEle >=0))
        {
            sum = (a[aEle] - '0') + (b[bEle] - '0');
        }
        if((aEle < 0) && (bEle >= 0))
        {
            sum = (b[bEle] - '0');            
        }
        if((aEle >= 0) && (bEle < 0))
        {
            sum = (a[aEle] - '0');
        }
        if((aEle < 0) && (bEle < 0))
        {
            if(plus == true)    // 만약 1이 넘어왔다면 
            {
                answer = "1" + answer;
            }
            
            break;  // while문 종료            
        }
        
        
        if(plus == true)    // 이전 덧셈이 10 이상이었다면, 1 넘어와서 추가로 더해줌
        {
            sum +=1;
        }
        
        if(sum >= 10)
        {
            // cout << "기존answer(" << answer << ")에 추가로 더해서  -> ";
            answer = to_string(sum % 10) + answer;
            // cout << answer << "\n";
            plus = true;
        }
        else
        {
            // cout << "기존answer(" << answer << ")에 추가로 더해서  -> ";
            answer = to_string(sum) + answer;
            // cout << answer << "\n";
            
            plus = false;
        }
        
        aEle --;
        bEle --;
    }
    return answer;
}