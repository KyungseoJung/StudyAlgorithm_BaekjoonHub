#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    int min;
    int s, e, k;
    for(int a=0; a<queries.size(); a++)
    {
        min = 9999999;
        s = queries[a][0];
        e = queries[a][1];
        k = queries[a][2];
        for(int i=s; i<=e; i++)
        {
            if((arr[i] > k) && (arr[i] < min))
            {
                min = arr[i];
            }
        }
        if(min == 9999999)
        {
            min = -1;
        }
        answer.push_back(min);
    }
    return answer;
}