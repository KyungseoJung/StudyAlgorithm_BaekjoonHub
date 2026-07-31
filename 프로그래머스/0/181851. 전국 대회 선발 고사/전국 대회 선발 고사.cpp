#include <string>
#include <vector>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    int findStudent = 0;    // 대회에 선발된 학생들 수 (3명까지만 찾으면 됨)
    int highestRank = 1;
    vector <int> studentNum;
    while(findStudent < 3)
    {
        for(int i=0; i<rank.size(); i++)
        {
            if(rank[i] == highestRank)
            {
                if(attendance[i] == true)
                {
                   studentNum.push_back(i);
                    findStudent++;
                    // highestRank++;  // 다음 등수 찾자
                }
                // else
                // {
                //     // highestRank ++; // 다음 등수 찾자
                // }
                
                highestRank ++; // 다음 등수 찾자 - 위에서 2번 할 거 여기서 1번 하기 위함
            }
        }
    }
    
    // 덧셈 시작
    answer = 10000 * studentNum[0] + 100 * studentNum[1] + studentNum[2];
    
    return answer;
}