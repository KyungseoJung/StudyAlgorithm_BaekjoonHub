#include <string>
#include <vector>

#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    vector <int> places;    // 명예의 전당
    // k: 명예의 전당에 오를 수 있는 최대 점수 개수
    int min;    // 최하위점수    

    // 1. 각 날짜별 초대 가수의 점수를 살펴보기
    for(int i=0; i<score.size(); i++)
    {
        if(places.size() < k)   // (i) k명이 꽉 차지 않았다면, 명예의 전당에 바로 추가해주기
        {
            places.push_back(score[i]);
            
            // 최하위 점수 기록
            sort(places.begin(), places.end());
            min = places[0];
        }
        else    // k명이 꽉 찼다면, 명예의 전당 중 최하위 점수와 비교하기. 더 낮은 점수는 탈락
        {
            sort(places.begin(), places.end());
            if(places[0] < score[i])    // (ii) 새로운 점수로 바꿔주기
            {
                places[0] = score[i];   
                // 점수가 바뀌었다면, 최하위 점수는 places[0] 또는 places[1] 중 하나임
                min = (places[0] > places[1])? places[1] : places[0];
            }
            else
            {   
                // 점수가 바뀐 게 없으므로 최하위 점수는 places[0]
                min = places[0];
            }
            
        }
        
        // (iii) 각 날짜별 최하위 점수를 기록하기
        answer.push_back(min);
    }
    return answer;
}