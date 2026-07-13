#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    answer = arr;
    int rowNum = arr.size();
    int colNum = arr[0].size();
    
    int diff;
    if(rowNum > colNum)
    {
        diff = rowNum - colNum;
        for(int i=0; i < rowNum; i++)
        {
            for(int j=0; j<diff; j++)
            {
                answer[i].push_back(0);
            }        
            
        }
    }
    else if(rowNum < colNum)    // 열이 더 클 때, 0으로 가득찬 행을 추가해줘야 함
    {
        diff = colNum - rowNum;
        for(int i=0; i<diff; i++)
        {
            vector <int> v(colNum, 0);
            answer.push_back(v);
        }
    }
    
    cout << rowNum << " " << colNum;
    return answer;
}