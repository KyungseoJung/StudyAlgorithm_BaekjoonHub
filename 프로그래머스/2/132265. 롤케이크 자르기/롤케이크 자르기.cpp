#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    // int answer = -1;
    int answer = 0;
    

    // **** 처음 시작: 철수는 0개, 동생은 topping.size()만큼 먹는다고 가정하고 시작
    vector <bool> haveTopping(topping.size()+1, false);     // 특정 종류 (index)의 토핑을 갖고 있는지/ 아닌지
        // 철수는 1개 토핑을 얻을 때마다, 이미 가지고 있는 토핑인지/아닌지만 구분하면 됨
        // 1부터 topping.size()까지 저장. 처음엔 모두 false
    
    vector <int> sumTopping(topping.size()+1, 0);   // 특정 종류(index)의 토핑을 몇 개 가지고 있는지
        // 동생은 갖고 있는 토핑을 모두 for문으로 순회하며, 최종 토핑이 몇가지수인지 더하면 됨
        // 처음엔 topping에 해당하는 전체를 저장하면 됨
    for(int i=0; i<topping.size(); i++)
    {
        sumTopping[topping[i]] ++;
    }
    
    // 시작 ----------------
    int toppingEle;
    
    int sum1 = 0;   // 철수가 먹을 토핑의 가짓수
    int sum2 = 0;   // 동생이 먹을 토핑의 가짓수
    for(int i=1; i<sumTopping.size(); i++)      // 동생의 가짓수 구하기
    {
        if(sumTopping[i] > 0)
        {
            sum2++;
        }
    }


    for(int t = 0; t < topping.size()-1; t++) 
    {
        // t번째 인덱스에 해당하는 토핑을 한 개씩 동생 -> 철수에게 주는 것
        toppingEle = topping[t];
        
        // 철수 업데이트
        if(haveTopping[toppingEle] == false)
        {
            haveTopping[toppingEle] = true;
            // 추가되었을 때에만 sum2 ++ 추가해주기
            sum1++;
        }
        
        // 동생 업데이트
        sumTopping[toppingEle]--;
        if(sumTopping[toppingEle] == 0) // 가진 토핑이 0개가 될 때에만 토핑 가짓수 -1 해주기
        {
            sum2--;
        }

        // 철수와 동생 비교
        if(sum1 == sum2)
        {
            answer++;
        }
    }
    
    return answer;
}