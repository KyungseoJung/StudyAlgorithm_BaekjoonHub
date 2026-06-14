#include <string>
#include <vector>
#include <algorithm>    //min 함수 사용하기 위함

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int size = lines.size();
    // -100이상 100 이하까지의 범위를 ->  0이상 200 이하까지의 범위로 바꿔서 생각하자
    // 100을 더해서 저장하자
    // 만약 checkLines[0] = 1이라면, 0부터 1까지의 부분이 겹쳐있다고 하자.
    vector <int> checkLines(201, 0);    // 초기값은 0으로 설정하기
    
    // min, max를 찾아두어서, 그 제한된 범위 내에서만 찾으며 코드를 효율화하기 위함
    int minVal = 200;   //min, max를 변수 이름으로 설정하면 안됨. algorithm 헤더가 min,max함수와 헷갈려함.
    int maxVal = 0;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<2; j++)  // 시작과 끝좌표, 총 2개 점으로 이루어져 있으므로
        {
            lines[i][j] += 100;     // 100씩 더해주기
            
            if(lines[i][j] < minVal)   // min값 업데이트
            {
                minVal = lines[i][j];
            }
            if(lines[i][j] > maxVal)   // max값 업데이트
            {
                maxVal = lines[i][j];
            }
        }
    }
    
    // 각 선분을 다른 선분과 비교하면서, 겹친 부분은 1로 처리
        // 겹친 것 확인: (선A의 시작 좌표 < 선B의 끝좌표)이고 (선B의 시작좌표 < 선A의 끝좌표)
        // ㄴ겹친 부분은: 선B의 시작 좌표부터 ~ min(선A의 끝좌표, B의 끝좌표) 까지
        // (min(선A의 끝좌표, B의 끝좌표) - 선B의 시작 좌표)
    for(int a=0; a<size; a++)
    {
        for(int b=a+1; b<size; b++)
        {
            if( lines[a][0] <= lines[b][0]   )   // 선A가 더 왼쪽에 있다면, (+ 시작점이 같다면)
            {
                if(lines[b][0] < lines[a][1])   
                {
                    int minPos = min(lines[a][1], lines[b][1]);
                    // 겹친 부분을 1로 만들기
                    for(int i = lines[b][0]; i<minPos; i++)
                    {
                        checkLines[i] = 1;
                    }
                }
            }
            else if(lines[b][0] < lines[a][0])   // 선B가 더 왼쪽에 있다면,
            {
                if(lines[a][0] < lines[b][1])
                {
                    int minPos = min(lines[a][1], lines[b][1]);
                    //겹친 부분을 1로 만들기
                    for(int i= lines[a][0] ; i<minPos; i++)
                    {
                        checkLines[i] = 1;
                    }
                }
            }
        }
    }
    
    // 겹친 부분의 길이 체크
    int sum = 0;
    for(int i=minVal; i<maxVal; i++)
    {
        sum += checkLines[i];
    }
    
    answer = sum;
    return answer;
}