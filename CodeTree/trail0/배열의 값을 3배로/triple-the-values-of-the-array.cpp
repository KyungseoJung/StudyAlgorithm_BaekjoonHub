#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N = 3;
    int arr[3][3];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 출력하기
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << arr[i][j] * 3 << " " ;
        }
        cout << "\n";
    }
    return 0;
}
