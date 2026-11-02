#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    // 내림차순 정렬 후, m의 배수번째에 있는 값들만 더하기 (그 값이 m개로 묶었을 때의 최저 점수 사과니까)
    // 1) 내림차순 정렬
    sort(score.rbegin(), score.rend());
    
    // 2) m의 배수번째에 있는 값들만 더하기 (단 여기서는 0번째 index를 1번째라고 인식해야 함)
    for(int i=0; i<score.size(); i++)
    {
        if((i+1) % m == 0)
        {
            answer += score[i];
        }
    }
    
    // 3) 마지막에는 각 상자당 m개씩 들어있을 것이므로 m을 곱해주면 됨
    answer = answer * m;

    return answer;
}