#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    
    answer.resize(emergency.size());
    int check = 0;
    int max;
    int maxEle;
    while(check < emergency.size())
    {
        max = -1;
        for(int i=0; i<emergency.size(); i++)
        {
            if(emergency[i] > max)
            {
                max = emergency[i];
                maxEle = i;
            }
        }
        
        answer[maxEle] = check + 1;
        emergency[maxEle] = -1;    // 제일 작게 업데이트
        check++;
    }
    return answer;
}