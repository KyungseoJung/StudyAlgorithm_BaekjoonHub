#include <iostream>
#include <vector>   // 추가
using namespace std;

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;
    
    vector <vector <int>> vec(N, vector <int> (N));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> vec[i][j];
        }
    }

    // 연속되는 숫자 세보기
    int sum = 0;

    // 행에서 --------------
    int rememberNum = -1;
    int count;
    for(int row = 0; row<N; row++)
    {
        count = 1;
        rememberNum = -1;
        for(int col = 0; col < N; col++)
        {
            if(vec[row][col] == rememberNum)
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if(count == M)
            {
                sum++;
                // cout << row << "행, " << col << "열에서 일치숫자 M개 발견\n";
                break;  // 이 행은 더이상 안 봐도 됨. 다음 행으로 넘어가기.
            }
            else
            {
                rememberNum = vec[row][col];
            }
        }
    }

    // 열에서 ------------
    rememberNum = -1;
    for(int col = 0; col<N; col++)
    {
        count = 1;
        rememberNum = -1;
        for(int row = 0; row < N; row++)
        {
            if(vec[row][col] == rememberNum)
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if(count == M)
            {
                sum++;
                // cout << row << "행, " << col << "열에서 일치숫자 M개 발견\n";
                break;  // 이 행은 더이상 안 봐도 됨. 다음 행으로 넘어가기.
            }
            else
            {
                rememberNum = vec[row][col];
            }
        }
    }

    cout << sum;
    return 0;
}