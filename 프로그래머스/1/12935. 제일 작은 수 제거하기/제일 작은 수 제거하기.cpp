#include <string>
#include <vector>

#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() ==1 )
    {
        answer.push_back(-1);
    }
    else
    {
        answer = arr;
        
        int min = arr[0];
        int minEle = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] < min)
            {
                min = arr[i];
                minEle = i;
            }
        }
        
        answer.erase(answer.begin() + minEle);
    }
    return answer;
}