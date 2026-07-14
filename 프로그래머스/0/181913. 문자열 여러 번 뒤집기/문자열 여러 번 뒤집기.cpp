#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    answer = my_string;
    
    // my_string을 기준으로 두고, 참고하면서 answer 값을 바꿔주기.
    
    int start, end;
    for(int i=0; i<queries.size(); i++)
    {
        start = queries[i][0];
        end = queries[i][1];
        
        for(int j=0; j<= (end - start); j++)
        {
            answer[start + j] = my_string[end - j];
        }
        
        my_string = answer;   // my_string도 새롭게 업데이트. 
    }
    return answer;
}