#include <iostream>

using namespace std;
int main()
{
    int N;
    cin >> N;
    
    long long int a,b;
    while(N--)
    {
        cin >>  a>> b;
        cout << (a+b) << "\n";
    }
    return 0;
}