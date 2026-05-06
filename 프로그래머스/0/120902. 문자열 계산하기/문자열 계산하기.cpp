#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    int num = 0;
    int ele = 1;
    for(int i= my_string.length()-1; i>=0; i--)
    {
        cout << "순서: " << my_string[i] <<"\n";
        if(isdigit(my_string[i]))
        {
            num += (my_string[i] - '0') * ele;
            ele *= 10;
        }
        else if(my_string[i] == '+')   // 연산 기호 나왔다면
        {
            cout << num << "을 더하기~ \n";
            answer += num;
            ele = 1; // 초기화
            num = 0; // 초기화
        }
        else if(my_string[i] == '-')   // 연산 기호 나왔다면
        {
            cout << num << "을 빼기~ \n";
            answer -= num;
            ele = 1; // 초기화
            num = 0; // 초기화
        }
        
        if(i == 0)  // 맨 앞에는 무조건 +가 숨어있는 거니까, -는 고려하지 않아도 됨
        {
            answer += num;
        }
    }
    return answer;
}