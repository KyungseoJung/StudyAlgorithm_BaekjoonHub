#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int start;
    int end;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == 2)
        {
            start = i;
            break;
        }
    }
    
    for(int i= arr.size() -1; i>=0; i--)
    {
        if(arr[i] == 2)
        {
            end = i;
            break;
        }
    }
    
    // answer 만들기
    for(int i=start; i<=end; i++)
    {
        answer.push_back(arr[i]);
    }
    
    if(answer.size() == 0)
    {
        answer.push_back(-1);
    }
    return answer;
}