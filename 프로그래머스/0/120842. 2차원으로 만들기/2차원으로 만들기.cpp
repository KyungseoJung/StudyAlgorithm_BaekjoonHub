#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    // vector<vector<int>> answer;
    // 행의 개수 지정해주기
    int size;
    if(num_list.size() % n == 0)
    {
        size = num_list.size() / n;
    }
    else
    {
        size = (num_list.size() / n) + 1;
    }
    vector<vector<int>> answer(size);
    
    int ele = 0;
    int numEle = 0;
    while(numEle < num_list.size())
    {
        for(int j=0; j<n; j++)
        {
            answer[ele].push_back(num_list[numEle]);
            numEle++;
        }
        ele++;
    }
    return answer;
}