#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    
    int num = score.size();
    vector<int> scoreMeans(num);
    for(int i=0; i<num; i++)
    {
        scoreMeans[i] = (score[i][0] + score[i][1]);    // 평균이 크면 합도 크니까, 굳이 평균을 구할 필요 없음. (정확히 평균을 구하는 것보다는, 어떤 학생의 평균이 큰지 확인하는 게 중요한 문제니까)
    }
    
    // 높은 점수를 하나씩 찾아서 등수 매기기
    answer.resize(num);
    int max;
    int maxEle;
    int rank = 1;
    int rankCount;   // 해당 순위에 해당하는 학생이 2명 이상이라면
    while(rank <= num)
    {
        max = -1;    // 초기화
        rankCount = 0;
        for(int i=0; i<num; i++)
        {
            if(scoreMeans[i] > max)
            {
                max = scoreMeans[i];
                maxEle = i;
            }
        }
        
        // 만약 해당 max에 해당하는 학생이 2명 이상인지 확인
        for(int i=0; i< num; i++)
        {
            if( (i != maxEle) && (scoreMeans[i] == max) )   // maxEle가 아닌데도, 점수가 동일하다면, 해당 학생들에게 모두 아래 코드를 적용하자
            {
                rankCount++;
                // scoreMeans.erase(scoreMeans.begin() + i);
                scoreMeans[i] = -1; // 그냥 작은 값으로 업데이트 해주자. // *** erase하면, 앞으로 땡겨져와서 내가 원하는 element 값이 아닌 다른 값에 접근하게 됨
                answer[i] = rank;
            }
        }
        // ---- 이건 동점자가 있든 없든 해야 하는 것~ ----
        // scoreMeans.erase(scoreMeans.begin() + maxEle);    // 최고로 높은 평균 점수의 값을 지우기
        scoreMeans[maxEle] = -1; // 그냥 작은 값으로 업데이트 해주자. // *** erase하면, 앞으로 땡겨져와서 내가 원하는 element 값이 아닌 다른 값에 접근하게 됨

        answer[maxEle] = rank;                  // 해당 ele에 등수를 매겨주기

        if(rankCount > 0)
        {
            rank += (rankCount + 1);    // 해당 학생이 n명일수록 rank도 n번 더 더해주면 됨
        }
        else if(rankCount == 0)  // 만약 해당 점수가 오로지 1명만 있다면
        {
            rank++;                                 // 등수 + 1 (다음 등수 해당하는 값에 찾아서 매겨주기)
        }

    }
    
    return answer;
}