#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    vector <int> checkNums(100001, 0); // 0부터 100,000까지 이미 있었는지 확인하는 배열
    
    int count = 0;
    for(int i=0; (i<arr.size()) && (count < k); i++)
    {
        if(checkNums[arr[i]] == 0)
        {
            answer.push_back(arr[i]);
            checkNums[arr[i]] = 1;
            count++;
        }
    }
    
    for(int i=0; i<(k - count); i++)
    {
        answer.push_back(-1);
    }
    
    return answer;
}