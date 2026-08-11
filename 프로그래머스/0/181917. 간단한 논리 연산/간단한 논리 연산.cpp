#include <string>
#include <vector>

#include <iostream>
using namespace std;

bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = true;
    
    // bool b1 = true * true;
    // bool b2 = true * false;
    // bool b3 = false * true;
    // bool b4 = false * false;
    // cout << b1 << "\n";
    // cout << b2 << "\n";
    // cout << b3 << "\n";
    // cout << b4 << "\n";
    
    bool b1, b2;
    b1 = (x1 + x2 > 0)? 1 : 0;  // 하나라도 true이면, 합은 0보다 크게 되고, b1은 true// 둘다 false이면 b1은 false
    b2 = (x3 + x4 > 0)? 1 : 0;
    
    if(b1 * b2 == 1)    // b1과 b2가 모두 true여서, 그 곱이 1이 나온다면 answer = true
    {
        answer = true;
    }
    else    // 둘 중 하나라도 false여서, 그 곱이 0이 나온다면 answer = false
    {
        answer = false;
    }
    
    return answer;
}