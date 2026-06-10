#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    // 각 두 직선의 기울기를 구하면 됨.
    // 두 직선의 기울기를 구하는 방법: 두 점을 선택. 어떤 것이 먼저 오든 상관 없음. 
    // (a, b)와 (c, d)라고 한다면 기울기: (b-d)/(a-c)
    
    bool findSame = false;
    float grad1, grad2; // 기울기 계산은 실수로 해야 함!!!!!!!!!
    for(int i=0; i<dots.size(); i++)
    {
        if(findSame == true)    // 코드 낭비를 줄이기 위한 목적의 if문: 한번이라도 평행한 경우가 있다면, for문 멈추기
        {
            break;
        }
        
        for(int j= i+1; j<dots.size(); j++) // j는 i와 다른 점을 선택해야 하므로
        {
            for(int a=0; a<dots.size(); a++)
            {
                for(int b=a+1; b<dots.size(); b++)  // b는 a와 다른 점을 선택해야 하므로
                {
                    if((a != i) && (a != j) && (b != i) && (b != j))
                    {
                        // i와 j에 모두 겹치지 않는 두 점을 선택했다는 가정하에 비교 시작.
                        // i와 j를 이은 기울기와, a와 b를 이은 기울기를 비교
                        if((dots[i][0] - dots[j][0] != 0) && (dots[a][0] - dots[b][0] != 0))
                        {
                            // y좌표의 위치가 동일해서, 기울기가 0인 경우는 자동으로 grad1과 grad2 모두 0으로 계산됨
                            
                            // grad1 = (dots[i][1] - dots[j][1]) / (dots[i][0] - dots[j][0]);
                            // grad2 = (dots[a][1] - dots[b][1]) / (dots[a][0] - dots[b][0]);
                            // 위처럼 계산한 결과는, 실수가 아니라 정수로 나오게 됨
                            // 따라서, grad1 == grad2를 확인하고 싶다면 아래처럼 비교하는 게 올바름
                            // if(grad1 == grad2)
                            
                            if((dots[i][1] - dots[j][1]) * (dots[a][0] - dots[b][0]) ==  (dots[a][1] - dots[b][1])* (dots[i][0] - dots[j][0]))
                            {
                                cout << i << "와 " << j <<"의 기울기 == " << a << "와 " << b << "의 기울기\n";
                                answer = 1;
                                findSame = true;
                                break;
                            }
                        }
                        else if((dots[i][0] - dots[j][0] == 0) && (dots[a][0] - dots[b][0] == 0))
                        {
                            // 둘다 분모에 0이 들어가면, 기울기가 둘다 1이라는 것. 즉, 계산은 안되어도 기울기가 1로 동일한 경우임
                            answer = 1;
                            findSame = true;
                        }
                     
                       
                    }
                    
                }
    
            }
        }
    }
    
    return answer;
}