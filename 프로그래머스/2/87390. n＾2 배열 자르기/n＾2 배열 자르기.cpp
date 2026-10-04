#include <string>
#include <vector>

#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    // 일단 left와 right 만으로 -> 몇 행 몇 열(row1, col1)부터 몇 행 몇 열(row2, col2)까지 뽑아낼 것인지 파악하기
    long long row1;
    long long col1;
    long long row2;
    long long col2;
    
    // 헷갈리니까 left와 right을 1번부터 시작하는 것으로 +1해주기
    left += 1;
    right += 1;
    if(left % n == 0)
    {
        row1 = (left / n) -1 ;
        col1 = n-1; // 맨 오른쪽 열
    }
    else
    {
        row1 = (left / n);
        col1 = (left % n) - 1;
    }
    
    if(right % n == 0)
    {
        row2 = (right / n) -1;
        col2 = n-1;
    }
    else
    {
        row2 = (right / n);
        col2 = (right % n) - 1;
    }
    
    // 체크
    cout << "시작 행: " << row1 << "/ 열: " << col1 << "\n";
    cout << "끝나는 행: " << row2 << "/ 열: " << col2 << "\n";
    
    
    // 행과 열 중에 더 큰 숫자가 -> 거기 적혀있는 숫자 i를 의미함
    // 즉, 몇 행 몇 열인지만 알면 무슨 숫자가 적혀있는지 알 수 있음.
    long long max;
    for(int i = row1; i<=row2; i++)
    {
        if(row1 == row2)    // 만약 한 행에서만 가져와야 한다면
        {
            for(int j= col1; j<= col2; j++)
            {
                max = (i>j)? i : j;
                answer.push_back(max+1);    // 행열번호는 0부터 시작이므로, 추가할 때에는 +1해서 추가해주기
            }
        }
        else
        {
            if(i == row1)
            {
                for(int j=col1; j<n; j++)
                {
                    max = (i>j)? i : j;
                    answer.push_back(max+1);    // 행열번호는 0부터 시작이므로, 추가할 때에는 +1해서 추가해주기
                }
            }
            else if(i == row2)
            {
                for(int j=0; j<=col2; j++)
                {
                    max = (i>j)? i : j;
                    answer.push_back(max+1);    // 행열번호는 0부터 시작이므로, 추가할 때에는 +1해서 추가해주기
                }
            }
            else    // row1도 row2도 아니라면, 모든 열의 값을 가져오면 됨
            {
                for(int j=0; j<n; j++)
                {
                    max = (i>j)? i : j;
                    answer.push_back(max+1);    // 행열번호는 0부터 시작이므로, 추가할 때에는 +1해서 추가해주기
                }
            }
        }
    }
    return answer;
}