#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    // 합이 될 수 있는 수는 0~200
    vector <bool> sums(201, false);   // 0부터 200까지 나타났는지를 저장하기. 나타났다면 true. 처음엔 모두 false.
    int sum;
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j=0; j<numbers.size(); j++)
        {
            sum = numbers[i] + numbers[j];
            if((i != j) && (sums[sum] == false))
            {
                sums[sum] = true;
            }
        }
    }
    
    for(int i=0; i<sums.size(); i++)
    {
        if(sums[i] == true)
        {
            answer.push_back(i);
        }
    }
    
    return answer;
}