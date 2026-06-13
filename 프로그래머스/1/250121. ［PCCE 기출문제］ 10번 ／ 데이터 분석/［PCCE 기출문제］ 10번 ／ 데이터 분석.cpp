#include <string>
#include <vector>
#include <algorithm>    // sort함수 사용하기 위함

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int extIndex;
    int sortIndex;
    vector <string> dataName = {"code", "date", "maximum", "remain"};
    for(int i=0; i<dataName.size(); i++)
    {
        if(dataName[i] == ext)
        {
            extIndex = i;
        }
        if(dataName[i] == sort_by)
        {
            sortIndex = i;
        }
    }
    // val_ext보다 ext값이 작은 데이터만 뽑기
    for(auto row:data)
    {
        if(row[extIndex] < val_ext)
        {
            answer.push_back(row);
        }
    }
    
    // sort_by에 해당하는 값을 기준으로 오름차순 정렬하기
    sort(answer.begin(), answer.end(), [sortIndex](const vector <int>& a, const vector <int>& b) {
        return a[sortIndex] < b[sortIndex];
    });
    
    return answer;
}