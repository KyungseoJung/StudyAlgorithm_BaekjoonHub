#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    vector <int> rows;
    for(int i=0; i<arr1.size(); i++)
    {
        rows.assign(arr1[i].size(), 0); // i번째 행의 사이즈로 맞추기

        for(int j=0; j<arr1[i].size(); j++)
        {
            rows[j] = arr1[i][j] + arr2[i][j];  // 덧셈
        }
        answer.push_back(rows); // 행 추가
    }
        
    return answer;
}