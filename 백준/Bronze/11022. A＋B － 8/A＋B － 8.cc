  
#include <iostream>

using namespace std;
int main()
{
    int T;
    cin >> T;
    int a, b;
    
    for(int i=0; i<T; i++)
    {
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a << " + " << b << " = " << (a+b) << "\n";
    }
    return 0;
}