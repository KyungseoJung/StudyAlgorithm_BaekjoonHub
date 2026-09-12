#include <string>
#include <vector>

#include <algorithm> // reverse 함수 사용
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int quotient, remainder;
    quotient = n;
    
    string num3;    // 3진법 표현문장
    while(true)
    {
        remainder = quotient % 3;   // 나누기 전에 나머지부터 저장하기 (quotient가 변하기 전에)
        quotient = quotient / 3;    // 몫 저장
        
        num3 = to_string(remainder) + num3; // 3진법 저장하기
        
        // 몫이 0이 되면, 그 순간까지만 나머지를 3진법으로 저장하는 데 사용하고, 종료
        if(quotient == 0)
        {
            break;
        }
    }
    // 3진법 반전
    reverse(num3.begin(), num3.end());  // 반전시키기
    
    cout << num3 << endl;
    int multiplyNum = 1;
    // 10진법으로 표현하기
    for(int i=num3.size()-1; i>=0; i--)
    {
        answer += (num3[i] - '0') * multiplyNum;   // i번째 자리숫자 이용하기
        cout << "더하기: " <<  (num3[i] - '0') * multiplyNum << endl;
        multiplyNum *= 3;
    }
    return answer;
}