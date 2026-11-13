#include <string>
#include <vector>

#include <algorithm>    // sort 사용 목적
#include <queue>    // queue 사용 목적

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    // queue 특징: Dequeue 할 때는 앞에서 뽑고, Enqueue 할 때는 뒤로 넣기
    
    // 1) 원본 priorities 데이터
    queue <int> pq; // priorities와 구성이 동일한 queue 만들어두기 -> 이제 이것만 조정할 것임
    for(int i=0; i<priorities.size(); i++)
    {
        pq.push(priorities[i]);
    }
    
    // 2) 우선순위 저장하기 (숫자가 클수록 우선순위래)
    vector <int> ranks;
    ranks = priorities;
    sort(ranks.rbegin(), ranks.rend());   // -> 내림차순 이용해서, 내가 확인한 숫자가 가장 높은 우선순위의 숫자가 맞는지 확인하기. 맞다면 ranks에서도 제거하기. 그 다음 우선순위를 고를 수 있게.
    
    // 3) 특정 priorities을 실행할 때, 몇 번재 index인지 저장하기
    queue <int> indexes;
    for(int i=0; i<priorities.size(); i++)
    {
        indexes.push(i);
    }
    
    // queue 시작
    int priorityNum;
    while(true)
    {
        priorityNum = ranks[0]; // 첫 번째 원소 = 내가 가진 숫자 중, 가장 우선순위 숫자
        if(pq.front() == priorityNum)
        {
            answer++;
            // 실행하면 됨!!
            if(indexes.front() == location) // 실행해서 빼기 전에, 내가 찾으려는 원소인지 확인 - 만약 내가 찾는 것이었다면, 종료!
            {
                break;  // while문 종료
            }
            pq.pop();   // 앞의 것 빼기
            indexes.pop();  // 앞의 것 빼기
            
            ranks.erase(ranks.begin() + 0);   // 첫 번째 원소 제거하기
        }
        else
        {
            // 원본 자체를 이동 (앞에서 빼서 뒤로 넣기)
            pq.push(pq.front());    // 뒤로 넣기
            pq.pop();   // 앞에서 빼기
            
            // 몇 번째 index인지 저장한 값을 이동 (앞에서 빼서 뒤로 넣기)
            indexes.push(indexes.front());
            indexes.pop();
        }
    }
    
    
    
    return answer;
}