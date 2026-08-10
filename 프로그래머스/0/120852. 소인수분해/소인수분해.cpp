#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector <int> nums;
    while(n > 1)
    {
        for(int i=2; i<=n; i++)
        {
            if(n % i == 0)
            {
                nums.push_back(i);
                n = n / i;
                break;
            }
        }
    }
    
    // nums 중에서 겹치는 숫자 빼고, 고유한 숫자만 answer에 넣기
    // 어차피 오름차순으로 들어가있을테니까
    int ele = 0;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] != ele)  // 이전 숫자와 다른 숫자일 때에만 answer에 넣기
        {
            answer.push_back(nums[i]);
            ele = nums[i];
        }
    }
    return answer;
}