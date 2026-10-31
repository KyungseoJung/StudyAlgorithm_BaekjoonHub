#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = -1;

    // 1) 일단 각 숫자들이 소수인지, 아닌지 판별하는 vector 저장해놓기
    vector <bool> primeNumber(50001, true);
    primeNumber[0] = false;
    primeNumber[1] = false;
    // *** 에라토스테네스의 체 ***
    for(int i= 2; i*i <= 50000; i++)
    {
        if(primeNumber[i] == true)
        {
            for(int j= i*i; j<= 50000; j+= i)
            {
                primeNumber[j] = false;
            }
        }
    }
    
    // 2) 3개의 수 덧셈 조합을 얻어보기
    int sum;
    answer = 0;
    for(int i= 0; i<nums.size(); i++)
    {
        for(int j= i+1; j<nums.size(); j++)
        {
            for(int k= j+1; k<nums.size(); k++)
            {
                sum = nums[i] + nums[j] + nums[k];
                if(primeNumber[sum] == true)
                {
                    answer++;
                }
            }
        }
        
    }

    return answer;
}