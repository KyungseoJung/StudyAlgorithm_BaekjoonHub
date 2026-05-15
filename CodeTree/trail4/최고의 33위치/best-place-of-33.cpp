#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int sum = 0;
    int maxSum = 0;
    for(int i=0; i<=N-3; i++)
    {
        for(int j=0; j<=N-3; j++)
        {
            sum = 0;
            for(int row = i; row <i+3; row++)
            {
                for(int col = j; col < j+3; col++)
                {
                    if(grid[row][col] == 1)
                    {
                        sum += 1;
                    }
                }
            }
            if(sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }

    cout << maxSum;

    return 0;
}
