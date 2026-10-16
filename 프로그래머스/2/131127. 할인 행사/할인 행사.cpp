#include <string>
#include <vector>

// #include <iostream> // 확인용
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int wantTypeNum = want.size();  // 원하는 음식 종류 수
    int wantNum = 0;  // 원하는 음식 개수
    for(int i=0; i<number.size(); i++)
    {
        wantNum += number[i];
    }
    
    vector <string> checkMenu(wantNum);
    checkMenu = want;
    vector <int> checkMenuNum;
    
    // 구매할 수 있는 가장 늦은 날짜 = 총 할인 날짜 - 구매해야 하는 물건 개수 +1 = discount.size() - wantNum +1 (0일부터 시작이라는 전제)
    string discountMenu;
    for(int start = 0; start < discount.size() - wantNum + 1; start++)    // 시작 날짜 (0일부터 구매했을 때 ~ (구매할 수 있는 가장 늦은 날짜) 구매했을 때)  
    {
        checkMenuNum.assign(wantTypeNum, 0);    // 처음엔 모두 0개로 시작하기
        for(int i=start; i<start + wantNum; i++)    // 해당 날짜에 구매하기 시작한 경우, 원하는 물건을 몇 개 살 수 있는지 카운팅해보기
        {
            discountMenu = discount[i];
            for(int ele = 0; ele < wantTypeNum; ele++)
            {
                if(want[ele] == discountMenu)
                {
                    checkMenuNum[ele]++;
                    // cout << start << "시작 날짜에 : " << i << "번째 날에서" << want[ele] << " 발견 \n";
                }
            }
        }
        
        // checkMenuNum(실제로 구매한 개수)와 number(구매하고 싶어했던 개수) 비교하기
        bool same = true;
        for(int i=0; i<number.size(); i++)
        {
            if(checkMenuNum[i] != number[i])
            {
                same = false;
                break;  // for문 종료
            }
        }
        if(same == true)
        {
            answer++;
        }
    }
    
    return answer;
}