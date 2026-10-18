#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    int score;
    int scoreSum;
    
    for(int i=0; i<photo.size(); i++)
    {
        // photo[i]에 있는 사람들의 추억 점수 더하기
        scoreSum = 0;
        for(int j=0; j<photo[i].size(); j++)
        {
            score = 0;
            for(int ele = 0; ele < name.size(); ele++)
            {
                if(name[ele] == photo[i][j])
                {
                    score = yearning[ele];
                    break;
                }
            }
            scoreSum += score;
        }
        
        // photo[i]에 있는 추억 점수들을 result에 넣기
        answer.push_back(scoreSum);
    }
    return answer;
}