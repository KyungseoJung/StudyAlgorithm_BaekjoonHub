#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {

    // schedules: 직원 n명이 설정한 출근 희망 시각 (+10분까지 용인해줌)
    // timelogs: 직원들이 일주일 동안 출근한 시각을 담은 2차원 정수 배열
    // startday: 이벤트를 시작한 요일을 의미하는 정수(1, 2, ... 7) (토요일, 일요일은 평가에서 제외)
    
    int answer = 0;
    int num = schedules.size();
    int allowTime; // 지각 허용 시각 (이 시간보다 늦게 오면 지각) (실제 출근 희망시간 + 10분)
    vector <int> giftWorker(num, 1); // 상품을 받을 직원의 값은 1, 못 받는 직원의 값은 0으로 설정 (일단 처음에는 모두 1로 설정해서 시작)
    int day; // 현재 무슨 요일인지
    


    for(int p=0; p<num; p++)    // 한 사람씩 평가
    {
        for(int i=0; i<7; i++)
        {
            day = startday + i;
            if(day > 7)
            {
                day -= 7;
            }
            if((day != 6) && (day != 7))  // 토요일, 일요일은 평가에서 제외
            {
                // allowTime (일단 출근 희망 시각 + 10분)을 먼저 계산하고,
                if((schedules[p]  + 10) % 100 >= 60)
                {
                    allowTime = schedules[p] + 100 + 10 - 60;
                }
                else
                {
                    allowTime = schedules[p] + 10;
                }
                
                if(allowTime / 100 >= 24)
                {
                    allowTime -= 24;
                }
                
                // schedules 시간과 비교하기 (실제 출근 희망 시각 + 10분 < timelogs[p][i] 이면 지각임)
                if(allowTime < timelogs[p][i])
                {
                    giftWorker[p] = 0;
                    break;  // 남은 요일은 계산할 필요 없음
                }
                
            }
        }
    }

    // 상품 받을 직원 카운팅하기
    int sum = 0;
    for(int p=0; p<num; p++)
    {
        if(giftWorker[p] == 1)
        {
            sum ++;
        }
    }
    
    answer = sum;
    return answer;
}