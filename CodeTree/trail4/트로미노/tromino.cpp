#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    vector <vector<int>> arr1 = { {1, 0}, {1, 1} };
    vector <vector<int>> arr2 = { {1, 1}, {1, 0} };
    vector <vector<int>> arr3 = { {1, 1}, {0, 1} };
    vector <vector<int>> arr4 = { {0, 1}, {1, 1} };

    // 입력값
    int N, M;
    cin >> N >> M;
    vector <vector<int>> arr(N, vector <int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 확인하기 (ㄴ자 블록)
    int sum1, sum2, sum3, sum4;
    int max = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < M - 1; j++)
        {
            sum1 = 0;
            sum2 = 0;
            sum3 = 0;
            sum4 = 0;
            for (int row = 0; row < 2; row++)
            {
                for (int col = 0; col < 2; col++)
                {
                    sum1 += arr[i + row][j + col] * arr1[row][col];
                    sum2 += arr[i + row][j + col] * arr2[row][col];
                    sum3 += arr[i + row][j + col] * arr3[row][col];
                    sum4 += arr[i + row][j + col] * arr4[row][col];
                }
            }

            //cout << i << "행 " << j << "열에서의 sum1 : " << sum1 << "\n";
            //cout << i << "행 " << j << "열에서의 sum2 : " << sum2 << "\n";
            //cout << i << "행 " << j << "열에서의 sum3 : " << sum3 << "\n";
            //cout << i << "행 " << j << "열에서의 sum4 : " << sum4 << "\n";
            max = (sum1 > max) ? sum1 : max;
            max = (sum2 > max) ? sum2 : max;
            max = (sum3 > max) ? sum3 : max;
            max = (sum4 > max) ? sum4 : max;
        }
    }

    // 확인하기 (직사각형 블록)
    // 가로 3칸 직사각형
    int sum;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
            if (sum > max)
            {
                max = sum;
            }
        }
    }

    // 세로 3칸 직사각형
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
            if (sum > max)
            {
                max = sum;
            }
        }
    }

    cout << max;
    return 0;
}