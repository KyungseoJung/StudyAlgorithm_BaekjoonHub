#include <string>
#include <vector>

#include <algorithm>    // sort 함수
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // 2명씩 밖에 탈 수 없음 = 가장 가벼운 사람은 최대한 무거운 사람과 같이 타는 것이 효율적 (100kg을 넘지 않는 선에서)
    

    // *** 핵심 ***
    // 가장 가벼운 사람과 가장 무거운 사람을 매칭해보기
    // 매칭해서 100kg 이하이면: 그 두 사람을 보트에 태워보내기
    // 매칭해서 100kg 초과라면: 해당 무거운 사람은 더이상 매칭 가능한 사람이 없는 것이므로, 무거운 사람만 보트에 태워보내기
        // (다음으로 무거운 사람을 찾기 -> XXX)
    
    // 오름차순 정렬
    sort(people.begin(), people.end()); 
    
    int light = 0;  // 가벼운 사람들 중, 보트 탄 사람 카운팅
    int heavy = 0;  // 무거운 사람들 중, 보트 탄 사람 카운팅
    bool twoPeople;
    int boatNum = 0;
    
    int i;
    int j;
    int num = people.size();
    while(true)
    {
        if(light + heavy == num)
        {
            break;  // while문 종료
        }
        i = light;  // 남은 사람들 중 가장 가벼운 사람의 index 번호
        j = people.size() - 1 - heavy;  // 남은 사람들 중 가장 무거운 사람의 index 번호
        
        if( (i != j) && (people[i] + people[j] <= limit))
        {
            light++;
            heavy++;
            // 두 사람 모두 보트 타고 탈출
            // cout << i << "와 " << j << "탈출 \n";
        }
        else
        {
            heavy++;    // heavy만 보트 타고 탈출
            // cout << j << "만 탈출 \n";
        }

        boatNum++;  // 보트는 어쨌든 1개만 탈출
    }
    
    answer = boatNum;
    return answer;
}