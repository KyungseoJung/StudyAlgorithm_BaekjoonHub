#include <iostream>
#include <vector>
#include <stack>		// stack 사용하기 위함
#include <queue>		// queue 사용하기 위함
#include <algorithm>	// 공백 제거 등을 위해 필요할 수 있음
#include <cmath>
#include <string>
#include <sstream>	// stringstream 사용하기 위함
#include <set> // set 사용하기 위함
using namespace std;
// 34704 문제: 크기가 4인 박스

int main()
{
    // 코드 속도 빠르게 하기 위한 설정
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string criterion = "LOVE";
    vector <int> count(criterion.length(), 0); // 각 글자가 등장한 횟수 카운팅

    string yeondoName;
    cin >> yeondoName;

    int N;
    cin >> N;
    vector <string> teams(N);
    vector <int> scores(N); // 각 팀의 score

    for (int i = 0; i < N; i++)
    {
        cin >> teams[i];
        fill(count.begin(), count.end(), 0);    // score 계산 & count 계산 전에, 모두 0으로 초기화하기
        // 연두의 이름과 팀 이름에서 등장하는 개수이므로, 연두의 이름을 포함한 +1은 해준 상태에서 카운팅해야 함.

        for (int j = 0; j < yeondoName.length(); j++)
        {
            for (int k = 0; k < criterion.length(); k++)
            {
                if (yeondoName[j] == criterion[k])
                {
                    count[k]++;
                }
            }
        }

        for (int j = 0; j < teams[i].length(); j++) // i번째 팀의 이름을 하나하나 파악하기
        {
            for (int k = 0; k < criterion.length(); k++)
            {
                if (teams[i][j] == criterion[k])
                {
                    count[k]++;
                }
            }
        }

        // i번째 팀의 점수 계산하기
        scores[i] = ((count[0] + count[1]) * (count[0] + count[2]) * (count[0] + count[3]) * (count[1] + count[2]) * (count[1] + count[3]) * (count[2] + count[3])) % 100;
        
        //cout << i << "번째 팀의 점수: " << scores[i] << "\n";
    }

    // 점수가 가장 높은 팀 확인하기
    int maxScore = 0;
    int maxScoreEle = 0;
    for (int i = 0; i < N; i++)
    {
        if (scores[i] > maxScore)
        {
            maxScore = scores[i];
            maxScoreEle = i;
        }
        else if (scores[i] == maxScore)
        {
            maxScoreEle = (teams[i] < teams[maxScoreEle]) ? i : maxScoreEle;
            // 사전순으로 우선인 단어를 우선으로 하기
        }
    }

    cout << teams[maxScoreEle];




    return 0;
}