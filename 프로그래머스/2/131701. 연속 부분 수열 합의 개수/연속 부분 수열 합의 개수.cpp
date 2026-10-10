#include <string>
#include <vector>


#include <algorithm>    // sort 함수 사용 목적
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    // 합의 최댓값 구해놓기 -> 이걸 이용해서, vector를 만들고, 그 vector를 이용해서 각 합의 숫자가 나왔는지 확인할 것임
    int maxSum = 0; 
    for(int i=0; i<elements.size(); i++)
    {
        maxSum += elements[i];
    }
    
    vector <bool> sums(maxSum + 1, false);   // 일단 첫 시작은 모두 false로. 해당 숫자가 합으로 구해지면 true로 바꾸기
    
    int sum;
    int num;
    for(int len = 1; len <= elements.size(); len++)
    {
        for(int i = 0; i<elements.size(); i++)  // i: 시작점
        {
            sum = 0;
            num = 0;
            for(int diff = 1; diff<= elements.size(); diff++)
            {
                for(int j=i; num < len; j+= diff)
                {
                    if(j >= elements.size())
                    {
                        j = j % elements.size();
                    }
                    sum += elements[j];
                    num ++; // 합에 사용한 개수 ++
                }                
                
                if(sums[sum] == false)
                {
                    sums[sum] = true;
                    answer++;
                }
            }
        }
    }
    
    
    return answer;
}