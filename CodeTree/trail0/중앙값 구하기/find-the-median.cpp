#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int A, B, C;
    int N = 3;
    int min = 100;
    int max = -100;

    vector <int> nums(N);
    for(int i=0; i<N; i++)
    {
        cin >> nums[i];
        if(nums[i] < min)
        {
            min = nums[i];
        }
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }

    for(int i=0; i<N; i++)
    {
        if((nums[i] != max) && (nums[i] != min))
        {
            cout << nums[i];    // 최솟값도, 최댓값도 아니면 중앙값!
        }
    }

    return 0;
}