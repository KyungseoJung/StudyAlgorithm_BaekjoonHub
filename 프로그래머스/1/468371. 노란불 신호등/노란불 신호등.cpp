#include <string>
#include <vector>
using namespace std;
int solution(vector<vector<int>> signals) {
    int answer = 0;
    int num = signals.size();
    // 최소공배수 (LCM) (Least Common Multiple), 근데 앞에 특정 수가 미리 더해져있는..
    vector <int> times(num);

    // 나머지를 이용해야겠다.
    // 각 주기는 초 + 노 + 빨 -> 현재 t % 주기= 현재 초/노/빨 중 어떤 것인지 알 수 있음
    int LCM;    // 일단 LCM을 계산해보자
    int max = 0;   // max를 기준으로 LCM을 찾아볼 예정이기 때문에 max 찾아두자
    vector <int> cycles(num);
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<signals[i].size(); j++)
        {
            cycles[i] += signals[i][j];
        }

        if(cycles[i] > max)
        {
            max = cycles[i];
        }
    }

    // max 값을 기준으로 계산하자
    int ele = max;
    bool divided;
    while(true)
    {
        divided = true;
        for(int i=0; i<num; i++)
        {
            if(ele % cycles[i] != 0)
            {
                divided = false;
            }
        }
        if(divided == true)
        {
            // 만약 모든 수가 나누어진다면, 그 값이 LCM
            LCM = ele;
            break;  // while문 통과하기
        }
        else
        {
            ele += max;
        }
    }
    
    // LCM까지만 계산하면 됨
    // 만약, 초/노/빨이 2, 2, 1초라면 -> 현재 시간 t % 주기값(5) == 3이상 4이하이면 노란불임
    bool yellow;
    for(int time=1; time<= LCM; time++)
    {
        yellow = true;
        for(int j=0; j<num; j++)
        {
            if( ((time % cycles[j]) < signals[j][0] + 1) || ((time % cycles[j]) > cycles[j] - signals[j][2]) )
            {
                yellow = false;
            }
        }
        if(yellow == true)  // yellow가 false인 신호등이 없는 것이므로, 
        {
            answer = time;
            break;  // for문 통과하기
        }
    }
    if(answer == 0) // 바뀌지 않았다면, 애초에 모두 다 노란불일 때가 없는 것이므로
    {
        answer = -1;
    }

    return answer;
}