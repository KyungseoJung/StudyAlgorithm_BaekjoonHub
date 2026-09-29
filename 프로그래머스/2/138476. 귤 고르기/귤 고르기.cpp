#include <string>
#include <vector>

#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector <int> sizes;  // 크기 종류
    vector <int> nums;      // 그 해당 크기가 몇 개 들어있는지 확인
    
    sort(tangerine.begin(), tangerine.end());

    int preventSize = tangerine[0];
    int count = 0;
    
    sizes.push_back(tangerine[0]);
    // 아래 for문을 통해
    // 어떤 종류의 크기가 있고, 그 해당 크기의 귤은 몇 개가 들어있는지 저장함
    for(int i=0; i<tangerine.size(); i++)
    {
        if(tangerine[i] != preventSize)
        {
            // 기존 입력한 sizes[preventSize]에 대한 개수 업데이트
            nums.push_back(count);
            // cout << sizes.back() <<"크기에 대하여: " << count <<"개 만큼 있음 \n";
            
            // 새로운 sizes 종류 추가
            sizes.push_back(tangerine[i]);
            count = 1;
        }
        else
        {
            count ++;
        }
        
        preventSize = tangerine[i];
        
        if(i == tangerine.size() -1)    // 마지막 원소일 때에는 그냥 바로 넣어주고 끝내기
        {
            nums.push_back(count);
            // cout << sizes.back() <<"크기에 대하여: " << count <<"개 만큼 있음 \n";
        }
    }
    
    // 크기별로 sort하면 빠르겠지만, 코드를 몰라서...
    int selectNum = 0;  // 선택한 귤의 개수 정하기
    int maxNum;
    int maxEle;
    while(true)
    {
        // cout << "k: " << k << "와 selectNum: " << selectNum << "\n";
        if(k <= selectNum)  // 그냥 k이상으로만 담으면 된다고 생각하자. (남는 건 덜어내면 되고. 내가 알고 싶은 건 최소한의 크기 종류 수니까)
        {
            break;  // while문 통과
        }
        maxNum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > maxNum)   // 가장 많이 있는 종류를 가져오기
            {
                maxNum = nums[i];
                maxEle = i;
            }
        }
        // 남은 귤 중, 가장 개수가 많은 귤을 선택 (크기는 몰라도 됨. 지금은 종류의 수만 구하는 거니까)
        // cout << sizes[maxEle] << "선택했고, 이건 " << nums[maxEle] << "개 있었음. \n";
        
        selectNum += nums[maxEle];
        
        nums[maxEle] = -1;  // 다음에 절대 선택 못하도록 -1로 바꾸기
        
        answer ++;  // 종류 수 +1
        
    }
    
    return answer;
}