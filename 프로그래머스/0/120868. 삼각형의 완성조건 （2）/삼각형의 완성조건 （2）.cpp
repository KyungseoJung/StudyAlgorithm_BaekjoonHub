#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    int len;    // 나머지 한 변의 길이
    int min = (sides[0] > sides[1])? sides[1] : sides[0];
    int max = (sides[0] > sides[1])? sides[0] : sides[1];
    int sum = min + max;
    
    // 1) 나머지 한 변의 길이가, 가장 긴 변일 때 (가장 긴 변이 2개인 경우도 여기 포함)
    len = max;

    while(true)
    {
        cout << len << " " << sum << "\n";
        if(len < sum)
        {
            answer ++;
            len++;
        }
        else
        {
            break;
        }
    }
    
    // 2) 나머지 한 변의 길이가, 가장 긴 변이 아닐 때 (가장 짧은 변이 2개인 경우도 여기 포함)
    len = max - 1;
    while(true)
    {
        sum = len + min;
        if(max < sum)
        {
            answer++;
            len--;
        }
        else
        {
            break;
        }
    }
    
    return answer;
}