#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    // 0부터 9까지 더하면 45
    // 45 - numbers의 합 = answer
    int sum = 0;
    for(int i=0; i<numbers.size(); i++)
    {
        sum += numbers[i];
    }
    
    answer= 45 - sum;
    
    return answer;
}