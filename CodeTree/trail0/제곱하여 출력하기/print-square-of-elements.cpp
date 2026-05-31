#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    vector <int> nums(N);
    for(int i=0; i<N; i++)
    {
        cin >> nums[i];
    }

    // 출력
    for(int i=0; i<N; i++)
    {
        cout << nums[i] * nums[i] << " ";
    }
    return 0;
}