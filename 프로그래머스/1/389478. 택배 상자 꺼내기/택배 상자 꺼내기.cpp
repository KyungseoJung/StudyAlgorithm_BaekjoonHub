#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int topHeight; // 전체 최대 몇층인지
    if(n % w == 0)
    {
        topHeight = n/w;
    }
    else
    {
        topHeight = n/w + 1;
    }
    
    int currentHeight;  // 현재 num이 어디에 위치해있나
    if(num % w == 0)
    {
        currentHeight = num / w;
    }
    else
    {
        currentHeight = num / w + 1;
    }
    

    // cout << "topH: " << topHeight << ", " << "curr H: " << currentHeight << "\n";
    
    // col 위치를 확인해서 맨 꼭대기층이 비어있지는 않은지 확인하기 ---------------------
    // (1) 일단 현재 num의 col 위치 확인하기 -----------------------
    bool currentRight = true;  // 오른쪽으로 채워지는 행이었는지, 왼쪽으로 채워지는 행이었는지 확인하기
    int currentCol;
    if(currentHeight % 2 == 1)
    {
        currentRight = true;
        currentCol = num % w -1;
        if(currentCol < 0) // 연산에 대해 추가 생각 (num % w이 0일 때)
        {
            currentCol += w;
        }
    }
    else
    {
        currentRight = false;
        currentCol = w - (num % w); // 연산에 대해 추가 생각 (num % w이 0일 때
        if(currentCol >= w)
        {
            currentCol -= w;
        }
    }
    
    // (2) 맨 꼭대기의 col 위치 확인하기 -----------------------
    bool topRight = true;   // 맨 꼭대기층이 오른쪽으로 채워지는 행이었는지, 왼쪽으로 채워지는 행이었는지
    int topCol;
    if(topHeight % 2 == 1)
    {
        topRight = true;
        topCol = n % w - 1;
        if(topCol < 0 ) // 연산에 대해 추가 생각 (num % w이 0일 때
        {
            topCol += w;
        }
        
        // cout << "currentCol : " << currentCol << " , topCol: " << topCol << "\n";
        
        if(currentCol <= topCol)
        {
            answer = topHeight - currentHeight + 1;
        }
        else
        {
            answer = topHeight - currentHeight;
        }
    }
    else
    {
        topRight = false;
        topCol = w - (n%w);
        if(topCol >= w) // 연산에 대해 추가 생각 (num % w이 0일 때
        {
            topCol -= w;
        }
        if(currentCol >= topCol)
        {
            answer = topHeight - currentHeight + 1;
        }
        else
        {
            answer = topHeight - currentHeight;
        }
    }
    
    
    
    
    return answer;
}