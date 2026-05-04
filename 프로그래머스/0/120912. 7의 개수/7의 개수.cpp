#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for(int i=0; i<array.size(); i++)
    {
        for(int j=0; j<to_string(array[i]).length(); j++)
        {
            if(to_string(array[i])[j] == '7')
            {
                answer++;
            }
        }
    }
    
    return answer;
}