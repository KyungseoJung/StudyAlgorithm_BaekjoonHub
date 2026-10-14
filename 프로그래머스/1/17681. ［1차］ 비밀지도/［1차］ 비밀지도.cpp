#include <string>
#include <vector>

#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    // 1. arr1을 이용해서 지도1을 구하자 -------------------------------
    // 1) 각 숫자를 이진수로 표현하기 -> arr1String에 넣기
    vector <string> arr1String;
    int dividend1;       // 나누어지는 수
    int divisor1 = 2;    // 나누는 수
    int remainder1;         // 나머지
    char ch1;
    string str1;
    
    int len1;    // 모자라서 앞에 0을 붙여줘야 하는 개수
    for(int i=0; i<arr1.size(); i++)
    {
        dividend1 = arr1[i];
        str1 = "";
        // 이진수로 표현
        while(dividend1 > 0)
        {
            remainder1 = dividend1 % divisor1;
            dividend1 = dividend1 / divisor1;
            
            ch1 = (char)(remainder1 + '0');
            str1 = ch1 + str1;
        }
        
        // 앞에 0 붙이기
        if(str1.length() < n)
        {
            len1 = n - str1.length();
            for(int i=0; i<len1; i++)
            {
                str1 = '0' + str1;
            }
        }
        
        arr1String.push_back(str1);
        
        cout << "arr1의 표현: " << str1 << "\n";
    }
    
    // 2) 이진수로 표현한 것을 기반으로 지도1을 그리자 -> 안 그려도 됨. 그냥 나중에 최종 지도 만들 때 참고해도 되지만, 그냥 그려보자.
    vector <vector <char>> map1(n, vector <char> (n, ' '));  // (n, n)차원의 지도1 만들기  
    for(int i=0; i < arr1String.size(); i++)
    {
        for(int j=0; j < arr1String[i].length(); j++)
        {
            if(arr1String[i][j] == '1')
            {
                map1[i][j] = '#';
            }
            // else // 아니면 그냥 공백 유지하면 됨
            else
            {
                map1[i][j] = ' ';
            }
        }
    }
    
    
    // 2. arr2을 이용해서 지도2을 구하자 -------------------------------
    // 1) 각 숫자를 이진수로 표현하기 -> arr1String에 넣기
    vector <string> arr2String;
    int dividend2;       // 나누어지는 수
    int divisor2 = 2;    // 나누는 수
    int remainder2;         // 나머지
    char ch2;
    string str2;
    
    int len2;    // 모자라서 앞에 0을 붙여줘야 하는 개수
    for(int i=0; i<arr2.size(); i++)
    {
        dividend2 = arr2[i];
        str2 = "";
        // 이진수로 표현
        while(dividend2 > 0)
        {
            remainder2 = dividend2 % divisor2;
            dividend2 = dividend2 / divisor2;
            
            ch2 = (char)(remainder2 + '0');
            str2 = ch2 + str2;
        }
        
        // 앞에 0 붙이기
        if(str2.length() < n)
        {
            len2 = n - str2.length();
            for(int i=0; i<len2; i++)
            {
                str2 = '0' + str2;
            }
        }
        
        arr2String.push_back(str2);
        cout << "arr2의 표현: " << str2 << "\n";
    }
    
    // 2) 이진수로 표현한 것을 기반으로 지도1을 그리자 -> 안 그려도 됨. 그냥 나중에 최종 지도 만들 때 참고해도 되지만, 그냥 그려보자.
    vector <vector <char>> map2(n, vector <char> (n, ' '));  // n, n차원의 지도1 만들기   (첫 시작은 모두 공백으로 설정)
    for(int i=0; i < arr2String.size(); i++)
    {
        for(int j=0; j < arr2String[i].length(); j++)
        {
            if(arr2String[i][j] == '1')
            {
                map2[i][j] = '#';
            }
            // else // 아니면 그냥 공백 유지하면 됨
        }
    }
        
    // 3. 최종 지도 그리기 -----------------
    string mapString3; // 각 행에 해당하는 string을 저장하기
    for(int i=0; i<n; i++)
    {
        mapString3 = "";
        for(int j=0; j<n; j++)
        {
            if((map1[i][j] == '#') || (map2[i][j] == '#'))
            {
                mapString3 = mapString3 + '#';
            }
            else    // 어느것도 벽이 아니라면, 공백
            {
                mapString3 = mapString3 + ' ';
            }   
        }
        answer.push_back(mapString3);
    }
    
    return answer;
}