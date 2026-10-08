#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // x가 자연수일 때, 
    // 1개 숫자로 표현하는 방법: x                    -> 최소숫자: 1
    // 2개 숫자로 표현하는 방법: x + (x+1) = 2x+1     -> 최소숫자: 3
    // 3개 숫자로 표현하는 방법: (2x+1) + (x+2) = 3x+3    -> 최소숫자: 6
    // 4개 숫자로 표현하는 방법: (3X+3) + (x+3) = 4x+6    -> 최소숫자: 10
    // 5개 숫자로 표현하는 방법: (4x+6) + (x+4) = 5x+10   -> 최소숫자: 15
    
    // y개 숫자로 표현할 때, 가능한 최소 숫자 크기를 이용해서
    // *** 최대 몇 개 숫자로 표현할 수 있는지, 그리고 그 때의 (+정수) 값은 무엇인지 알아내면 됨
    int count = 1;  // 최대 몇 개 숫자로 표현할 수 있는지 저장하기
    vector <int> countVector;   // *** 최대 몇 개의 숫자로 표현할 수 있는지
    
    int mul = 0;    // (+정수) 값
    int mulDiff = 1;    // 정수가 커지는 편차 (+1 +2 +3)
    
    int minNum = 1; // 최소 숫자
    int minNumDiff = 2;     // 최소 숫자가 커지는 편차( +2, +3, +4)

    vector <int> mulVector; // *** 그때의 (+정수)값 저장 --- 4x+6이라면 6이 정수값
    while(true)
    {
        if(minNum > n)  // 1 | 3 | 6
        {
            break;  // while문 통과
        }
        countVector.push_back(count);   // 저장: 1 | 2 | 3
        mulVector.push_back(mul);       // 저장: 0 | 1 | 3
        
        mul += mulDiff;            // 1    | 3    | 6
        mulDiff ++;                 // 1->2| 2->3 | 3->4
        
        minNum += minNumDiff;       // 3   | 6    | 10
        minNumDiff ++;              // 2->3| 3->4 | 4->5
        
        count ++;
    }
    
    // 이제 최종적으로, 최대 몇 개의 숫자로 표현할 수 있는지 & 그때의 +정수값을 알고 있음
    // i번째: 만약 (n-mulVector[i]) % countVector[i] == 0이라면 그것은 나타낼 수 있는 것
    
    cout << countVector.size()<< "\n";  // countVector와 mulVector의 크기가 같은지 확인하기 위한 cout문
    cout << mulVector.size()<< "\n";
    
    for(int i=0; i<countVector.size(); i++)
    {
        if((n - mulVector[i]) % countVector[i] == 0)
        {
            answer++;
        }
    }
    
    return answer;
}