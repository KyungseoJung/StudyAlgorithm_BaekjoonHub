#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    // Please write your code here.
    // n과 m의 곱 = 최대공약수 x 최소공배수
    //최대공약수부터 구해보면
    int lcm, gcd;
    int min = (n>m)? m : n;
    int max = (n>m)? n : m;
    for(int i=min; i>0; i--)
    {
        if((min % i == 0) && (max % i == 0))
        {
            gcd = i;
            break;
        }
    }
    gcd = min * max / gcd;
    cout << gcd;
    return 0;
}