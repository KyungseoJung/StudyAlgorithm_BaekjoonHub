#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // 1) 일단 각 기능이 며칠 후 완성되는지 작성하기
    // 특정 기능의 progress를 p라고 하고, 속도를 s, 날짜를 x라고 한다면: p + s * x >=100
    // s * x >= 100 - p         // x >= (100-p) / s     
    // (100-p)/s 가 소수라면: x = (int)((100-p)/s) + 1
    // (100-p)/s 가 정수라면: x = (100-p)/s
    
    int p, s, x;
    vector <int> dates;
    for(int i=0; i<progresses.size(); i++)
    {
        p = progresses[i];
        s = speeds[i];
        if((100-p) % s > 0)
        {
            x = (int)((100-p)/s) + 1;
        }
        else
        {
            x = (100-p)/s;
        }
        dates.push_back(x);
    }
    
    // 2) 며칠 후 완성되는지 저장한 vector를 기반으로 계산하기
    // 앞에 큰 숫자가 있다면 그보다 작거나 같은 숫자들까지 한꺼번에 작업 완료됨. 이후 큰 숫자부터 다시 기다림 이후, 그 *이하* 숫자들까지 한꺼번에 작업 완료
    bool start = true;
    int previousMax = 0;
    int count = 0;
    
    // 가장 첫 번째 날 먼저 설정해주기
    previousMax = dates[0];
    count = 1;
    
    // 만약 하루만 작업했다면
    if(progresses.size() == 1)
    {
        answer.push_back(1);
    }
    
    for(int i=1; i<dates.size(); i++)   // 두 번째 날부터 확인하기
    {
        if(dates[i] <= previousMax)
        {
            count++;
            
            if(i == dates.size() -1)    // 만약 마지막 작업이라면
            {
                answer.push_back(count);
                break;  // for문 통과
            }
        }
        else
        {
            previousMax = dates[i];
            answer.push_back(count);    // 앞에서 카운팅했던 작업들 한묶음으로 넣기
            count = 1;  // 다시 1부터 시작하기 (현재 i번째 작업 포함해서)
            
            if(i == dates.size() -1)    // 만약 마지막 작업이라면
            {
                answer.push_back(count);
                break;  // for문 통과
            }
        }
    }
    
    return answer;
}