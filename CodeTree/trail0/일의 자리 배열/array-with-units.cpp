#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int num = 10;
    int arr[10];
    cin >> arr[0] >> arr[1];
    for(int i=2; i < num; i++)
    {
        arr[i] = (arr[i-2] + arr[i-1])% 10 ;
    }

    // 출력
    for(int i=0; i<num; i++)
    {
        cout << arr[i] << " " ;
    }


    return 0;
}