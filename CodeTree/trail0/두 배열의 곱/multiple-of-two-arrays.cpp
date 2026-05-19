#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N = 3;
    // 입력
    int arr1[3][3];
    int arr2[3][3];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr2[i][j];
        }
    }

    // 계산 및 출력
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N ; j++)
        {
            cout << arr1[i][j] * arr2[i][j] << " " ;
        }
        cout << "\n";
    }
    return 0;
}