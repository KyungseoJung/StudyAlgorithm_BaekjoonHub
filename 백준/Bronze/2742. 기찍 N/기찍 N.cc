#include <iostream>

using namespace std;
int main()
{
    int N;
    cin >> N;
    for(int i=N; i>0; i--)
    {
        cout << i;
        if (i > 1)
        {
            cout <<"\n";
        }
    }
    
    return 0;
}