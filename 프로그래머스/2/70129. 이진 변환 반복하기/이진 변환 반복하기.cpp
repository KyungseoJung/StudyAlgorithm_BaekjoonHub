#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int num0;   // 0의 개수
    int num1;   // 1의 개수
    int changeNum = 0;  // 이진 변환의 횟수 (누적하기)
    int removeNum = 0;  // 삭제한 0의 개수 (누적하기)
    
    int remainder;
    while(true)
    {
        if(s == "1")
        {
            break;  // while문 통과
        }
        num0 = 0;
        num1 = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '0')
            {
                num0 ++;
            }
        }
        num1 = s.length() - num0;
        removeNum += num0;  // 지운 0의 개수 누적하기
        
        // num1을 2진법으로 표현해서 -> s 업데이트
            // 2진법 표현 방법
        s = "";
        while(true)
        {
            // 2로 나누었을 때의 나머지를 하나하나 추가해주면 됨
            // (나눈 몫이 0이 될 때까지)
            remainder = num1 % 2;
            num1 = num1/2;
            
            char ch = remainder + '0';
            s = ch + s;
            
            if(num1 == 0)
            {
                break;  // while문 탈출
            }
        }
        changeNum++;    // 이진 변환 횟수 누적
    }
    
    answer.push_back(changeNum);
    answer.push_back(removeNum);
    
    return answer;
}