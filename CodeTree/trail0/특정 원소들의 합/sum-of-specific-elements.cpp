#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N = 4;
    int arr[4][4];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 더하기
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(j <= i)
            {
                sum += arr[i][j];
            }
        }
    }

    cout << sum;
    
    return 0;
}