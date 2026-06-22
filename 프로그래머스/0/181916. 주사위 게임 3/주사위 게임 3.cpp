#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    vector <int> nums;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);
    nums.push_back(d);
    
    // for문을 거쳐서, 서로 다른 주사위의 개수를 센다고 하자.
    // 그 서로 다른 주사위의 개수를 count라고 한다면
    int count = 0;
    // case1: 네 주사위 숫자가 모두 같다면, count = 0;
    // case2: 세 주사위 숫자가 같고, 다른 주사위에 나온 숫자가 다르다면, count = 3
    // case3: 두 주사위 숫자가 같고, 다른 주사위에 나온 두 숫자가 같다면, count = 4
    // case4: 두 주사위 숫자가 같고, 다른 주사위에 나온 두 숫자가 다르다면, count = 5
    // case5: 네 주사위 숫자가 모두 다르다면, count = 6
    
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[i] != nums[j])
            {
                count++;
            }
        }
    }
    
    // case에 따라 나눠서 계산하기
    int caseNum;
    if(count == 0)
    {
        caseNum = 1;
    }
    else
    {
        caseNum = count-1; // 그냥 계산해보니까, 이래서 이렇게 저장하는 것임. 두 변수의 상관관계는 딱히 없음. 중요하지도 않고.
    }
    int p = 0;
    int q = 0;
    int r = 0;
    
    bool same;
    switch(caseNum)
    {
        case 1:{
            p = nums[0];
            answer = 1111 * p;
            
            break;}
        case 2:{
            for(int i=0; i<nums.size(); i++)
            {
                same = false;
                for(int j= 0; j<nums.size(); j++)
                {
                    if((i != j) && (nums[i] == nums[j]))
                    {
                        same = true;
                    }
                }
                if(same == false)
                {
                    q = nums[i];    // 모든 세 숫자와 다르다면 그 값이 q
                    if(i > 0)
                    {
                        p = nums[i-1];  // q와 다른 값 중 하나를 아무거나 p로 설정하면 됨
                    }
                    else
                    {
                        p = nums[i+1];
                    }
                    break;
                }
            }
            
            answer = (10 * p + q) * (10 * p + q);
            
            break;
            }
        case 3:{
            for(int i=0; i<nums.size(); i++)
            {
                for(int j=0; j<nums.size(); j++)
                {
                    if((i!=j) && (nums[i] != nums[j]))
                    {
                        p = nums[i];
                        q = nums[j];
                    }
                }
            }
            int diff = (p - q > 0)? (p-q) : (q-p);
            answer = (p+q) * diff;
            break;}
            
        case 4:{
            for(int i=0; i<nums.size(); i++)
            {
                same = false;
                for(int j=0; j<nums.size(); j++)
                {
                    if((i!=j) && (nums[i] == nums[j]))
                    {
                        same = true;
                        break;
                    }
                }
                if(same == false)   // 나머지 3개 숫자와 모두 다른 숫자
                {
                    if(q == 0)  // q가 아직 정해지지 않았다면
                    {
                        q = nums[i];
                    }
                    else if(q != 0) // q가 이미 정해졌다면
                    {
                        r = nums[i];
                    }
                }
            }
            
            // // q, r이 아닌 값이 p // 최종 계산에 안 쓰여서 찾을 필요 없었음
            // for(int i=0; i<nums.size(); i++)
            // {
            //     if((nums[i] != q) && (nums[i] != r))
            //     {
            //         p = nums[i];
            //     }
            // }
            answer = q * r;
            break;
            }
        case 5:{
            int min = 9;
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i] < min)
                {
                    min = nums[i];
                }
            }
            answer = min;
            break;}
    }
    
    return answer;
}