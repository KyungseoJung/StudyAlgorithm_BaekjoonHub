#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    // n개의 수여도, 아마 n개 수들의 최소공배수 x 최대공약수 = n개 수들의 곱셈 
    // ㄴ 아닌듯!!!
//     int min = 999;
//     for(int i=0; i<arr.size(); i++)
//     {
//         if(arr[i] < min)
//         {
//             min = arr[i];
//         }
//     }
    
//     // 가장 작은 숫자(min)을 기준으로, 그 이하의 숫자들을 살펴보면서 최대공약수 찾기
//     bool dividable;
//     int gcd;
//     for(int i=min; i>0; i--)
//     {
//         dividable = true;
//         for(int j=0; j<arr.size(); j++)
//         {
//             if(arr[j] % i != 0)
//             {
//                 dividable = false;
//             }
//         }
//         if(dividable == true)   // 만약 모든 숫자가 나누어졌다면, 그 수는 공약수
//         {
//             gcd = i;
            
//             break;  // for문 통과 (최대공약수를 구했으니 더이상 구할 필요 없음)
//         }
//     }
    
//     // 최대공약수 x 최소공배수 = 모든 수들의 곱셈
//     int mul = 1;    // 모든 수들의 곱셈
//     for(int i=0; i<arr.size(); i++)
//     {
//         mul = mul * arr[i];
//     }
    
//     int lcm;    // 최소공배수
//     lcm = mul / gcd;
//     answer = lcm;
    
    // 정석으로 풀어보면 max 값을 구한 뒤, 그 값에 1, 2씩 곱해가면서, 모든 arr 원소로 나누어지면 그 수가 최소공배수
    int max = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    int dividend;
    int ele = 1;
    bool dividable;
    while(true)
    {
        dividend = max * ele;
        dividable = true;
        for(int i=0; i<arr.size(); i++)
        {
            if(dividend % arr[i] != 0)
            {
                dividable = false;
                break;
            }
        }
        
        if(dividable == true)   // divisor이 모든 arr의 원소로 나누어졌다면, 그 수가 최소공배수
        {
            break;  // while문 통과
        }
        else
        {
            ele++;
        }
    }
    
    answer = dividend;
    return answer;
}