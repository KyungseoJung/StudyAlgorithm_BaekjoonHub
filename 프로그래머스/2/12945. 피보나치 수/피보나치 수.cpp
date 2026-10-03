#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector <int> nums;
    nums.push_back(0);
    nums.push_back(1);
    
    int sum = 0;
    for(int i=2; i<=n; i++)
    {
        nums.push_back ((nums[i-1] + nums[i-2]) %1234567);
    }
    
    answer = nums[n];
    
    return answer;
}

int fibonacci(int num)
{
    
}