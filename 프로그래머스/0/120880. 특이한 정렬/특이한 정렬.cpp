#include <string>
#include <vector>
#include <cmath>    // abs 함수 사용 목적

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    int ele;
    int diff;
    int minDiff;
    
    // 첫 번째 원소를 넣는 방법을 생각하다가...
    // 생각해보니, 모든 원소에 같은 방식을 적용하면 되잖아?
    
    while(numlist.size() > 0)
    {
        minDiff = 99999;
        for(int i=0; i<numlist.size(); i++)
        {
            diff = abs(numlist[i] - n);
            if(diff < minDiff)
            {
                minDiff = diff;
                ele = i;
            }
            else if(diff == minDiff)
            {
                if(numlist[i] > numlist[ele])
                {
                    ele = i;
                }
            }

        }
        // 일단 answer에 첫 번째 숫자 넣기
        answer.push_back(numlist[ele]);
        numlist.erase(numlist.begin() + ele);

    }
        
   
    
    return answer;
}