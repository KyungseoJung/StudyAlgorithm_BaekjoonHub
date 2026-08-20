#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    long long int num = -99999999999;
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j= (i+1); j<numbers.size(); j++)
        {
            if(numbers[i] * numbers[j] > num)
            {
                num = numbers[i] * numbers[j];
            }
        }
    }
    answer = num;
    return answer;
}