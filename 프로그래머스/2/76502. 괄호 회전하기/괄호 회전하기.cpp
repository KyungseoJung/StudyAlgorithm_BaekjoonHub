#include <string>
#include <vector>

#include <deque>
#include <stack>

#include <iostream>
using namespace std;

bool parenthness(deque<char> deq)
{
    deque <char> d;
    for(int i=0; i<deq.size(); i++)
    {
        if(d.empty())
        {
            d.push_back(deq[i]); 
        }
        else
        {
            if((deq[i] == ')') && (d.back() == '('))
            {
                d.pop_back();
            }
            else if((deq[i] == '}') && (d.back() == '{'))
            {
                d.pop_back();
            }
            else if((deq[i] == ']') && (d.back() == '['))
            {
                d.pop_back();
            }
            else
            {
                d.push_back(deq[i]);
            }
        }
       

    }
    
    if(d.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solution(string s) {
    int answer = 0;
    
    // string s를 deque로 표현하기 (나중에, pop_front, push_back하기 쉽도록)
    deque <char> de;
    for(int i=0; i<s.length(); i++)
    {
        de.push_back(s[i]);
    }
    
    
    // 0 만큼 회전시켰을 때
    if(parenthness(de) == true)
    {
        answer ++;
    }
    // 1 이상만큼 회전시켰을 때
    char c;
    for(int i=1; i<s.length(); i++)
    {
        c = de.front();
        de.pop_front();
        de.push_back(c);
        
        if(parenthness(de) == true)
        {
            cout << i << "만큼 회전했을 때 parenthness 성공 \n";
            answer++;
        }
    }
    
    return answer;
}