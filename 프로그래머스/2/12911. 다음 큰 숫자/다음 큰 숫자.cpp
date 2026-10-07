#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 10010 -> 10100
    // 10101 -> 10110
    // 1001100 -> 1010001
    
    // *** 숨은 규칙: 오른쪽끝부터 01이 나오는 부분을 찾아 -> 01부분을 10으로 바꾸고, 그 지점보다 오른쪽에 있는 1들을 모두 오른쪽으로 몰아넣어주기
    // ex) 1111은 01111로 보고 계산하면 -> 10111을 얻을 수 있음
    
    // 1. 일단 n을 이진변환하기
    string st = "";
    int remain; // 나머지 저장용
    
    while(n > 0)    // n이 0이 되면 while문 탈출하기
    {
        remain = n % 2;
        n = n / 2;  // 계속 2로 나눈 몫을 n으로 설정하다보면, n은 결국 0이 됨
        
        // st = to_string(remain) + st;
            // 위 방법도 되고
        char c = remain + '0';
        st = c + st;
    }
    
    // 2. st을 오른쪽부터 살펴보면서, 01부분을 찾기
    int ele = -1;
    for(int i=st.length(); i > 0; i--)
    {
        if( (st[i-1] == '0') && (st[i] == '1')   )
        {
            ele = i;
            break;
        }
    }
    
    // 3. answr의 이진표현 구하기
    string answerSt;
    int oneNum = 0; // 1의 개수 세기

    
    cout << "1 개수: " << oneNum << "\n";
    
    if(ele == -1)   // 만약 01부분을 찾지 못했다면, 1111, 1110 같은 형식임 -> 자릿수 추가
    {
        answerSt = '1' + st;    // 자릿수 추가 (앞에 1 추가)
        answerSt[1] = '0';
        
        // (a) 총 1의 개수 세기
        for(int i = 0; i<st.length(); i++)
        {
            if(st[i] == '1')
            {
                oneNum++;
            }
        }
        
        // (b) 알맞게 1 붙여주기
        // 10--- 으로 시작하는 숫자 뒤에 존재해야 하는 1의 개수는(oneNum -1);
        int needOneNum = oneNum - 1;
        // 그러면 일단 뒷자리를 모두 0으로 만들고, 붙여야 하는 자리에만 1을 붙이자
        for(int i=2; i<answerSt.length(); i++)
        {
            answerSt[i] = '0';
        }
        for(int i=answerSt.length()-1; i >= answerSt.length()-needOneNum; i--)
        {
            answerSt[i] = '1';
        }

        // 끝까지 모두 1로 만들어주기 -> 안해줘도 처음부터 그렇게 설정되어 있음
            // 틀린 생각 (1110 같은 숫자도 고려해줘야 함. 즉, 뒷자리를 모두 1로 바꾸면 안됨)
            // 
            
    }
    else    // 01 패턴이 있었다면  - 자릿수 유지
    {
        
        // (a) 일단 오른쪽에 있는 1의 개수부터 세고
        for(int i = st.length()-1; i>ele; i--)
        {
            if(st[i] == '1')
            {
                oneNum++;
            }
        }
        
        
        answerSt = st;
        answerSt[ele-1] = '1';
        answerSt[ele] = '0';

        
        // (b) index 기준: 맨 오른쪽(st.length()-1)부터 oneNum개 자리까지(st.length() -oneNum)는 1로 설정 (이렇게 해야 oneNum개만큼 1로 바뀜)
            // index 기준: ele +1부터 st.length()-1-oneNum 까지는 0으로 설정
        // 그러면 일단 ele+1부터 끝까지 모두 0으로 만들어놓고, 그 다음 1을 입히자
        for(int i=ele+1; i<answerSt.length(); i++)
        {
            answerSt[i] = '0';
        }
        for(int i=answerSt.length()-1; i>= answerSt.length()-oneNum; i--)
        {
            answerSt[i] = '1';
        }

        
    }
    cout << answerSt;
    
    // 4. 이진표현을 최종 답안 숫자로 표현하기
    int multiplyNum = 1;
    for(int i=answerSt.length()-1; i>=0; i--)
    {
        answer += multiplyNum * (answerSt[i] - '0');
        multiplyNum *= 2;
    }
    
    
    return answer;
}