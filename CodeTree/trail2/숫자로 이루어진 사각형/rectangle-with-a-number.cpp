#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    int ele = 1;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(ele >= 10)
            {
                ele = 1;
            }
            cout << ele << " ";
            ele++;
        }
        cout << "\n";

    }
    return 0;
}