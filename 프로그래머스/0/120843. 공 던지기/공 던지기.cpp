#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    int ele = 0;
    for(int i=0; i<(k-1); i++)
    {
        ele += 2;
        if(ele >= numbers.size())
        {
            ele = ele - numbers.size();
        }
    }
    
    answer = numbers[ele];
    
    return answer;
}