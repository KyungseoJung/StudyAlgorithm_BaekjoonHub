#include <string>
#include <vector>

#include <cctype>   // isdigit 함수 사용 목적
#include <iostream>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    int num = 0;
    bool continuously = false;
    for(int i=0; i<my_string.length(); i++)
    {
        if(isdigit(my_string[i]))
        {
            if(continuously == true)
            {
                num = num * 10 + (my_string[i] - '0');                
            }
            else
            {
                num = (my_string[i] - '0');
                continuously = true;                
            }

        }
        else if(!isdigit(my_string[i]) )
        {
            // 다음에 알파벳이 나왔다면 그냥 바로 더하기
            continuously = false;
            answer += num;
            num = 0;
            
            cout << "더하기: " << num << "\n";
        }
        
        if( (continuously == true) && (i == my_string.length()-1) )
        {
            // 마지막 순서의 원소라면 그냥 바로 더하기
            answer += num;
        }
    }
    return answer;
}