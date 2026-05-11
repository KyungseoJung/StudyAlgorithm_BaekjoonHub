#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    // Please write your code here.
    int min = (n>m)? m : n;
    int max = (n>m)? n : m;

    for(int i=min; i>0; i--)
    {
        if((min % i == 0 ) && (max % i == 0))
        {
            cout << i;
            break;
        }
    }
    return 0;
}