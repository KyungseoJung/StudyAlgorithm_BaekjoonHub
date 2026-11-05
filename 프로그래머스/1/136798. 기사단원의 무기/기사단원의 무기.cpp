#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    // 0) 1부터 number까지의 숫자에 대해, 약수가 각각 몇 개인지 확인하기 -> vector에 담기
    vector <int> countElements;
    
    for(int num = 1; num <= number; num++)
    {
        // 1) 특정 숫자 num의 약수의 개수 세는 방법
        int count = 0;  // 약수 개수
        for(int i=1; i*i <= num; i++)
        {
            // 만약 i * i == num으로 표현할 수 있는 i가 있다면, count + 1 해주기
            if(i * i == num)    // 약수로, 제곱근이 선택된 것이라면
            {
                count += 1;
            }
            else if(num % i == 0)   // 약수로, 제곱근 이외의 숫자가 선택된 것이라면
            {
                count += 2; // 2개씩 쌍으로 약수가 생길 테니까

            }
        }
        countElements.push_back(count);
    }
    
    // 2) limit을 넘는 값이 있다면 모두 power로 맞춰주기
    for(int i=0; i<countElements.size(); i++)
    {
        if(countElements[i] > limit)
        {
            countElements[i] = power;
        }
        cout << countElements[i] << " " ;
    }
    
    // 3) 모두 더해주기
    int sum = 0;
    for(int i=0; i<countElements.size(); i++)
    {
        sum += countElements[i];
    }
    
    answer = sum;
    
    return answer;
}