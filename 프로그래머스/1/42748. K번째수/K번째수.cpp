#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector <int> testArray;
    for(int ele=0; ele<commands.size(); ele++)
    {
        int i = commands[ele][0];
        int j = commands[ele][1];
        int k = commands[ele][2];
        
        testArray.clear();
        testArray = array;
        int a = j;
        int b = i -1;
        
        // 뒷부분 제거
        testArray.erase(testArray.begin() + a, testArray.end());    // a부터 끝까지 (a포함O)
        // 앞부분 제거
        testArray.erase(testArray.begin(), testArray.begin() + b);   // 처음부터 b 직전까지 (b포함X)
        
        // 정렬하기
        sort(testArray.begin(), testArray.end());
        
        // k번째 원소 추가하기
        answer.push_back(testArray[k-1]);
    }
    return answer;
}